# Merge Sort

def merge_sort(arg):
    if len(arg) > 1:
        mid = len(arg) // 2
        lx = arg[:mid]
        rx = arg[mid:]

        merge_sort(lx)  # Divide Left side
        merge_sort(rx)  # Divide Right side

        li, ri, i = 0,0,0

        while li < len(lx) and ri < len(rx):
            if lx[li] > rx[ri]:  # Compare them
                arg[i] = rx[ri]
                ri += 1
            else:
                arg[i] = lx[li]
                li += 1
            i += 1

        arg[i:] = lx[li:] if li != len(lx) else rx[ri:]  # If left value has exist...


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
merge_sort(a)

# After
index = 0
while (index < size):
    print(a[index], end=' ')
    index += 1
