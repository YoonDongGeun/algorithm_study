#include <iostream>

int min = 1000;

int FD(int parents[],int x) {		//x 정점의 부모를 정점찾아 반환하는 함수입니다.
	while (x != parents[x]) {
		x = parents[x];
	}
	return x;		
}
void UN(int parents[], int a, int b) {	//a와 b를 같은 그래프에 속하게하는 함수입니다.
	parents[FD(parents, b)] = FD(parents, a);
}


void dfs(int n, int cnt, int (*edges)[11], int selected, int& N, int pp[]) {

	if (cnt > N / 2) return;

	int parents[11],pc[11]={0,};	//이번 selected가 합당한지 분석하기 위한 부모리스트, 부모가 몇명인지 파악하기 위한 변수입니다.
	for (int x = 1; x <= N; ++x) parents[x] = x;	//각자 부모를 정해줍니다
	for (int i = 1; i < N; ++i) {	//i정점이랑 j정점을 볼 것입니다.
		for (int j = i + 1; j <= N; ++j) {
			if (edges[i][j] && (((selected & (1 << i))>0) == ((selected & (1 << j))>0))) {
				UN(parents, i, j);	//만약 둘 사이에 간선이 존재하고, 둘 다 선택 되었거나 둘다 선택되지 않았으면 같은 그래프에 속하도록 함수를 호출해줍니다.
			}
		}
	}
	for (int x = 1; x <= N; ++x) pc[FD(parents, x)] = 1;	//N까지의 숫자를 돌면서 존재하는 부모를 체크해줍니다.
	int ok=0; //부모가 몇명인지 세볼것입니다.
	for (int x = 1; x <= N; ++x) ok += pc[x];
	if (ok == 2) { //부모가 두명이라면 그래프가 두개만 존재하는 것이므로

		int c1 = 0, c2 = 0, ans;
		for (int i = 1; i <= N; ++i) {
			if (selected & (1 << i)) c1 += pp[i];
			else c2 += pp[i];	//각자 영역의 인원수를 합쳐줍니다.

		}
		if (c1 > c2) ans = c1 - c2;
		else ans = c2 - c1;	//인원수의 차이를 구하고
		if (ans < min) min = ans;	//현재 저장된 차이보다 적다면 갱신해줍니다.
	}

	for (int i = n + 1; i <= N; ++i) {	//다음 선택을 하고 dfs를 이어갑니다.
		dfs(i, cnt+1, edges, selected|(1 << i) , N, pp);
	}
}

int main() {
	int N,pp[11],edges[11][11]={0,};
	int selected=0;
	
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &pp[i]);
	for (int s = 1; s <= N; ++s) {
		int n,e;
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &e);
			edges[s][e] = 1;
			edges[e][s] = 1;
		}
	}
	dfs(0, 0, edges, selected, N, pp);
	if (min == 1000) printf("-1");
	else printf("%d\n", min);
}