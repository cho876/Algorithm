# Problem 6

"""
    Q. n개의 성적 입력 후, 입력된 성적 중, 5의 배수와의 차가 3 미만일 경우 5의 배수로 상승시키며
        이외의 경우에는 그대로 둔다. 단, 38미만인 점수에 대해서는 그대로 둔다.

    Input
        First line: the number of score
        Second line: score

    Output
        rounded grade

"""

def solve(grades):
    result = []
    for value in grades:
        if value < 38:   # If, score < 38 ...
            result.append(value)
        else:            # score >= 38 ...
            last = value % 5  # Remainder
            if last < 3:
                result.append(value)
            elif last >= 3:
                round_value = value + (5 - last) # Make a multiple of 5
                result.append(round_value)
    return result


n = int(input().strip())  # Maximum count
grades = []
grades_i = 0
for grades_i in range(n):  # input Grade
    grades_t = int(input().strip())
    grades.append(grades_t)
result = solve(grades)
print("\n".join(map(str, result)))


