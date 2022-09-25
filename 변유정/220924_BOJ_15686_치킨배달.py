# DFS
# 과정
# 1. 치킨집(2), 집(1) 배열 만들기
# 2. 치킨집 배열 중에서 폐업 시키지 않을 집(M개) 고르기
# 3. 고른 치킨 집 배열 중 그냥 집과의 최소 거리 찾기
# 4. 전부 돌아보고 최소 거리 찾아내기

def alive(now,cnt,mxx):
    if cnt == mxx:
        findmin()
        return

    for i in range(now+1,cl):
        choose.append(i)
        alive(i,cnt+1,mxx)
        choose.pop()

def findmin():
    global ans
    temp = 0
    for i in range(hl):
        minn = 1e9
        for k in choose:
            y, x = home[i]
            ey, ex = chicken[k]
            if minn > abs(y-ey) + abs(x - ex):
                minn = abs(y-ey) + abs(x-ex)
        temp += minn
    if ans > temp:
        ans = temp

N, M = map(int,input().split())
city = [list(map(int,input().split())) for _ in range(N)]
chicken = []
home = []
choose = []
ans = 1e9
for y in range(N):
    for x in range(N):
        if city[y][x] == 1:
            home.append([y,x])
        elif city[y][x] == 2:
            chicken.append([y,x])
cl = len(chicken)
hl = len(home)
alive(-1,0,M)
print(ans)