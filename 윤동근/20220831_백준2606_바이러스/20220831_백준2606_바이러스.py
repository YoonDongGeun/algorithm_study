T = int(input())                    # BFS 탐색.
node = [[] for i in range(T+1)]
for i in range(int(input())):
    a, b = map(int, input().split())
    node[a].append(b)
    node[b].append(a)
visited = [0]*(T+1)
visited[1] = 1                      # 1번 컴퓨터부터 시작.
Q = [1]
cnt = 0
while Q:
    L = len(Q)
    next = Q.pop(0)
    for j in range(L):              # 큐 사용
        for i in node[next]:
            if visited[i] == 1:
                continue
            else:
                Q.append(i)             #
                visited[i] = 1
                cnt += 1
print(cnt)