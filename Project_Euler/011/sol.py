def product(i, j, change_i, change_j):
    local_product = 1
    for n in range(0, 4):
        local_product *= grid[i][j]
        i += change_i
        j += change_j
    return local_product


grid = []
global_product = 0


for _ in range(20):
    grid.append(list(map(int, input().split())))


for i in range(20):
    for j in range(20):
        if i < 16 and product(i, j, 1, 0) > global_product:
            global_product = product(i, j, 1, 0)
        if j < 16 and product(i, j, 0, 1) > global_product:
            global_product = product(i, j, 0, 1)
        if i < 16 and j < 16 and product(i, j, 1, 1) > global_product:
            global_product = product(i, j, 1, 1)
        if i >= 3 and j < 16 and product(i, j, -1, 1) > global_product:
            global_product = product(i, j, -1, 1)

print(global_product)
