import heapq
import sys
input = sys.stdin.readline


V, E = map(int, input().split())
S = int(input())-1
NODE = [[] for i in range(V)]
visited = [100000000]*V                 # 최단 거리 저장
for i in range(E):
    u, v, w = map(int, input().split())
    NODE[u-1].append((w , v-1))             # NODE[노드번호1].append((거리, 노드번호2))

pos = []
visited[S] = 0
heapq.heappush(pos,(0, S))                  # 초기값 pos에 (0,s) 넣어주기

while pos:
    now1, now2 = heapq.heappop(pos)
    if visited[now2] < now1:                # now1이 이미 visited[now2]에 나온 최단거리보다 크면 넘어가기
        continue
    for i, k in NODE[now2]:
        if visited[now2] + i < visited[k]:  # 이미 나온 최단거리보다 작으면 실행
            visited[k] = visited[now2] + i
            heapq.heappush(pos, (visited[k], k))

for i in visited:
    if i == 100000000:
        print('INF')
    else:
        print(i)