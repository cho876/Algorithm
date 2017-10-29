# Insert Sort

def insert_sort(arg):
    for size in range(1, len(arg)):
        target = arg[size]
        i = size
        while i > 0 and arg[i - 1] > target:
            arg[i] = arg[i - 1]
            i -= 1
        arg[i] = target  # Swapping
    return arg


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
insert_sort(a)

# After
index = 0
while (index < size):
    print(a[index], end=' ')
    index += 1
