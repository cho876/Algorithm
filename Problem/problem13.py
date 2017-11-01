# Problem 13

"""
    Q. A flock of n birds is flying across the continent. Each bird has a type, and the different types are designated by the ID numbers 1, 2, 3, 4, and 5.
        Given an array of n integers where each integer describes the type of a bird in the flock, find
        and print the type number of the most common bird. If two or more types of birds are equally
        common, choose the type with the smallest ID number.

    Input
        The first line contains an integer denoting n (the number of birds).
        The second line contains n space-separated integers describing the respective type numbers of
        each bird in the flock.

    Output
        Print the type number of the most common bird; if two or more types of birds are equally
        common, choose the type with the smallest ID number.
"""


def migratoryBirds(ar):
    max_count = 0
    max_type = 0
    for i in range(6):
        type_count = ar.count(i)
        if max_count < type_count:
            max_count = type_count
            max_type = i
    return max_type


n = int(input().strip())
ar = list(map(int, input().strip().split(' ')))
result = migratoryBirds(ar)
print(result)
