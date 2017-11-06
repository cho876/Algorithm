# Problem 20

"""
    Q. Given an array of integers, find and print the maximum number of integers you can select from
    the array such that the absolute difference between any two of the chosen integers is <=1.

    Input

        The first line contains a single integer, n, denoting the size of the array.
        The second line contains n space-separated integers describing the respective values of a0, a1, ... , an-1.

    Output

        A single integer denoting the maximum number of integers you can choose from the array
        such that the absolute difference between any two of the chosen integers is <=1.

    Sample
        6
        4 6 5 3 3 1
        -> 3
"""

def find_count(arg):
    max_count = max((arg.count(x) + arg.count(x + 1) for x in set(arg)))
    return max_count


n = int(input().strip())
a = [int(a_temp) for a_temp in input().strip().split(' ')]
result = find_count(a)
print(result)