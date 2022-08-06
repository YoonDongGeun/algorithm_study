import sys
N=int(sys.stdin.readline())
rlist=[list(map(int,sys.stdin.readline().split())) for i in range(N)]
mx=(lambda y: y[0]+y[2])(max(rlist,key=lambda x: x[0]+x[2]))
my=(lambda y: y[1]+y[3])(max(rlist,key=lambda x: x[1]+x[3]))
rmap=[[0]*(mx) for _ in range(my)]  
for i in range(1,N+1):
    for j in range(rlist[i-1][1],(rlist[i-1][1]+rlist[i-1][3])):
        for k in range(rlist[i-1][0],rlist[i-1][0]+rlist[i-1][2]):
            rmap[j][k]=i
ans_list=[ans for x in rmap for ans in x]
for i in range(1,N+1):
    print(ans_list.count(i))