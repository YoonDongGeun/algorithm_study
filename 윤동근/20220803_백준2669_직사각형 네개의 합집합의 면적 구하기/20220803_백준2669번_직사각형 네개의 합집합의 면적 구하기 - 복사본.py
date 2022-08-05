A=[]
B=set()
cnt=0
for i in range(4):
    a,b,c,d=list(map(int,input().split()))
    B|={(x,y) for x in range(a,c) for y in range(b,d)}
print(len(B))