# Problem 11

"""
    Q. Lily는 초콜릿 가게를 한다. 며칠 후, Lily Ron의 생일을 기념해 초콜릿을 선물하고자 한다.
        Lily는 초콜릿에 새겨진 숫자를 바탕으로 의미있는 초콜릿을 제공하고자 한다.
        월(=m)개의 초콜릿을 선물하되 각 초콜릿의 숫자를 더한 값이 일(=d)이 되도록 만들고자 한다.
        이 때, 연속적으로 연결되어 있는 초콜릿을 기준으로 원하는 초콜릿을 얻어낼 수 있는 경우의 수는 몇 가지인지 구하라

    Input
        1. 초콜릿의 갯수
        2. 각 초콜릿 별, 숫자 문양 (연속되어 붙어있음)
        3. 생일 날짜 - d = '월', m = '일'

    Output
        연속되어 있는 숫자를 바탕으로 조건을 만족시키도록 만들 수 있는 초콜릿 갯수

    ex)
        5
        1 2 1 3 2
        3 2
        -> 2 (1+2, 2+1)

        1
        4
        4 1
        -> 1 (4)
"""


def solve(n, s, d, m):
    count = 0  # total count
    limit = n - m  # last index
    for i in range(limit + 1):  # 0 ~ last index
        sum = 0
        index = i
        for j in range(m):
            sum += s[index]  # sum of s[index]
            index += 1
        if sum == d:  # If sum == d
            count += 1
    return count


n = int(input().strip())  # the number of chocolate
s = list(map(int, input().strip().split(' ')))  # chocolate index
d, m = input().strip().split(' ')  # d= date, m= month
d, m = [int(d), int(m)]
result = solve(n, s, d, m)
print(result)
