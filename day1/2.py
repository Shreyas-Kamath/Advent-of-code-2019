def calc_fuel(init: int) -> int:
    sum = 0
    while (init > 0):
        init = init // 3 - 2
        if (init > 0): sum += init
    return sum

ans = 0

with open("data.txt", 'r') as file:
    for line in file:
        ans += calc_fuel(int(line))

print(ans)