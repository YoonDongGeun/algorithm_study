L=[]
for _ in range(int(input())):
    axis,height=map(int,input().split())
    if len(L)<axis: #이번 인덱스가 들어갈 공간이 없다면
        L+=[0]*(axis-len(L))+[height] #0과 해당 인덱스로 이루어진 리스트를 더합니다
    else: L[axis]=height #들어갈 공간이 있다면 껴넣습니다.
    L+=[0,0]
r=len(L)-1  #끝항
M=max(L)    #최대값을 찾습니다.
l,l_m,r_m=(0,)*3 #초항, 좌우 높은값들입니다
while L[l]!=M:  #왼쪽에서부터 오른쪽으로 가면서 높이를 채웁니다.
    if L[l]>l_m:l_m=L[l]
    else:L[l]=l_m
    l+=1
while L[r]!=M:  #오른쪽에서부터 왼쪽으로 채웁니다.
    if L[r]>r_m:r_m=L[r]
    else:L[r]=r_m
    r-=1
if l<r: #l과 r 사이에 거리가 있을경우
    for i in range(l,r+1):  #사이를 채워줍니다.
        L[i]=M
print(sum(L))