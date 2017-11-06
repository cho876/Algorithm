# Problem 19

"""
    Q. We define a magic square to be an (n x n) matrix of distinct positive integers from 1 to n^2
    where the sum of any row, column, or diagonal (of length n) is always equal to the same
    number (i.e., the magic constant).

    Consider a (3 x 3) matrix, s, of integers in the inclusive range [1,9]. We can convert any digit, a,
    to any other digit, b, in the range [1,9] at cost |a-b|.

    Given s, convert it into a magic square at minimal cost by changing zero or more of its digits.
    Then print this cost on a new line.

    Note: The resulting magic square must contain distinct integers in the inclusive range [1,9].

    Input
        There are 3 lines of input. Each line describes a row of the matrix in the form of 3 space-
        separated integers denoting the respective first, second, and third elements of that row.

    Output
        Print an integer denoting the minimum cost of turning matrix s into a magic square.

    Sample
        4 9 2
        3 5 7
        8 1 5
        -> 1
"""

def solv_minimum(arg):
    total = []

    for size in ex:
        sum = 0
        for ex_row, arg_row in zip(size, arg):
            for ex_value, arg_value in zip(ex_row, arg_row):
                tmpSum = abs(ex_value - arg_value)
                sum += tmpSum
        total.append(sum)

    return min(total)

ex = [
    [[8, 1, 6], [3, 5, 7], [4, 9, 2]],
    [[6, 1, 8], [7, 5, 3], [2, 9, 4]],
    [[4, 9, 2], [3, 5, 7], [8, 1, 6]],
    [[2, 9, 4], [7, 5, 3], [6, 1, 8]],
    [[4, 3, 8], [9, 5, 1], [2, 7, 6]],
    [[8, 3, 4], [1, 5, 9], [6, 7, 2]],
    [[2, 7, 6], [9, 5, 1], [4, 3, 8]],
    [[6, 7, 2], [1, 5, 9], [8, 3, 4]]
]

total = []
for size in range(3):
    local = list(map(int, input().strip().split(" ")))
    total.append(local)

result = solv_minimum(total)
print(result)
