answer = 0


def DFS(idx, numbers, target, curSum):
    global answer

    if idx == len(numbers) and target == curSum:
        answer += 1
        return
    if idx == len(numbers):
        return

    DFS(idx + 1, numbers, target, curSum + numbers[idx])
    DFS(idx + 1, numbers, target, curSum - numbers[idx])


def solution(numbers, target):
    global answer

    DFS(0, numbers, target, 0)
    return answer