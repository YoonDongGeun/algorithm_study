N = int(input())
apt = [list(map(int, list(input()))) for i in range(N)]
al = []                                                  # 좌표 리스트 저장 할 공간
m = [(0, 1), (0, -1), (1, 0), (-1, 0)]                   # 상하 좌우 탐색
for i in range(N):
    for j in range(N):
        if apt[i][j] == 1:
            al.append((i, j))                            # 1인 좌표 리스트 저장
total = []                                               # 아파트 단지별 sum 저장
cnt2 = 0                                                 # cnt2에 아파트 단지 개수 저장.
while al:
    cnt2 += 1                                            # stack 1개 길이 0 된 횟수마다 아파트 단지 개수 1 더함
    stack = [al.pop()]
    cnt = 1
    while stack:
        temp = stack.pop()
        for y, x in m:
            for k in range(len(al)):
                if (temp[0]+y, temp[1]+x) == al[k]:      # 상하좌우 맞는 좌표 있으면 +1 없으면 pop만 되다가 stack 사라지고 다시 저장됐던 좌표에서 1개 꺼내서 시작.
                    stack.append(al.pop(k))              
                    cnt += 1
                    break
    total.append(cnt)
total.sort()
print(cnt2, *total, sep='\n')