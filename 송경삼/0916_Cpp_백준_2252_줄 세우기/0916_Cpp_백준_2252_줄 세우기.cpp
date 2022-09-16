#include <iostream>
#include <vector>

#define Max 32001


int N, M,pre,post;
std::vector <int> E[Max];
int cnt[Max];
bool visit[Max];

int main() {
	scanf("%d %d", &N, &M);
	while (M--) {
		scanf("%d %d", &pre, &post);
		E[pre].push_back(post);
		++cnt[post];
	}
	int n = N;
	while (n--) {
		for (int i = 1; i <= N; ++i) {
			if (!cnt[i]&&!visit[i]) { 
				printf("%d ", i);
				visit[i] = 1;
				if (!E[i].empty()) {
					for (int j = 0; j < E[i].size(); ++j) {
						--cnt[E[i][j]];
					}
					E[i].clear();
				}
			}
		}
	}
	printf("\n");
}
