import sys
N,M=map(int,sys.stdin.readline().split())
SL=[]
cnt=0
LL=set()
for i in range(N):
    SL.append([(0,0),tuple(map(int,sys.stdin.readline().split()))])
for i in range(len(SL))[::-1]:
    if len(SL)==1:
        break
    for j in range(len(SL[i])):
        for k in range(len(SL[i-1])):
            m=SL[i][j][0]+SL[i-1][k][0]
            if m<=M:
                h=SL[i][j][1]+SL[i-1][k][1]
                LL.add((m,h))
    for l in list(LL):
        cnt=0
        for o in LL:
            if (l[0]>o[0])and(l[1]>o[1]):
                cnt+=1
    SL=SL[:i-1]+[list(LL)]
print(SL)
print(max(*SL,key=lambda x: x[1])[1])
P = [[0]*(N + 1) for _ in range(M + 1)]
print(P)



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