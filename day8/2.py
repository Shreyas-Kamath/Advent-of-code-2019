with open("data.txt", 'r') as file:
    content = file.read()

width, height = 25, 6
layer_size = width * height
ans = ""
layers = []

def find(_):
    for x in _: 
        if x != '2': return x


for i in range(0, len(content), layer_size):
    layers.append(content[i: i + layer_size])
    
ans = ""

first = list(zip(*layers))
for _ in first:
    ans += find(_)

formatted_output = ""
for i in range(0, len(ans), width):
    formatted_output += ans[i:i + width] + "\n"

formatted_output = formatted_output.replace('0', ' ')

print(formatted_output)


