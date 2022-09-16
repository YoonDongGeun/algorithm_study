C=[[0,1,2],[0,2,1],[1,2,0],[1,0,2],[2,1,0],[2,0,1]]
def take(L,i,n,cnt=0):
    l=r=i
    d=1
    t=1
    for _ in range(n):
        while l>=1 or r<=N:
            if l>=1 and L[l]==0:t=1;break
            if r<=N and L[r]==0:t=0;break
            else:
                l-=1
                r+=1
                d+=1
        if t: L[l]=1
        else: L[r]=1
        cnt+=d
    if t and r<=N and L[r]==0:
        sub=L[::]
        sub[r],sub[l]=sub[l],sub[r]
        return [L,sub],cnt
    return [L],cnt

for T in range(1,int(input())+1):
    N=int(input())
    F=[1]+[0]*N
    L=[list(map(int,input().split())) for _ in '___']
    s=1000000
    for c in C:
        I1,N1 = L[c[0]][0],L[c[0]][1]
        I2,N2 = L[c[1]][0],L[c[1]][1]
        I3,N3 = L[c[2]][0],L[c[2]][1]
        out1s=take(F[:],I1,N1)
        print('out1s:',out1s)
        for out1 in out1s[0]:
            out2s=take(out1[:],I2,N2,out1s[1])
            print('out2s:',out2s)
            for out2 in out2s[0]:
                out3s=take(out2[:],I3,N3,out2s[1])
                if out3s[1]<s:s=out3s[1]
                print('out3s:',out3s)
    print(f'#{T}',s)