I=lambda :map(int,input().split())

def is_ok(films):
    global RK,RW,Kc
    for w in RW:
        for k in RK:
            c=(Kc<<k)
            C=films[w]&c
            if (C==0 or C==c):break
        else:return 0
    return 1

def dfs(F,n,last):
    global flag
    if flag:return
    if n==m:
        flag=is_ok(F)
    else:
        for i in range(last+1,D):
            dfs(list(map(lambda x:(x|(1<<i)),F)),n+1,i)
            dfs(list(map(lambda x:(x&(~(1<<i))),F)),n+1,i)

for t in range(1,int(input())+1):
    D,W,K=I();films=list(I())
    Kc=2**K-1;RK=range(D-K+1);RW=range(W);flag=0
    for d in range(1,D):
        sub=list(I());c=2**d
        for w in range(W):films[w]+=sub[w]*c
    if is_ok(films):print(f'#{t} 0');continue
    for m in range(1,K):
        dfs(films,0,-1)
        if flag:print(f'#{t}',m);break











