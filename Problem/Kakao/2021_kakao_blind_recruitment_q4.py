graph = [[]]
INF = int(1e9)


def makeNode(n, fares):
    global graph

    graph = [[] for _ in range(n + 1)]

    for src, dst, cost in fares:
        graph[src].append([dst, cost])
        graph[dst].append([src, cost])


def bfs(src, dst):
    global graph
    costArr = [INF] * len(graph)

    costArr[src] = 0
    route = [[src, 0]]

    while route:
        curRoute, curCost = route.pop()

        if curCost > costArr[curRoute]:
            continue

        for nextRoute, nextCost in graph[curRoute]:
            nextCost += curCost

            if nextCost < costArr[nextRoute]:
                costArr[nextRoute] = nextCost
                route.append([nextRoute, nextCost])
    return costArr[dst]


def solution(n, s, a, b, fares):
    global graph

    answer = 0
    makeNode(n, fares)

    answer = bfs(s, a) + bfs(s, b)

    for i in range(1, n + 1):
        if i != s:
            answer = min(answer, bfs(s, i) + bfs(i, a) + bfs(i, b))

    return answer