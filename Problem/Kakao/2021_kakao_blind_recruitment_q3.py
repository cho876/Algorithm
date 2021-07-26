from bisect import bisect_left
from itertools import combinations


def funcSplit(info):
    cases = []

    for i in range(5):
        for combi in combinations([0, 1, 2, 3], i):
            case = ''
            for j in range(4):
                if j in combi:
                    case += info[j]
                else:
                    case += '-'
            cases.append(case)

    return cases


def solution(info, query):
    answer = []
    all_people = {}

    for infoData in info:
        splitInfo = infoData.split()
        datas = funcSplit(splitInfo)

        for data in datas:
            if data in all_people.keys():
                all_people[data].append(int(splitInfo[4]))
            else:
                all_people[data] = [int(splitInfo[4])]

    for key in all_people:
        all_people[key].sort()

    for q in query:
        splitQuery = q.split()
        target = splitQuery[0] + splitQuery[2] + splitQuery[4] + splitQuery[6]

        if target in all_people.keys():
            answer.append(len(all_people[target]) - bisect_left(all_people[target], int(splitQuery[7]), lo=0,
                                                                hi=len(all_people[target])))
        else:
            answer.append(0)
    return answer