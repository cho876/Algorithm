def solution(numbers, hand):
    answer = ''
    last_L = 10
    last_R = 12

    for number in numbers:
        if number in [1, 4, 7]:
            answer += 'L'
            last_L = number
        elif number in [3, 6, 9]:
            answer += 'R'
            last_R = number
        else:
            number = 11 if number == 0 else number

            if sum(divmod(abs(last_L - number), 3)) < sum(divmod(abs(last_R - number), 3)):
                answer += 'L'
                last_L = number
            elif sum(divmod(abs(last_R - number), 3)) < sum(divmod(abs(last_L - number), 3)):
                answer += 'R'
                last_R = number
            else:
                if hand == 'right':
                    answer += 'R'
                    last_R = number
                else:
                    answer += 'L'
                    last_L = number

    return answer