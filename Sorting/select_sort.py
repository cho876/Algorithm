# Select Sorting

def swap(arr, before_max_index, change_index):
    arr[before_max_index], arr[change_index] = arr[change_index], arr[before_max_index]


def select_sort(argv):  # Select Sorting
    for size in reversed(range(len(argv))):
        max_index = 0  # base index
        for index in range(1, size + 1):
            if (argv[max_index] < argv[index]):  # If more bigger than base index(max_index) exist...
                max_index = index
            swap(argv, max_index, size)  # Swapping
    return argv


a = []
size = int(input('Input Size of List: '))  # Input List's size

index = 0
while (index < size):
    data = int(input('Input List''s data: '))  # Input List's value
    a.append(data)
    index += 1

# Before
index = 0
while (index < size):
    print(a[index], end=' ')
    index += 1

print()
# Sorting List
select_sort(a)

# After
index = 0
while (index < size):
    print(a[index], end=' ')
    index += 1
