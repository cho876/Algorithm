def solution(answers):
    answer = [0] * 3
    person1 = [1, 2, 3, 4, 5]
    person2 = [2, 1, 2, 3, 2, 4, 2, 5]
    person3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

    res = []

    for idx in range(len(answers)):
        if person1[idx % len(person1)] == answers[idx]:
            answer[0] += 1
        if person2[idx % len(person2)] == answers[idx]:
            answer[1] += 1
        if person3[idx % len(person3)] == answers[idx]:
            answer[2] += 1

    for idx in range(len(answer)):
        if max(answer) == answer[idx]:
            res.append(idx + 1)

    return res