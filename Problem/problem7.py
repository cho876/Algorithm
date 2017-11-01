# Problem 7

"""
    Q. 집(s=왼쪽 범위, t=오른쪽 범위)을 기준으로 왼쪽에 사과나무(a= 사과나무 위치), 오른쪽에 오렌지 나무(b= 오렌지나무 위치)가 존재한다.
        사과 나무에는 m개의 사과가 존재하고 오렌지 나무에는 n개의 오렌지가 존재한다.
        이 과일들이 나무에서 떨어진 지점은 나무를 기준으로 각각 a(= 각 사과들이 착지한 지점), b(= 각 오렌지들이 착지한 지점)이다.
        이 때, 떨어진 과일들이 집 범주 내에 떨어진 경우를 출력하라.
        
    Input
        1. 집의 범위 (s, t)
        2. 사과나무, 오렌지 나무 위치 (a, b)
        3. 사과 갯수, 오렌지 갯수 (m, n)
        4. 사과 나무 기준 사과가 떨어진 상대적 위치
        5. 오렌지 나무 기준 오렌지가 떨어진 상대적 위치
    
    Output
        1. 집의 범위 내에 떨어진 사과 갯수
        2. 집의 범위 내에 떨어진 오렌지 갯수
"""

def solve_func(house_start, house_end, apple_tree_position, orange_tree_position, apple, orange):
    apple_count = 0
    orange_count = 0
    for ap in apple:
        range = ap + apple_tree_position
        if range >= house_start and range <= house_end:  # If apple is within range
            apple_count += 1
    for oran in orange:
        range = oran + orange_tree_position
        if range <= house_end and range >= house_start:  # If orange is within range
            orange_count += 1
    return apple_count, orange_count


s, t = input().strip().split(' ')  # range of house (s= start point, t = end point)
s, t = [int(s), int(t)]

a, b = input().strip().split(' ')  # position of apple & orange trees (a= apple tree, b = orange tree)
a, b = [int(a), int(b)]

m, n = input().strip().split(' ')  # the number of apple & orange  (a = apple, b = orange)
m, n = [int(m), int(n)]

apple = [int(apple_temp) for apple_temp in input().strip().split(' ')]
orange = [int(orange_temp) for orange_temp in input().strip().split(' ')]

result = solve_func(s, t, a, b, apple, orange)
for value in result:
    print(value)
