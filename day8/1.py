with open("data.txt", 'r') as file:
    content = file.read()

width, height = 25, 6
layer_size = width * height

min_zero_count = layer_size + 1

for i in range(0, len(content), layer_size):
    layer = content[i: i + layer_size]
    zero_count = layer.count('0')  

    if zero_count < min_zero_count:
        min_zero_count = zero_count
        ans = layer.count('1') * layer.count('2')

print(ans) 