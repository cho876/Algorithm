# Problem 14

"""
    Q.Anna and Brian order n items at a restaurant, but Anna declines to eat any of the k^th item
    (where 0 <= k < n) due to an allergy. When the check comes, they decide to split the cost of
    all the items they shared; however, Brian may have forgotten that they didn't split the k^th item
    and accidentally charged Anna for it.

    You are given n, k, the cost of each of the n items, and the total amount of money that Brian
    charged Anna for her portion of the bill. If the bill is fairly split, print Bon Appetit; otherwise,
    print the amount of money that Brian must refund to Anna.

    Input
        The first line contains two space-separated integers denoting the respective values of n (the
        number of items ordered) and k (the 0-based index of the item that Anna did not eat).
        The second line contains n space-separated integers where each integer i denotes the cost,
        c[i], of item i (where 0 <= i < n).
        The third line contains an integer, b_charged, denoting the amount of money that Brian charged
        Anna for her share of the bill.

    Output
        If Brian did not overcharge Anna, print Bon Appetit on a new line; otherwise, print the
        difference (i.e., b_charged - b_actual) that Brian must refund to Anna (it is guaranteed that this will
        always be an integer).

    sample
        4 1
        3 10 2 9
        12

        -> 5
"""

def bonAppetit(n, k, b, ar):
    actual_price = 0
    for food in range(n):
        if food == k:  # Anna가 못먹는 음식일 경우
            continue
        else:
            actual_price += ar[food]

    if (actual_price / 2) < b:  # Anna가 Overcharge되는 경우
        return int(b - (actual_price / 2))
    else:
        return "Bon Appetit"


n, k = input().strip().split(' ')  # n = 음식 갯수, k = Anna가 못먹는 음식의 index
n, k = [int(n), int(k)]
ar = list(map(int, input().strip().split(' ')))  # 음식 index
b = int(input().strip())
result = bonAppetit(n, k, b, ar)
print(result)
