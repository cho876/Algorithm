# Problem 17

"""
    Q. Monica wants to buy exactly one keyboard and one USB drive from her favorite electronics store.
        The store sells n different brands of keyboards and m different brands of USB drives.
        Monica has exactly s dollars to spend, and she wants to spend as much of it as possible (i.e.,
        the total cost of her purchase must be maximal).

        Given the price lists for the store's keyboards and USB drives, find and print the amount money
        Monica will spend. If she doesn't have enough money to buy one keyboard and one USB drive, print -1 instead.

    Input
        The first line contains three space-separated integers describing the respective values of s (the
        amount of money Monica has), n (the number of keyboard brands) and m (the number of USB drive brands).
        The second line contains n space-separated integers denoting the prices of each keyboard brand.
        The third line contains m space-separated integers denoting the prices of each USB drive brand.

    Output
        Print a single integer denoting the amount of money Monica will spend. If she doesn't have enough
        money to buy one keyboard and one USB drive, print -1 instead.

    Sample
        10 2 3
        3 1
        5 2 8
        -> 9
"""


def getMoneySpent(keyboards, drives, s):
    prices = []
    for keyboard in keyboards:
        for drive in drives:
            total_price = keyboard + drive
            if total_price <= s:
                prices.append(total_price)
    if not prices:
        return -1
    else:
        max_price = max(prices)
        return max_price


s, n, m = input().strip().split(' ')
s, n, m = [int(s), int(n), int(m)]
keyboards = list(map(int, input().strip().split(' ')))
drives = list(map(int, input().strip().split(' ')))
moneySpent = getMoneySpent(keyboards, drives, s)
print(moneySpent)
