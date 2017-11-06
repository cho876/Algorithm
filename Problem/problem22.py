# Problem 22

"""
    Q. When you select a contiguous block of text in a PDF viewer, the selection is highlighted with
    a blue rectangle. In a new kind of PDF viewer, the selection of each word is independent of the
    other words; this means that each rectangular selection area forms independently around each highlighted word.

    In this type of PDF viewer, the width of the rectangular selection area is equal to the number of
    letters in the word times the width of a letter, and the height is the maximum height of any letter in the word.

    Consider a word consisting of lowercase English alphabetic letters, where each letter is 1mm wide.
    Given the height of each letter in millimeters (mm), find the total area that will be
    highlighted by blue rectangle in mm^2 when the given word is selected in our new PDF viewer.

    Input
        The first line contains 26 space-separated integers describing the respective heights of each
        consecutive lowercase English letter (i.e., ha, hb, hc, ..., hy, hz).
        The second line contains a single word, consisting of lowercase English alphabetic letters.

    Output
        Print a single integer denoting the area of highlighted rectangle when the given word is
        selected. The unit of measurement for this is square millimeters (mm^2), but you must only
        print the integer.

    Sample
        1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
        abc
        -> 9
"""


def convert_to_numbers(word):  # Convert to numbers
    index = []
    for value in word:
        index.append(ord(value) - 97)  # int
    return index


def find_value(h, word):
    number_of_alphabets = len(word)  # Number of Alphabets
    indexes = list(convert_to_numbers(word))  # Index number of each alphabets
    words_value = []  # Numbers according to each index number
    for i in indexes:
        words_value.append(h[i])
    result = max(words_value) * number_of_alphabets
    return result


h = list(map(int, input().strip().split(' ')))  # Alphabet's font sizes
word = input().strip()  # word

result = find_value(h, word)
print(result)
