import sys
N,M=map(int,sys.stdin.readline().split())
SL=[]
LL=[]
for i in range(N):
    a,b,c=map(int,sys.stdin.readline().split())
    VL=[(0,0)]
    for j in range(c):
        m1=a*(j+1)
        h1=b*(j+1)
        if m1<=M:
            VL.append((m1,h1))
    SL.append(VL)
print(SL)

for i in range(len(SL))[::-1]:
    if len(SL)==1:
        break
    for j in range(len(SL[i])):
        for k in range(len(SL[i-1])):
            m=SL[i][j][0]+SL[i-1][k][0]
            if m<=M:
                h=SL[i][j][1]+SL[i-1][k][1]
                LL.append((m,h))
    del SL[i]
    del SL[i-1]
    SL.append(list(set(LL)))
print(max(*SL,key=lambda x: x[1])[1])




#print(SL)
    #LL+=[(a,b)]*c
    #A={'V':a,'C':b,'K':c }
    #VL.append(A)
#VL.sort(key=lambda x:(x['C']/x['V']),reverse=True)


'''
def rec(LL,KL=[],c=1):
    for k in LL:
        for i in range(len(k)):
            for j in range(len(k)-i-1):
                mass=k[i][0]+k[i+j+1][0]
                hap=k[i][1]+k[i+j+1][1]
                if mass>M:
                    continue
                else:
                    AL=deepcopy(k)
                    del AL[i+j+1]
                    del AL[i]
                    AL=AL+[(mass,hap)]
                    KL.append(tuple(AL))
        KL=set(KL)
        if(set(LL)==KL):
            return KL
        return rec(list(KL),[],len(KL))
print(rec(LL))
'''

'''
def mhappy(VL):
    mass=0
    happy=0
    for i in range(len(VL)):
        for j in range(VL[i]['K']):
            if mass+VL[i]['V']>M:
                break
            mass+=VL[i]['V']
            happy+=VL[i]['C']
            KL.append((mass,happy))
    return KL

for i in range(len(VL)):
    SL.append(mhappy(VL[i:]))
print(SL)

for i in 
'''