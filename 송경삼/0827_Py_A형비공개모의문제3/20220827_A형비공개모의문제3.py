def shu(L,x):
    d=x-w
    subl=[0]*d+L[:w]+[0]*-d
    subr=[0]*-d+L[w:]+[0]*d
    sub=[]
    for a,b in zip(subr,subl):
        if a:sub.append(a)
        if b:sub.append(b)
    return sub

for T in range(1,int(input())+1):
    N=int(input())
    w=N//2
    Ls=[list(map(int,input().split()))]
    ans1=[_ for _ in range(1,N+1)]
    ans2=ans1[::-1]
    G=-1
    if Ls[0]!=ans1 and Ls[0]!=ans2:
        for c in [1,2,3,4]:
            SUB_L=[]
            for i in range(1,N):
                for L in Ls:
                    SUB=shu(L,i)
                    if SUB==ans1 or SUB==ans2:
                        G=c
                        break
                    SUB_L.append(SUB)
                else:continue
                break
            else:
                Ls=SUB_L
                continue
            break
    else:G=0
    if G==-1:
        for L in Ls:
            if L[0]==1 or L[0]==N:
                for i in range(1,w):
                    SUB=shu(L,i)
                    if SUB==ans1 or SUB==ans2:
                        G=5
                        break
                else:continue
                break
            elif L[w]==1 or L[w]==N:
                for i in range(w,N):
                    SUB=shu(L,i)
                    if SUB==ans1 or SUB==ans2:
                        G=5
                        break
                else:continue
                break
    print(f'#{T}',G)


