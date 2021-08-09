INF = int(1e9)


def solution(s):
    answer = INF

    if len(s) == 1:  # 길이가 1일 때, return 1
        return 1

    for cutPoint in range(1, len(s) // 2 + 1):
        ans = ""
        count = 1
        tmpStr = s[:cutPoint]

        for idx in range(cutPoint, len(s), cutPoint):
            if tmpStr == s[idx:idx + cutPoint]:
                count += 1
            else:
                if count == 1:
                    count = ""
                ans += str(count) + tmpStr
                tmpStr = s[idx:idx + cutPoint]
                count = 1

        if count == 1:
            count = ""

        ans += str(count) + tmpStr
        answer = min(answer, len(ans))

    return answer