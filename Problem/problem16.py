# Problem 16

"""
    Q. Brie’s Drawing teacher asks her class to open their n-page book to page number p. Brie can
    either start turning pages from the front of the book (i.e., page number 1) or from the back of
    the book (i.e., page number n), and she always turns pages one-by-one (as opposed to
    skipping through multiple pages at once). When she opens the book, page 1 is always on the right side:

    Each page in the book has two sides, front and back, except for the last page which may only
    have a front side depending on the total number of pages of the book (see the Explanation
    sections below for additional diagrams).

    Given n and p, find and print the minimum number of pages Brie must turn in order to arrive
    at page P.

    Input
        The first line contains an integer, n, denoting the number of pages in the book.
        The second line contains an integer, p, denoting the page that Brie's teacher wants her to turn
        to.

    Output
        Print an integer denoting the minimum number of pages Brie must turn to get to page p.

    Sample
        6
        2
        -> 1
"""


def solve(n, p):
    total_count = n // 2  # 총 넘김 횟수
    count_from_first = p // 2  # 앞에서부터 넘길 시, 넘겨야할 횟수
    count_from_last = total_count - count_from_first  # 뒤에서부터 넘길 시, 넘겨야할 횟수
    if count_from_first > count_from_last:
        return count_from_last
    else:
        return count_from_first


n = int(input().strip())  # 책의 총 페이지 쪽 수
p = int(input().strip())  # 원하는 페이지 쪽
result = solve(n, p)
print(result)
