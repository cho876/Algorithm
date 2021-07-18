import heapq

def solution(jobs):
    answer = 0
    heap = []
    start, now = -1, 0
    cnt = 0

    while cnt < len(jobs):

        for job in jobs:
            if start < job[0] <= now:
                heapq.heappush(heap, [job[1], job[0]])

        if heap:
            item = heapq.heappop(heap)
            start = now
            now += item[0]
            answer += (now - item[1])
            cnt += 1
        else:
            now += 1

    return answer // len(jobs)