# Problem 24

"""
    Q. A Discrete Mathematics professor has a class of N students. Frustrated with their lack of
    discipline, he decides to cancel class if fewer than K students are present when class starts.

    Given the arrival time of each student, determine if the class is canceled.

    Input
        The first line of input contains , the number of test cases.

        Each test case consists of two lines. The first line has two space-separated integers, N
        (students in the class) and K (the cancelation threshold). The second line contains N space-
        separated integers (a1,a2,...,aN) describing the arrival times for each student.

        Note: Non-positive arrival times (ai<=0) indicate the student arrived early or on time; positive
        arrival times (ai>0) indicate the student arrived ai minutes late.

    Output
        For each test case, print the word YES if the class is canceled or NO if it is not.

    Sample
        2
        4 3
        -1 -3 4 2
        4 2
        0 -1 2 1
        -> YES
           NO
"""


def check_students(limit_students, reach_time):
    student_attended = 0
    for i in reach_time:
        if i == 0 or i < 0:
            student_attended += 1
    if limit_students <= student_attended:
        return "NO"
    else:
        return "YES"


t = int(input().strip())
result = []
for a0 in range(t):
    n, k = input().strip().split(' ')
    n, k = [int(n), int(k)]
    a = [int(a_temp) for a_temp in input().strip().split(' ')]
    result.append(check_students(k, a))

for i in result:
    print(i)
