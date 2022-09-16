def com(L,n):
    ll = len(L[0])
    SUB=[]
    for P in L:
        for l in range(ll + 1):
            for r in range(l, ll + 1):
                SUB.append(P[0:l] + [n] + P[l:r] + [-n] + P[r:])
    return SUB

for t in range(1,int(input())+1):
    N=int(input())
    L=[list(map(int,input().split())) for _ in '_'*N]
    D=[[0]*9 for _ in '_'*9]
    T=[(0,0)]*9
    li=[]

    for i in range(N):
        for j in range(N):
            sub=L[i][j]
            if sub:
                T[sub]=(i,j)
                if sub>0 and sub not in li:li.append(sub)

    for I,(i1,j1) in enumerate(T):
        for J,(i2,j2) in enumerate(T):
                D[I][J]=abs(i1-i2)+abs(j1-j2)

    P=[[]]
    for i in li:
        P=com(P,i)

    m=1e10

    for p in P:
        d=D[0][p[0]]
        for i in range(2*len(li)-1):
            d+=D[p[i]][p[i+1]]
            if d>m:break
        if d<m:m=d
    print(f'#{t}',m)
```