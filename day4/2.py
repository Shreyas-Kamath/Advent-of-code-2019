from collections import Counter

def part_2(password: str) -> bool:
    return any(count == 2 for count in Counter(password).values())

def always_increasing(password: str) -> bool:
    return list(password) == sorted(password)

ans = 0

for password in range(168630, 718098):
    str_password = str(password)
    if part_2(str_password) and always_increasing(str_password): ans += 1

print(ans)