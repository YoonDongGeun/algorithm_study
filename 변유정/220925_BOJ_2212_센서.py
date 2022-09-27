# 그리디 알고리즘
# 과정
# 1. 배열 정렬 후 사이 거리 모두 구하기
# 2. 사이 거리 배열 정렬
# 3. 거리 배열 중에서 뒤쪽 중 K개 만큼 빼기 (사이 거리 넓은거)

N = int(input())
K = int(input())
sensor = list(map(int,input().split()))
sensor.sort()
if K >= N:
    print(0)
else:
    array = []
    for i in range(0,N-1):
        array.append(sensor[i+1] - sensor[i])
    ans = sum(array[:N-K])
    print(ans)