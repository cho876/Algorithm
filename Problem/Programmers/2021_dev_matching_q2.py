def makeMap(rows, columns):
    table = [[0 for _ in range(columns)] for _ in range(rows)]
    val = 1

    for row in range(rows):
        for col in range(columns):
            table[row][col] = val
            val += 1

    return table


def rotateMap(table, srcRow, srcCol, dstRow, dstCol):
    firstVal = table[srcRow - 1][srcCol - 1]
    minVal = firstVal

    for row in range(srcRow - 1, dstRow - 1):
        tmp = table[row + 1][srcCol - 1]
        table[row][srcCol - 1] = tmp
        minVal = min(minVal, tmp)

    for col in range(srcCol - 1, dstCol - 1):
        tmp = table[dstRow - 1][col + 1]
        table[dstRow - 1][col] = tmp
        minVal = min(minVal, tmp)

    for row in range(dstRow - 1, srcRow - 1, -1):
        tmp = table[row - 1][dstCol - 1]
        table[row][dstCol - 1] = tmp
        minVal = min(minVal, tmp)

    for col in range(dstCol - 1, srcCol - 1, -1):
        tmp = table[srcRow - 1][col - 1]
        table[srcRow - 1][col] = tmp
        minVal = min(minVal, tmp)

    table[srcRow - 1][srcCol] = firstVal
    return table, minVal


def solution(rows, columns, queries):
    answer = []
    table = makeMap(rows, columns)

    for query in queries:
        table, minVal = rotateMap(table, query[0], query[1], query[2], query[3])
        answer.append(minVal)

    return answer