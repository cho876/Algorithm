# Problem 8

"""
    Q. 캥거루가 두마리가 있다. 첫 번째 캥거루는 x1지점부터 v1 rate로 뛰기 시작했고
        두 번째 캥거루는 x2지점부터 v2 rate로 뛰기 시작했다.
        이들이 동시간에 같은 위치에서 만날 지점이 있는지 구하라

    Input
        x1(=첫 번째 캥거루 시작 위치), v1(=첫 번째 캥거루의 점프 거리), x2(=두 번째 캥거루 시작 위치), v1(=두 번째 캥거루의 점프 거리)

    Output
        Yes or No
"""


def kangaroo(x1, v1, x2, v2):
    if x1 > x2 and v1 > v2:
        return "NO"
    elif x2 > x1 and v2 > v1:
        return "NO"
    elif x2 != x1 and v1 == v2:
        return "NO"
    elif (x2 - x1) % (v1 - v2) == 0:
        return "YES"
    else:
        return "NO"


x1, v1, x2, v2 = input().strip().split(' ')
x1, v1, x2, v2 = [int(x1), int(v1), int(x2), int(v2)]
result = kangaroo(x1, v1, x2, v2)
print(result)
