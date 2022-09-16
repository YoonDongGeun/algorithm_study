N=int(input())
max=0
MAX=[]
R1=int(3*N/5) if int((3*N/5))!=0 else 1 #시작점
R2=int(2*N/3)+2 #끝점
for i in range(R1,R2):
    sub=[N,i]   #리스트생성
    while sub[-2]>=sub[-1]:
        sub.append(sub[-2]-sub[-1]) #수이어가기
    if len(sub)>max:max=len(sub);MAX=sub    #더 긴 sub를 만들경우 갱신
print(max)
print(*MAX)
