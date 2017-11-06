# Problem 21

"""
    Q. Dan is playing a video game in which his character competes in a hurdle race by jumping over
     n hurdles with heights h0, h1, ..., hn-1. He can initially jump a maximum height of k units,
     but he has an unlimited supply of magic beverages that help him jump higher! Each time Dan
     drinks a magic beverage, the maximum height he can jump during the race increases by 1 unit.

     Given n, k, and the heights of all the hurdles, find and print the minimum number of magic
     beverages Dan must drink to complete the race.

    Input
        The first line contains two space-separated integers describing the respective values of n (the
        number of hurdles) and k (the maximum height he can jump without consuming any beverages).
        The second line contains n space-separated integers describing the respective values of
        h0, h1, ..., hn-1.

    Output
        Print an integer denoting the minimum number of magic beverages Dan must drink to
        complete the hurdle race.

    Sample
        5 4
        1 6 3 5 2
        -> 2
"""


def solv_maximum(maximum_jump, height_of_hurdles):
    result = max(height_of_hurdles) - maximum_jump
    if result < 0:
        return 0
    else:
        return result


n, k = input().strip().split(' ')
n, k = [int(n), int(k)]
height = list(map(int, input().strip().split(' ')))
result = solv_maximum(k, height)
print(result)
