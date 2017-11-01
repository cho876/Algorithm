# Problem 12

"""
    Q. You are given an array of n integers, a0, a1, ..., an-1, and a positive integer, k.
    Find and print the number of (i,j) pairs where i<j and  ai + aj is divisible by k.

    Input
        The first line contains 2 space-separated integers, n and k, respectively.
        The second line contains n space-separated integers describing the respective values of a0, a1, ... , an-1.

    Output
        Print the number of (i,j) pairs where i>j and ai + aj is evenly divisible by k.
"""


import sys

def divisibleSumPairs(n, k, ar):
    count = 0
    for i in reversed(range(len(ar))):
        for j in range(i):
            result = (ar[i] + ar[j]) % k
            if result == 0:
                count += 1
    return count


n, k = input().strip().split(' ') # n = 총 갯수, k = 나눌 수
n, k = [int(n), int(k)]
ar = list(map(int, input().strip().split(' '))) # n개의 요소
result = divisibleSumPairs(n, k, ar)
print(result)
