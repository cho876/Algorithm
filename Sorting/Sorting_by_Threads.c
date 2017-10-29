#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *array;
	int start;
	int end;
	int tid;
} thread_info;

int limit_threads;     // Maximum number of threads
int shared_index;      // Thread's id (=Shared data)
pthread_mutex_t mutex;   // MUTEX

void swap(int*, int*);  // Swap Function
void bubble_sort(int*, int);  // Bubble Sorting
void merge_sort(int*, int, int);  // Merge Sorting
void *split_thread(void*);    // Split thread's array & Rejoin them
void split_main(int*, int, int);  // Split main()'s array & Rejoin this

int main(void) {
	int limit_numbers;    // Maximum number of input digits
	int input_value;      //

	scanf("%d", &limit_threads);   // Input Maximum number of threads
	scanf("%d", &limit_numbers);   // Input Maximum number of input digits
	int* result_array = (int*) malloc(sizeof(int) * limit_numbers); // Create an array with the maximum number of entries

	// Store numbers inside array
	for (int i = 0; i < limit_numbers; i++) {
		scanf("%d", &input_value);
		result_array[i] = input_value;
	}

	split_main(result_array, 0, limit_numbers - 1);   // Merging Sort Calls

	int i = 0;
	for (i = 0; i < limit_numbers; ++i) {
		printf("%d\n", result_array[i]);
	}
	free(result_array);
	pthread_mutex_destroy(&mutex);
	return 0;
}

/**
 function: Swap Function

 param1: swapping value_1
 param2: swapping value_2
 */
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 function: Bubble Sorting (Ascending)

 param1: Array to sort
 param2: Array's size
 */
void bubble_sort(int* arr, int size) {
	for (int i = size; 1 < i; i--) {
		for (int j = 1; j < i; j++) {
			if (arr[j - 1] > arr[j])
				swap(&arr[j - 1], &arr[j]);
		}
	}
}

/**
 function: Merge Sorting (Ascending)

 param1: Array to sort
 param2: Start index
 param3: End index
 */
void merge_sort(int *data, int start, int end) {

	int *tmpArray = (int *) malloc((end - start + 1) * sizeof(int));
	int ctr = 0;
	int i = start;
	int mid = start + ((end - start) / 2);
	int j = mid + 1;

	while (i <= mid && j <= end) {
		if (data[i] <= data[j]) {
			tmpArray[ctr++] = data[i++];
		} else {
			tmpArray[ctr++] = data[j++];
		}
	}
	if (i == mid + 1) {
		while (j <= end) {
			tmpArray[ctr++] = data[j++];
		}
	} else {
		while (i <= mid) {
			tmpArray[ctr++] = data[i++];
		}
	}
	i = start;
	ctr = 0;
	while (i <= end) {
		data[i++] = tmpArray[ctr++];
	}
	free(tmpArray);
	return;
}

/**
 Function: main()'s array를 분할하기 위한 pthread_create 및 pthread_join Call

 param1: Main()'s array
 param2: Start index
 param3: End index

 ※ shared_index: 각 thread 별 tid 지정 변수 (= Shared data)
 */
void split_main(int *array, int start, int end) {

	pthread_mutex_init(&mutex, NULL);  // Initialize Mutex
	shared_index = 0;                  // Initialize Shared Data

	// Input thread's info
	thread_info info;
	info.array = array;
	info.start = start;
	info.end = end;
	info.tid = 0;

	// Create & Join thread
	pthread_t thread;
	pthread_create(&thread, NULL, split_thread, &info);
	pthread_join(thread, NULL);
	return;
}

/**
 Function: Divide Thread & Sorting Thread's array & Rejoin them

 param: Array
 */
void *split_thread(void *arg) {

	// Input thread's info through param
	thread_info *info = (thread_info *) arg;
	int start = info->start;
	int end = info->end;
	int tid = info->tid;

	// 최대 thread 갯수보다 thread가 같거나 많아질 경우
	if (shared_index >= limit_threads)
		bubble_sort(info->array + start, end - start + 1);

	else {
		int center = start + ((end - start) / 2);   // Find center of Array

		// Split into two thread
		thread_info thread_info_0;
		thread_info thread_info_1;

		// Set First thread's info
		thread_info_0.start = start;
		thread_info_0.end = center;
		thread_info_0.array = info->array;

		// Set Second thread's info
		thread_info_1.start = center + 1;
		thread_info_1.end = end;
		thread_info_1.array = info->array;

		// Create First thread
		pthread_t thread_0;
		pthread_create(&thread_0, NULL, split_thread, &thread_info_0);

		// Create Second thread
		pthread_t thread_1;
		pthread_create(&thread_1, NULL, split_thread, &thread_info_1);

		// Set First thread's id
		pthread_mutex_lock(&mutex);
		thread_info_0.tid = shared_index++;
		pthread_mutex_unlock(&mutex);

		// Set Second thread's id
		pthread_mutex_lock(&mutex);
		thread_info_1.tid = shared_index++;
		pthread_mutex_unlock(&mutex);

		pthread_join(thread_0, NULL);
		pthread_join(thread_1, NULL);

		merge_sort(info->array, start, end);
	}
	pthread_exit(NULL);
}
