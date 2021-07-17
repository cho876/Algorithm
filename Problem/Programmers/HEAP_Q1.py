import heapq


def solution(scoville, K):
    answer = 0

    heap = []

    for data in scoville:
        heapq.heappush(heap, data)

    while heap[0] < K: # data
        try:
            answer += 1
            heapq.heappush(heap, heapq.heappop(heap) + (heapq.heappop(heap) * 2))
        except:
            return -1

    return answer