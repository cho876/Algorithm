# Problem 5

"""
Input Format

    The first line contains a single integer, n, denoting the number of candles on the cake.
    The second line contains n space-separated integers, where each integer i describes the height of candle i.

Output Format

    Print the number of tallest candles Colleen blows out on a new line.
"""


def birthdayCakeCandles(n, ar):
    max_value = 0
    count = 1
    for value in ar:
        iValue = int(value)
        if value > max_value:
            max_value = value
            count = 1
        elif value == max_value:
            count += 1
    return count

n = int(input().strip())
ar = list(map(int, input().strip().split(' ')))
result = birthdayCakeCandles(n, ar)
print(result)
