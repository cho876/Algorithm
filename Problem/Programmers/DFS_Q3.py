def isMatch(curWord, cmpWord):
    matchCnt = 0

    for idx in range(len(curWord)):
        if curWord[idx] == cmpWord[idx]:
            matchCnt += 1

    if matchCnt == len(curWord) - 1:
        return True
    else:
        return False


def solution(begin, target, words):
    answer = 0

    if target not in words:
        return 0

    curArr = [begin]
    isVisited = [0] * len(words)

    while curArr:
        curWord = curArr.pop()

        if curWord == target:
            break

        answer += 1

        for idx in range(len(words)):
            if not isVisited[idx] and isMatch(curWord, words[idx]):
                isVisited[idx] = True
                curArr.append(words[idx])

    return answer