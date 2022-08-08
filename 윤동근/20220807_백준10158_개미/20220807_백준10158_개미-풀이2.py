#처음 개미는 x,y방향으로 1칸씩 이동하는 것으로 시작된다.
#이때, 처음 벽에 닿을때 방향이 전환되는 방향이 다른 경우는 3가지 이다.
#1.우측벽에 부딪힐 때, 2. 위쪽벽에 부딪힐 때, 3. 대각선 모서리에 부딪힐 때이다.
# 위의 조건들을 수식으로 정리해보자. 우선 x축은 0부터 W까지, y축은 0부터 h까지 범위가 제한된다.
# 그리고 벽에 부딪히는 것을 계산해 봤을때, 어느 주기를 가질 수 밖에 없다는 것을 알 수 있다.

w,h=map(int,input().split()) #x축 너비는 w, y축높이는 h이다.
x,y=map(int,input().split()) #개미의 초기위치 x,y이다.
t=int(input())#t시간후의 개미위치를 구한다. (1시간에 x,y축은 1씩 변한다.)
def ant(w,h,x,y,t):
    if w==h:#정사각형
        cycle=2*w #정사각형 싸이클
    else:#직사각형
        cycle=h*w #직사각형 싸이클
    t=t%cycle #t에서 싸이클 없애고 나머지 t

    if (t//w)%2==0:
        x=(x+(t%w))%w
    else:
        if w-x<t%w:
            x=t%w+x-w
        else:
            x=w-x-t%w
    if (t//h)%2==0:
        y=(y+(t%h))%h
    else:
        if h-y<t%h:
            y=t%h+y-h
        else:
            y=h-y-t%h
    return print(x,y)
ant(w,h,x,y,t) 
'''
    else:

    t/h
    int(x/w)+int(x%w)
    int(y/h)+int(y%h)
    for i in range(t):
        if cntx==0:
            x+=1
            if x==w:
                cntx=1     
        else:
            x-=1
            if x==0:
                cntx=0

        if cnty==0:
            y+=1
            if y==h:
                cnty=1
        else:
            y-=1
            if y==0:
                cnty=0
    return print(x,y)
'''
