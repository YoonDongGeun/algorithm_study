#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int adjL[101][101];
int visited[101];

// [A] 각 출발점에서 연결된 송전탑 개수를 반환하는 bfs 함수
int N;
int bfs(int i) {
    int cnt = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        cnt++;
        int now = q.front();
        q.pop();
        for (int next = 1; next <= N; next++) {
            if (adjL[now][next] && !visited[next]) {
                visited[next] = 1;
                q.push(next);
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    N = n;

    // [1] wires 연결관계를 adjL에 저장
    for (int i = 0; i < wires.size(); i++) {
        int A = wires[i][0];
        int B = wires[i][1];
        adjL[A][B] = adjL[B][A] = 1;
    }

    // [2] wires의 각 wire를 하나씩 끊는다고 가정하여 완전탐색.
    //     wire의 A와 B를 visited처리하고 bfs탐색하면 양쪽의 차이를 구할 수 있다.
    for (int i = 0; i < wires.size(); i++) {
        memset(visited, 0, sizeof(visited));
        int A = wires[i][0];
        int B = wires[i][1];
        visited[A] = 1;
        visited[B] = 1;
        answer = min(answer, abs(n - 2 * bfs(A)));
    }
    return answer;
}