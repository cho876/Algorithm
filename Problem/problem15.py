#Problem 15

"""
    Q. John works at a clothing store and he's going through a pile of socks to find the number of
    matching pairs. More specifically, he has a pile of n loose socks where each sock i is labeled
    with an integer, ci, denoting its color. He wants to sell as many socks as possible, but his
    customers will only buy them in matching pairs. Two socks, i and j, are a single matching pair
    if they have the same color (ci == cj).

    Given n and the color of each sock, how many pairs of socks can John sell?

    Input
        The first line contains an integer, n, denoting the number of socks.
        The second line contains n space-separated integers describing the respective values of
        c0, c1, c2, ... , cn-1.

    Output
        Print the total number of matching pairs of socks that John can sell.

    Sample
        9
        10 20 20 10 10 30 50 10 20
        -> 3
"""
def distinct_value(indexes):
    result = []
    for value in list:
        if value not in result:
            result.append(value)
    return result


def count_value(indexes, unique_index):
    pair_count = 0
    for i in unique_index:
        tmpCount = indexes.count(i)
        pair_count += tmpCount // 2
    return pair_count


n = int(input())  # 총 양말 갯수
indexes = list(map(int, input().split(" ")))  # 각 양말 별 index number

unique_index = distinct_value(indexes)  # index 종류 확인
count = count_value(indexes, unique_index)

print(count)
