# Problem 23

"""
    Q. The Utopian Tree goes through 2 cycles of growth every year. Each spring, it doubles in height.
    Each summer, its height increases by 1 meter.

    Laura plants a Utopian Tree sapling with a height of 1 meter at the onset of spring. How tall will
    her tree be after N growth cycles?

    Input
        The first line contains an integer, T, the number of test cases.
        T subsequent lines each contain an integer, N, denoting the number of cycles for that test case.

    Output
        For each test case, print the height of the Utopian Tree after N cycles. Each height must be
        printed on a new line.

    Sample
        3
        0
        1
        4
        -> 1
           2
           7
"""


def calc_cycles(cycles):
    result = []
    for i in cycles:
        if i == 0:
            result.append(1)
        elif i % 2 == 0:
            value = 2 ** ((i // 2) + 1) - 1
            result.append(value)
        else:
            value = 2 ** ((i + 3) // 2) - 2
            result.append(value)
    return result


t = int(input().strip())
cycles = []
for i in range(t):
    cycles.append(int(input().strip()))

result = calc_cycles(cycles)
for i in result:
    print(i)
