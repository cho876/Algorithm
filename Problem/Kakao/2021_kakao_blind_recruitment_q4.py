INF = int(1e9)
node = [[]]

import heapq


def makeNodes(fares):
    global node

    for src, dst, cost in fares:
        node[src].append([dst, cost])
        node[dst].append([src, cost])


def dijkstra(src, dst):
    global node
    localCost = [INF] * (len(node))
    localCost[src] = 0

    route = [[0, src]]

    while route:
        curCost, curRoute = heapq.heappop(route)

        if curCost > localCost[curRoute]:
            continue

        for nextRoute, nextCost in node[curRoute]:
            nextCost += curCost

            if nextCost < localCost[nextRoute]:
                localCost[nextRoute] = nextCost
                heapq.heappush(route, [nextCost, nextRoute])

    return localCost[dst]


def solution(n, s, a, b, fares):
    global node
    answer = 0
    node = [[] for _ in range(n + 1)]

    makeNodes(fares)

    answer = dijkstra(s, a) + dijkstra(s, b)

    for i in range(1, n + 1):
        if i != s:
            answer = min(answer, dijkstra(s, i) + dijkstra(i, a) + dijkstra(i, b))
    return answer