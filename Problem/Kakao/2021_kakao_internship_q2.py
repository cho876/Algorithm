from collections import deque

mov = ([1, 0], [0, 1], [-1, 0], [0, -1])


def makeMap(place):
    manLoc = []
    maps = []

    for rowIdx, data in enumerate(place):
        for colIdx, ch in enumerate(data):
            if ch == 'P':
                manLoc.append([rowIdx, colIdx])
        maps.append(data)
    return manLoc, maps


def isin(row, col):
    if -1 < row < 5 and -1 < col < 5:
        return True
    else:
        return False


def bfs(maps, row, col):
    que = deque()
    que.append([row, col])

    table = [[-1 for _ in range(5)] for _ in range(5)]
    table[row][col] = 0

    while que:
        curRow, curCol = que.popleft()

        for dRow, dCol in mov:
            movRow = curRow + dRow
            movCol = curCol + dCol

            if not isin(movRow, movCol):
                continue

            if table[movRow][movCol] == -1 and maps[movRow][movCol] != 'X':
                table[movRow][movCol] = table[curRow][curCol] + 1
                que.append([movRow, movCol])

    return table


def solution(places):
    answer = []

    for place in places:
        manLoc, maps = makeMap(place)
        isOk = True

        for curMan in manLoc:
            arr = bfs(maps, curMan[0], curMan[1])

            for man in manLoc:
                if curMan != man:
                    manRow = man[0]
                    manCol = man[1]

                    if -1 < arr[manRow][manCol] <= 2:
                        isOk = False
                        break

            if not isOk:
                break

        if isOk:
            answer.append(1)
        else:
            answer.append(0)

    return answer