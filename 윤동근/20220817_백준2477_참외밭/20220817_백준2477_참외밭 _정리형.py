K = int(input())
field = [list(map(int, input().split())) for i in range(6)]
max_num = max(field, key=lambda x: x[1])
for i in range(len(field)):
    if field[i] == max_num:
        if field[i-5][1] == field[i-3][1] + field[i-1][1]:
            solution = field[i][1] * field[i-5][1] - field[i-3][1] * field[i-2][1]
            break
        else:
            solution = field[i][1] * field[i-1][1] - field[i-4][1] * field[i-3][1]
            break
print(solution*K)