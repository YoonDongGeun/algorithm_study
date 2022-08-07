import sys
N=int(sys.stdin.readline())
rlist=[list(map(int,sys.stdin.readline().split())) for i in range(N)]
ans_list=[]
on_set=set()
mx=(lambda y: y[0]+y[2])(max(rlist,key=lambda x: x[0]+x[2]))
my=(lambda y: y[1]+y[3])(max(rlist,key=lambda x: x[1]+x[3]))
mm=mx*my
for i in range(1,N+1)[::-1]:
    if len(on_set)==mm:
        for m in range(i,N+1):
            ans_list.append(0)
        break
    cnt=0
    for j in range(rlist[i-1][1],(rlist[i-1][1]+rlist[i-1][3])):
        
        for k in range(rlist[i-1][0],rlist[i-1][0]+rlist[i-1][2]):
            if (j,k) not in on_set:
                on_set.add((j,k))
                cnt+=1
            else:
                pass
    ans_list.append(cnt)

for i in ans_list[::-1]:    
    print(i)