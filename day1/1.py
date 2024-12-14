ans = 0

with open("data.txt", 'r') as file:
    for line in file:
        ans += int(line) // 3 - 2

print(ans)