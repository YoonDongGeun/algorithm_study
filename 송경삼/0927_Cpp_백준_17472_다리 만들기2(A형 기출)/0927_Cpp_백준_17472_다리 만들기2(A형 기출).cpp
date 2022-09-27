#include <iostream>
#include <vector>
#include <algorithm>

struct eg {			//간선 정보 구조체
	int V;
	int S;
	int E;
};

int N, M;
int island[10][10];
int E[10][10] = { 0, };		//노드간 최소 거리의 간선을 택하기 위한 배열입니다.
int pr[10];					//부모 노드를 저장할 배열입니다.
std::vector <eg> Edge;		//간선 정보를 정렬할 벡터입니다.

bool comp(eg A, eg B) { return A.V < B.V; }	//정렬에 필요한 함수

void setN(int i, int j, int n) {				//땅을 노드화(정점 번호 부여) 시키기 위한 DFS 함수입니다.
	if (i < 0 || i >= N || j < 0 || j >= M) return;
	if (island[i][j] == 1) {
		island[i][j] = n;
		setN(i + 1, j, n);
		setN(i - 1, j, n);
		setN(i, j + 1, n);
		setN(i, j - 1, n);
	}
	else return;
}

void setB(int i, int j) {			//해당 지점에서 이을 수 있는 다리의 길이를 계산하고, 최소값을 갱신할 수 있을 경우 갱신하는 함수입니다.
	int I = i, J = j;
	while (++I <N) {				//아래쪽으로 찾습니다.
		if (island[I][J]) {
			if (I - i - 1 >= 2 && island[I][J] != island[i][j] && (!E[island[i][j]][island[I][J]] || E[island[i][j]][island[I][J]] > I - i - 1)) {
				E[island[i][j]][island[I][J]] = I - i - 1;
				E[island[I][J]][island[i][j]] = I - i - 1;
			}
			break;
		}
	}
	I = i, J = j;
	while (++J <M) {				//오른쪽으로 찾습니다.
		if (island[I][J]) {
			if (J - j - 1 >= 2 && island[I][J] != island[i][j] && (!E[island[i][j]][island[I][J]] || E[island[i][j]][island[I][J]] > J - j - 1)) {
				E[island[i][j]][island[I][J]] = J - j - 1;
				E[island[I][J]][island[i][j]] = J - j - 1;
			}
			break;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &island[i][j]);		//땅과 바다 정보를 받습니다.
		}
	}

	int sub = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (island[i][j] == 1) {
				setN(i, j, ++sub);			//각 땅을 노드화 시킵니다.
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (island[i][j]) setB(i, j);	//각 땅 사이의 가능한 간선을 전부 추출합니다.
		}
	}



	int visit[10] = { 0, };
	for (int s = 2; s < sub; ++s) {				//최소값만 골라낸 간선을 정렬하기 위해 벡터에 담습니다.
		for (int e = s + 1; e <= sub; ++e) {
			if (E[s][e]) {
				Edge.push_back({ E[s][e],s,e });
				visit[s] = 1;
				visit[e] = 1;					//방문하지 않은 노드가 있는지 점검하기 위해 쓰였습니다.
			}
		}
	}
	int cant = 0;
	for (int x = 2; x <= sub; ++x) {			//방문하지 않은 노드가 있다면 모든 섬을 잇는게 불가능하므로 불가능을 출력합니다.
		if (!visit[x]) cant = 1;
	}
	if (cant) printf("-1");



	else {
		std::sort(Edge.begin(), Edge.end(),comp);	//최소 신장 트리를 만들기 위해 길이에 따라 정렬합니다.
		
		for (int x = 2; x <= sub; ++x) {		//처음 부모 노드를 각자 번호로 지정합니다.
			pr[x] = x;
		}

		int sum = 0,cnt=0;

		for (int x = 0; x < Edge.size(); ++x) {	//정렬된 간선 정보를 차례대로 불러와서
			int S = Edge[x].S, E = Edge[x].E;

			if (pr[S] == pr[E])continue;	//만약 사이클이 발생하면 이번 간선을 선택하지 않고 넘어갑니다.

			if (pr[E] != E) {				//이미 이어져있는 노드의 경우

				if (pr[E] < S) {			//현재 저장된 부모 노드의 값이 추가될 값보다 작은 경우
					pr[S] = pr[E];			//이미 부모노드를 잘 찾아 놓은 것이므로 추가 될 값의 부모노드를 갱신해줍니다.
				}
				else {						//추가될 값이 현재 부모노드 번호보다 작은 경우					
					int pr_sub = pr[E];
					for (int z = 2; z <= sub; ++z) {	//현재 부모노드 값을 가진 모든 노드를 갱신해줍니다.
						if (pr[z] == pr_sub) pr[z] = S;
					}
				}
			}
			else {						//안 이어져 있는경우
				int pr_sub = pr[E];		//현재 간선 정보를 모든 부모 노드에 갱신해주고
				for (int z = 2; z <= sub; ++z) {
					if (pr[z] == pr_sub) pr[z] = S;
				}
				pr[E] = S;
				while (pr[S] != S) {	//부모 노드를 찾습니다.
					S = pr[S];
					pr[E] = S;

				}
			}

			sum += Edge[x].V;		//만약 사이클이 발생하지 않았다면 현재 간선 값을 더해주고
			++cnt;					//간선의 개수를 세줍니다
			if (cnt == sub - 2) break;	//N-1개를 택했다면 멈춥니다.
		}
		if (cnt!=sub-2) printf("-1");	//만약 N-1개를 택하지 못했다면 모든 노드를 잇지 못한 것입니다.
		else printf("%d", sum);

	}


}