dir=[(1,0),(-1,0),(0,1),(0,-1)]
next=[0,(0,1,2,3),(0,1),(2,3),(1,2),(0,2),(0,3),(1,3)]
can=[(1,2,4,7),(1,2,5,6),(1,3,6,7),(1,3,4,5)]

for t in range(1,int(input())+1):
    N,M,R,C,L=map(int,input().split())
    tn=[list(map(int,input().split())) for _ in '_'*N]
    visit=[[0]*M for _ in '_'*N]
    cnt=0
    Q=[(R,C,1)]
    visit[R][C]=1
    l=0;r=1

    while(l<r):
        i,j,c=Q[l];l+=1
        print(i,j,c)
        if c>L:break
        else:cnt+=1
        temp=tn[i][j]
        for d in next[temp]:
            ni,nj=i+dir[d][0],j+dir[d][1]
            if ni<0 or ni>=N or nj<0 or nj>=M or visit[ni][nj] or tn[ni][nj] not in can[d]:continue
            visit[ni][nj]=1
            Q.append((ni,nj,c+1));r+=1
    print(f'#{t}',cnt)













