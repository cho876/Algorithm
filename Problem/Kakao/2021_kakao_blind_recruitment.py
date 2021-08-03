def solution(new_id):
    answer = ''
    sCh = new_id.lower()

    for ch in sCh:
        if ch.isalnum() or ch in '-_.':
            answer += ch

    while '..' in answer:
        answer = answer.replace('..', '.')

    answer = answer[1:] if len(answer) > 1 and answer[0] == '.' else answer
    answer = answer[:-1] if answer[-1] == '.' else answer

    answer = 'a' if len(answer) == 0 else answer

    if len(answer) >= 16:
        answer = answer[:15]

    answer = answer[:-1] if answer[-1] == '.' else answer

    while len(answer) < 3:
        answer += answer[-1]

    return answer