# 2021 카카오 채용연계형 인턴십
# Q1. 숫자 문자열과 영단어

def solution(s):
    answer = 0
    start, end = 0, 0
    data = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    dic = dict()
    res = []

    for idx in range(len(data)):
        dic[data[idx]] = str(idx)

    for idx in range(len(s)):
        tmp = s[start:idx + 1]
        if tmp in dic:
            res.append(dic[tmp])
            start = idx + 1
        elif tmp.isdigit():
            res.append(str(tmp))
            start = idx + 1

    return int("".join(res))