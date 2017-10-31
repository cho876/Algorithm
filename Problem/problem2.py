# Problem 2

"""
Input Format

    The first line contains an integer, , denoting the size of the array.
    The second line contains  space-separated integers describing an array of numbers

Output Format

    You must print the following  lines:

        1. A decimal representing of the fraction of positive numbers in the array compared to its size.
        2. A decimal representing of the fraction of negative numbers in the array compared to its size.
        3. A decimal representing of the fraction of zeroes in the array compared to its size.
"""

def solve_func(arr):
    positive_count, negative_count, zero_count = 0, 0, 0
    for size in range(len(arr)):
        if arr[size] > 0:
            positive_count += 1
        elif arr[size] == 0:
            zero_count += 1
        else:
            negative_count += 1

    return positive_count / len(arr), negative_count / len(arr), zero_count / len(arr)  # return tuple


n = int(input().strip())  # Input Maximum of values
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]  # set Array
result = solve_func(arr)

for value in result:
    print(value)