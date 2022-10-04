#include <iostream>
#include <vector>
#include <queue>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, K, b_t[1001],cnt[1001]={0,}, time[1001]={0,}, s, e, end;
		std::vector <int> edges[1001];            
		std::queue <int> Q;

		scanf("%d %d", &N, &K);
		for (int n = 1; n <= N; ++n) scanf("%d", &b_t[n]);      
		while (K--) {
			scanf("%d %d", &s, &e);
			edges[s].push_back(e);
			++cnt[e];
		}
		scanf("%d", &end);

		for (int i = 1; i <= N; ++i) {    //진입차수 배열을 돌면서 진입 차수가 0인 곳을 큐에 푸쉬해줍니다.
			if (!cnt[i]) {
				Q.push(i);
				time[i] = b_t[i];
			}
		}
		while (cnt[end]) {                  //도착점의 진입차수가 0이 될 때까지 진행
			s = Q.front();              
			Q.pop();
			for (int i = 0; i < edges[s].size(); ++i) {     //다음 도착점 목록을 보면서
				e = edges[s][i];                      
				if (time[s] + b_t[e] > time[e]) time[e] = time[s] + b_t[e];   //만약 더 오래걸리는 루트가있다면 갱신해줍니다
				if (!(--cnt[e])) {  //새로 진입차수가 0이 된 곳이 있다면 큐에 넣어줍니다.
					Q.push(e);
				}
			}
		}
		printf("%d\n", time[end]);

	}

}