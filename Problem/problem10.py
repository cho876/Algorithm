# Problem 10

"""
    Q. n번의 경기를 치룬다.
         각 경기마다 score를 기록하고 자신의 이전 경기들을 기준으로 점수가 높아질 경우, 낮아질 경우를 각각 체크한다.
         n 번의 경기를 통해 얻은 이전 score들을 바탕으로 점수가 상승된 횟수, 하향된 횟수를 구하여라.
         
    Input
        1. 경기 횟수
        2. 각 경기별 점수
        
    Output
        점수가 상승된 횟수, 점수가 하향된 횟수
"""


def getRecord(s):
    max = 0
    max_count = 0
    min = 0
    min_count = 0
    for s_index in range(1, len(s)):
        if s[max] < s[s_index]:
            max = s_index
            max_count += 1
        if s[min] > s[s_index]:
            min = s_index
            min_count += 1
    return max_count, min_count

n = int(input().strip())
s = list(map(int, input().strip().split(' ')))
result = getRecord(s)
print (" ".join(map(str, result)))
