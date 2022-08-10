X,Y=list(map(int,input().split())) # X,Y칸
N=int(input()) # 자르는 횟수
x_arr=[0,X] # 나중에 자른 구간들을 구하기 위해 종이 맨 끝도 좌표로 넣어준다 [0,X]
y_arr=[0,Y] # [0,y]도 종이 맨끝이니 넣어준다.
for i in range(N): # 자르는 구간들을 입력하고 저장한다.
    cut=input().split()
    if cut[0]=='0': # cut[0]이 0이면 가로축, 1이면 세로축 자르기
        y_arr.append(int(cut[1]))
    else:
        x_arr.append(int(cut[1]))
x_arr.sort() # x축 자르는 위치 정리
x_span=[] # 자른 후 길이들 리스트
y_arr.sort() # y축 자르는 위치 정리
y_span=[] # 자른 후 길이들 리스트
for i in range(len(x_arr)-1):
    x_span.append(x_arr[i+1]-x_arr[i]) # 0~X 사이 자른 길이 저장.
for i in range(len(y_arr)-1):
    y_span.append(y_arr[i+1]-y_arr[i]) # 0~Y 사이 자른 길이 저장.
print(max(x_span)*max(y_span)) # X 가장 긴 길이 * Y 가장 긴 길이 = 가장 큰 넓이