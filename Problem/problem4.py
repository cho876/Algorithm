# Problem 4

"""
 Q. Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four
    of the five integers. Then print the respective minimum and maximum values as a single line of two space-separated long integers.

    Input Format

        A single line of five space-separated integers.

    Output Format

    Print two space-separated long integers denoting the respective minimum and maximum values that can be calculated by
    summing exactly four of the five integers. (The output can be greater than 32 bit integer.)
"""


def sum_array(arr):
    result_array = []

    for size in range(len(arr)):
        sum_result = 0
        for i in range(len(arr)):
            if size == i:  # Same index pass
                continue
            else:
                sum_result += arr[i]
        result_array.append(sum_result)
    return result_array


def find_result(arr):  # Find max & min index , return arr[min], arr[max]
    max = 0
    min = 0
    for size in range(1, len(arr)):
        if arr[max] < arr[size]:
            max = size
        if arr[min] > arr[size]:
            min = size
    return arr[min], arr[max]


arr = list(map(int, input().strip().split(' ')))
tmp_arr = sum_array(arr)
result_arr = find_result(tmp_arr)
for value in result_arr:
    print(value, end=" ")
