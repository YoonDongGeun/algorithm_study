import sys
N=int(sys.stdin.readline())
rmap=[[0]*1001 for _ in range(1001)]
for i in range(1,N+1):
    b,c,d,e=map(int,sys.stdin.readline().split())
    for j in range(c,(c+e)):
        rmap[j][b:b+d]=[i]*d

dict1={}
result=[]
for i in rmap:
    for j in i:
        result.append(j)
for i in range(1,N+1):
    dict1[i]=result.count(i)
for i in range(1,N+1):
    print(dict1[i])

