N, M, V = map(int, input().split())
NODE = [[] for i in range(N+1)]     # 노드들 갈 수 있는곳 표시
visited = [0] * (N+1)               # 방문한 곳 표시
visited[V] = 1
Qp = [V]
for i in range(M):
    a, b = map(int, input().split())
    NODE[a].append(b)                   # 양방향 노드
    NODE[b].append(a)
for i in range(N+1):
    NODE[i].sort()                      # 낮은 숫자부터 넣기위해 정렬
Q = [V]
while Q:
    for i in range(len(Q)):
        now = Q.pop(0)                  # BFS 는 큐를 사용
        for j in NODE[now]:
            if visited[j] == 0:
                Q.append(j)
                visited[j] = 1
                Qp.append(j)
stack = [V]
visited = [0] * (N+1)
visited[V] = 1
Stackp=[V]
while stack:                            # DFS는 stack사용
    now = stack[-1]
    for j in NODE[now]:
        if visited[j] == 0:
            stack.append(j)
            visited[j] = 1
            Stackp.append(j)
            break
    else:
        stack.pop()
print(*Stackp)
print(*Qp)