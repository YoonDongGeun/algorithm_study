red=[]  
green=[]
blue=[]     #input 저장할 공간들 입니다.

N=int(input())  #N을 받고
for i in range(N):      #range(N)의 범위에서
    r,g,b=map(int,input().split())
    red.append(r)
    green.append(g)
    blue.append(b)      #input을 색깔별로 나눠서 저장해줍니다.

best_red=[red[0]]
best_green=[green[0]]
best_blue=[blue[0]]     # N번째 집을 이름에 해당하는 색깔로 칠했을때의 최소값을 저장할 공간입니다.

for i in range(1,N):
    best_red.append(min((red[i]+best_blue[i-1]),red[i]+best_green[i-1]))
    best_green.append(min((green[i]+best_red[i-1]),green[i]+best_blue[i-1]))
    best_blue.append(min((blue[i]+best_green[i-1]),blue[i]+best_red[i-1]))

    #i번째 집을 변수 이름의 색깔로 칠할 때는 해당색깔과 다른 i-1번째 집의 정보를 이용합니다.
    #예를 들어 i번째집을 빨간색으로 칠하려면 i-1번째 집을 파란색으로 칠한 최선의 값과 초록으로 칠한 최선의 값 중에
    #더 작은값으로 최선의 방법이 정해집니다.

print(min(best_red[-1],best_green[-1],best_blue[-1]))
#그렇게 채워넣은 정보에서 마지막 값중에 제일 작은 값이 최선의 방법입니다.
