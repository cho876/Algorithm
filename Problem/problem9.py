# Problem 9

"""
    Q. 두개의 리스트가 주어진다.
        첫 번째 리스트의 요소들은 n % 요소 == 0가 되어야하며
        두 번째 리스트의 요소들은 요소 % n == 0이 되어야 한다.
        이 때 n이 될 수 있는 갯수를 구하여라
        
    Input
        1. 두 배열의 크기
        2. 첫 번째 배열의 data
        3. 두 번째 배열의 data
    
    Output
        문제에 적합한 숫자 갯수
"""

from fractions import gcd
from functools import reduce


def LCM(a, b):
    return (a * b) // gcd(a, b)


def getTotalX(a, b):
    lcm_a = reduce(LCM, a)  # a's Least common multiple
    gcm_b = reduce(gcd, b)  # b's GCD
    count = 0
    for i in range(lcm_a, gcm_b + 1, lcm_a):
        if gcm_b % i == 0:
            count += 1
    return count


if __name__ == "__main__":
    n, m = input().strip().split(' ')
    n, m = [int(n), int(m)]
    a = list(map(int, input().strip().split(' ')))
    b = list(map(int, input().strip().split(' ')))
    total = getTotalX(a, b)
    print(total)
