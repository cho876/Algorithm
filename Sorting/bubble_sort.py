# Bubble Sort

def swap(arr, first, second):
    arr[first], arr[second] = arr[second], arr[first]


def bubble_sort(argv):
    isSorting = True
    for index in reversed(range(len(argv))):
        for i in range(index):
            if argv[i] > argv[i + 1]:  # 두번째 인자가 첫번째 인자보다 클 경우 Swapping
                swap(argv, i, i + 1)
                isSorting = False
        if (isSorting):
            break
    return argv


a = []
size = int(input('Input Size of List: '))  # Input List's size

index = 0
while (index < size):
    data = int(input('Input List''s data: '))  # Input List's value
    a.append(data)
    index += 1

# Before
index = 0
while (index < size):
    print(a[index], end=' ')
    index += 1

print()
# Sorting List
bubble_sort(a)

# After
index = 0
while (index < size):
    print(a[index], end=' ')
    index += 1
