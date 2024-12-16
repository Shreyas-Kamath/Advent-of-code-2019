
def adjacent_digits(password: str) -> bool:
    for i in range(len(password) - 1):
        if password[i] == password[i+1]: return True
    return False

def always_increasing(password: str) -> bool:
    return list(password) == sorted(password)

ans = 0

for password in range(168630, 718098):
    str_password = str(password)
    if adjacent_digits(str_password) and always_increasing(str_password): ans += 1

print(ans)