from sys import exit
w,h=map(int, input().split())
x,y=map(int, input().split())
t=int(input())  #인풋을 받습니다.

d=1 #첫 이동 방향 direction 1 입니다.

if (w-x)<(h-y): #x축과 y축중 가까운 거리를 판별합니다.
    d=2 #x축이 더 가깝다면 direction 2로 바꿉니다.
    if t>(w-x): #x축과의 거리보다 이동해야할 거리가 더 멀다면
        t-=(w-x)    #x축과의 거리를 이동거리에서 빼줍니다.
    else:
        print(x+t,y+t)  #이동거리가 더 짧다면 이동 후 좌표를 출력하고 끝냅니다.
        exit()
    y+=(w-x)    #끝까지 이동했다면 좌표를 바꿔줍니다. x축 끝
    x=w
else:   #위와 같은 로직인데, y축이 더 짧을 경우입니다.
    d=4 #direction 4로 바꿉니다.
    if t>(h-y):     #똑같은 끝까지 이동가능 여부 판단입니다.
        t-=(h-y)
    else:
        print(x+t,y+t)
        exit()
    x+=(h-y)
    y=h

dis=t   #첫 이동 후 남은 거리를 저장합니다.
Q=[x,y] #첫 이동 좌표를 저장합니다.
D=d     #첫 이동 후 방향을 저장합니다.

while True:     #위와 같은 끝까지 로직을 반복합니다.
    if d==1:    #입사각이 우상향일 경우입니다.
        if (w-x)<(h-y): #거리 판단
            d=2 #방향바꿈
            if t>(w-x): #도착 판단
                t-=(w-x)
            else:
                print(x+t,y+t) #루프 탈출판단
                break
            y+=(w-x)    #좌표 바꿈
            x=w
        else:   #똑같은 로직의 y축이 더가까울 경우입니다.
            d=4
            if t>(h-y):
                t-=(h-y)
            else:
                print(x+t,y+t)
                break
            x+=(h-y)
            y=h

    elif d==2:  #위와 똑같은 로직에서 입사각이 좌상향일 경우입니다.
        if x<(h-y):
            d=1
            if t>x:
                t-=x
            else:
                print(x-t,y+t)
                break
            y+=x
            x=0
        else:
            d=3
            if t>(h-y):
                t-=(h-y)
            else:
                print(x-t,y+t)
                break
            x-=(h-y)
            y=h

    elif d==3:  #똑같은 로직에서 입사각이 좌하향일 경우입니다.
        if x<y:
            d=4
            if t>x:
                t-=x
            else:
                print(x-t,y-t)
                break
            y-=x
            x=0
        else:
            d=2
            if t>y:
                t-=y
            else:
                print(x-t,y-t)
                break
            x-=y
            y=0

    else:   #우하향일 경우입니다.
        if (w-x)<y:
            d=3
            if t>(w-x):
                t-=(w-x)
            else:
                print(x+t,y-t)
                break
            y-=(w-x)
            x=w
        else:
            d=1
            if t>y:
                t-=y
            else:
                print(x+t,y-t)
                break
            x+=y
            y=0

    if [x,y]==Q and d==D:   #만약 첫 이동점에 똑같은 방향으로 도착한다면
        t=t%(dis-t) #이동거리만큼 계속 반복되므로 이동거리에서 반복횟수만큼 빼줘서 연산량을 줄입니다.