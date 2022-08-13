x, y = map(int, input().split())
motion = [0, [0, 1], [2*x+y, -1], [2*x+2*y, -1], [x, 1]]    # x값에 따라 다르게 배치하는 리스트.
position = [list(map(int,input().split())) for i in range(int(input())+1)]  # 상점의 위치와 경비원 위치 리스트
SOL= 0  # 경비원의 최단거리 합
for i in range(len(position)-1, -1, -1):    # 경비원 위치부터 거리파악.
    if i == len(position)-1:    # 경비원 이라면
        police = motion[position[i][0]][0] + position[i][1]*motion[position[i][0]][1] # 경비원 위치(1차원)
    else:
        if abs(police-(motion[position[i][0]][0] + position[i][1]*motion[position[i][0]][1])) > x+y:    # 거리 차가 x+y보다 높으면 최단거리 아님
            SOL += 2*x+2*y-abs(police-(motion[position[i][0]][0] + position[i][1]*motion[position[i][0]][1]))
        else:
            SOL += abs(police-(motion[position[i][0]][0] + position[i][1]*motion[position[i][0]][1]))
print(SOL)  # 계산한 거리합 계산