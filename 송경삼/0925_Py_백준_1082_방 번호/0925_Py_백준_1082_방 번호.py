
def ch(S,b):
    for i in range(len(S)):
        if int(S[i])<=b:
            S=S[:i]+str(b)+S[i:]
            break
    return S
    
N=int(input())
cost=list(map(int,input().split()))
M=int(input())

DP=['']*(M+1)

for m in range(M+1):
    dp=[]
    if m>0 and DP[m-1]:dp.append(DP[m-1])
    for i in range(len(cost)):
        if m-cost[i]>=0:
            if not DP[m-cost[i]]:dp.append(str(i))
            else:
                dp.append(ch(DP[m-cost[i]],i))
    if dp:DP[m]=max(dp,key=lambda x:int(x))

print(DP[-1])

