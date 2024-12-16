with open("data.txt", 'r') as file:
    data = list(map(int, file.read().split(',')))

for i in range(0, len(data), 4):
    if data[i] == 99: break
    elif data[i] == 1: data[data[i + 3]] = data[data[i+1]] + data[data[i + 2]]
    elif data[i] == 2: data[data[i + 3]] = data[data[i+1]] * data[data[i + 2]]
    else: continue

print(data[0])