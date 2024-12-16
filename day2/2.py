with open("data.txt", 'r') as file:
    data = list(map(int, file.read().split(',')))


def help(data: list[int], noun: int, verb: int) -> int:
    data[1], data[2] = noun, verb
    for i in range(0, len(data), 4):
        if data[i] == 99: break
        elif data[i] == 1: data[data[i + 3]] = data[data[i+1]] + data[data[i + 2]]
        elif data[i] == 2: data[data[i + 3]] = data[data[i+1]] * data[data[i + 2]]
        else: continue
    return data[0] == 19690720

for noun in range(100):
    for verb in range(100):
        if help(list(data), noun, verb):
            print(100 * noun + verb)

