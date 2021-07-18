import math
from itertools import permutations


def isPrime(num):
    if num == 0 or num == 1:
        return False

    for idx in range(2, int(math.sqrt(num)) + 1):
        if num % idx == 0:
            return False
    return True


def solution(numbers):
    answer = 0
    res = []

    for idx in range(1, len(numbers) + 1):
        lst = list(permutations(numbers, idx))

        for data in lst:
            num = int("".join(data))

            if isPrime(num) and num not in res:
                res.append(num)

    return len(res)