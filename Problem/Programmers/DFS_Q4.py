def solution(tickets):
    answer = []
    dic = dict()
    tickets.sort(reverse=True)

    for src, dst in tickets:
        if src in dic:
            dic[src].append(dst)
        else:
            dic[src] = [dst]

    routes = ['ICN']

    while routes:
        route = routes[-1]

        if route not in dic or len(dic[route]) == 0:
            answer.append(routes.pop())
        else:
            routes.append(dic[route].pop())

    answer.reverse()
    return answer