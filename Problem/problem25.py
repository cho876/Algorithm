# Problem 25

"""
    Q. Lily likes to play games with integers and their reversals. For some integer x, we define
     reversed(x) to be the reversal of all digits in x. For example, reversed(123) = 321,
     reversed(21) = 12, and reversed(120) = 21.

    Logan wants to go to the movies with Lily on some day x satisfying (i <= x <= j), but he knows
    she only goes to the movies on days she considers to be beautiful. Lily considers a day to be
    beautiful if the absolute value of the difference between x and reversed(x) is evenly divisible
    by k.

    Given i, j, and k, count and print the number of beautiful days when Logan and Lily can go to
    the movies.

    Input
        A single line of three space-separated integers describing the respective values of i, j, and k.

    Output
        Print the number of beautiful days in the inclusive range between i and j.

    Sample
        20 23 6
        -> 2
"""


def reversed_number(num):
    revered_num = ""
    for i in num:
        revered_num = i + revered_num
    return int(revered_num)


def count_divided(start, stop, denominator):
    count = 0
    for i in range(start, stop + 1):
        molecule = abs(i - reversed_number(str(i)))
        if molecule % denominator == 0:
            count += 1
    return count


start, stop, denominator = list(map(int, input().strip().split(" ")))
result = count_divided(start, stop, denominator)
print(result)
