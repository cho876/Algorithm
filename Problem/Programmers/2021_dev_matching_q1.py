def makeRank(num):
    rank = 6

    if num == 6:
        rank = 1
    elif num == 5:
        rank = 2
    elif num == 4:
        rank = 3
    elif num == 3:
        rank = 4
    elif num == 2:
        rank = 5

    return rank


def solution(lottos, win_nums):
    answer = []

    dic = dict()
    for win_num in win_nums:
        if win_num in dic:
            dic[win_num] += 1
        else:
            dic[win_num] = 1

    zeroCnt = 0
    hitCnt = 0

    for lotto in lottos:
        if lotto in dic:
            hitCnt += 1
        else:
            if lotto == 0:
                zeroCnt += 1

    answer.append(makeRank(hitCnt + zeroCnt))
    answer.append(makeRank(hitCnt))

    return answer