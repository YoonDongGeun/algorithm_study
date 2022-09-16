J,I=map(int,input().split())
P=[[0,I],[0,J]] #저장공간
N=int(input())
for i in '_'*N:
    s,c=map(int,input().split())
    P[s].append(c)  #i축이면 i축저장공간에,j축이면 j축 저장공간에 저장합니다
for i in (0,1): #각 축을
    P[i].sort() #정렬하고
    P[i]=[x-y for x,y in zip(P[i][1:],P[i][:-1])]   #간격을 구해 줍니다
print(max(P[0])*max(P[1]))  #최대간격끼리 곱한값을 출력