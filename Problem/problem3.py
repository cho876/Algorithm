# Problem 3

"""
Q. Observe that its base and height are both equal to , and the image is drawn using # symbols and spaces. The last line is not preceded by any spaces.
    Write a program that prints a staircase of size .

Input Format

    A single integer, , denoting the size of the staircase.

Output Format

    Print a staircase of size  using # symbols and spaces.
"""


def solve_top(input):  # If input is 6
    for size in reversed(range(input)):  # 5 ~ 0  -> Count = 6
        for i in range(size):  # First : 0 ~ 4 -> Count = 5
            print(" ", end="")
        for j in range(input - size):  # First :
            print("#", end="")
        print()


n = int(input().strip())
solve_top(n)
