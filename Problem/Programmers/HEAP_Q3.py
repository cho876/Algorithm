import heapq


def solution(operations):
    answer = []

    for oper in operations:
        item = oper.split(' ')

        if item[0] == 'I':
            heapq.heappush(answer, int(item[1]))
        elif item[0] == 'D':
            if answer:
                if item[1] == '1':  # 최댓값 삭제
                    answer = answer[:-1]
                elif item[1] == '-1':  # 최솟값 삭제
                    heapq.heappop(answer)

    if answer:
        answer = [max(answer), min(answer)]
    else:
        answer = [0, 0]

    return answer