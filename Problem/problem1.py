# Problem 1

"""
Input Format

    The first line contains a single integer,
    The next  lines denote the matrix's rows, with each line containing space-separated integers describing the columns.

Output Format

    Print the absolute difference between the two sums of the matrix's diagonals as a single integer.
"""

def solve_sum(out_arr):
    index_1 = 0
    index_2 = len(out_arr) - 1
    sum_1, sum_2 = 0, 0
    for size in range(len(out_arr)):
        in_arr = out_arr[size]
        for i in range(len(in_arr)):
            if i == index_1:
                sum_1 += in_arr[i]
            if i == index_2:
                sum_2 += in_arr[i]
        index_1 += 1
        index_2 -= 1

    result = abs(sum_1 - sum_2)
    return result


n = int(input().strip())  # n x n
a = []
for a_i in range(n):
    a_t = [int(a_temp) for a_temp in input().strip().split(' ')]
    a.append(a_t)

print(solve_sum(a))
