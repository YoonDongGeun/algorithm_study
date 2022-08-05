
X,Y=map(int, input().split())
N=int(input())  #인풋을 받습니다.

x,y=1,0 #초기 위치입니다.
if N>X*Y:   #N이 자리개수보다 크다면
    print(0)    #0을 출력하고 종료합니다.
else:   #아니라면
    for cnt in range(0,N,2): #cnt(한바퀴 상수)를 2씩늘려가면서 
        if N<=0:    #N이 남아있지않으면
            break   #종료
        if N-(Y-cnt)>=0:    #위로 쭉 갈 수 있으면 갑니다. 
            y+=Y-cnt    #y축을 갱신하고
            N-=Y-cnt    #이동한 만큼 N값을 줄여줍니다.
        else:       #쭉 갈수 없다면
            y+=N    #N만큼 이동하고
            break   #종료
        
        if N-(X-1-cnt)>=0:  #위와 같은 메커니즘으로 오른쪽으로 갑니다.
            x+=(X-1-cnt)
            N-=(X-1-cnt)
        else:
            x+=N
            break
        
        if N-(Y-1-cnt)>=0: #위와 같은 메커니즘으로 아래로갑니다.
            y-=(Y-1-cnt)
            N-=(Y-1-cnt)
        else:
            y-=N
            break 
        
        if N-(X-2-cnt)>=0: #위와 같은 메커니즘으로 왼쪽으로 갑니다.
            x-=(X-2-cnt)
            N-=(X-2-cnt)
        else:
            x-=N
            break
    
    print(x,y) #N만큼 이동했으면 x,y를 출력하고 종료합니다.


    

