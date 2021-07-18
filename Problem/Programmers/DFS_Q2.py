answer = 0

def DFS(idx, computers, isVisited):
    global answer

    if isVisited[idx]:
        return

    isVisited[idx] = True

    for i in range(len(computers[idx])):
        if not isVisited[i] and computers[idx][i] == 1:
            DFS(i, computers, isVisited)


def solution(n, computers):
    global answer
    isVisited = [0] * n

    for idx in range(n):
        if not isVisited[idx]:
            answer += 1
            DFS(idx, computers, isVisited)
    return answer