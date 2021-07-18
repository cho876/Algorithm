def solution(numbers):
    answer = ''

    lst = list(map(str, numbers))
    lst.sort(key=lambda x: x * 3, reverse=True) # 문자열 sort (lambda)

    return str(int("".join(lst)))   # 배열 내, 모든 문자 이어붙이기