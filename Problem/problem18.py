# Problem 18

"""
    Q. Two cats named A and B are standing at integral points on the x-axis. Cat A is standing at
    point x and cat B is standing at point y. Both cats run at the same speed, and they want to
    catch a mouse named C that's hiding at integral point z on the x-axis. Can you determine who
    will catch the mouse?

    You are given q queries in the form of x, y, and z. For each query, print the appropriate answer
    on a new line:

    - If cat A catches the mouse first, print Cat A.
    - If cat B catches the mouse first, print Cat B.
    - If both cats reach the mouse at the same time, print Mouse C as the two cats fight and mouse escapes.
      Input Format

    Input

        The first line contains a single integer, q, denoting the number of queries.
        Each of the q subsequent lines contains three space-separated integers describing the
        respective values of x (cat A's location),  y(cat B's location), and z (mouse C's location).

    Output

        On a new line for each query, print Cat A if cat A catches the mouse first, Cat B
        if cat B catches the mouse first, or Mouse C if the mouse escapes.
"""

def find_winner(catA, catB, mouseC):
    mouse_position = mouseC
    catA_position = abs(mouseC - catA)
    catB_position = abs(mouseC - catB)

    if catA_position > catB_position:
        return "Cat B"
    elif catA_position < catB_position:
        return "Cat A"
    else:
        return "Mouse C"


n = int(input().strip())
result = []

for size in range(n):
    x, y, z = input().strip().split(" ")
    x, y, z = [int(x), int(y), int(z)]
    result.append(find_winner(x, y, z))

for value in result:
    print(value)
