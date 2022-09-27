#include <iostream>

int di[5] = { 0,-1,1,0,0 };
int dj[5] = { 0,0,0,-1,1 };
int RD[5] = { 0,2,1,4,3 };

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int N, M, K,i,j,sum=0;
		scanf("%d %d %d", &N, &M, &K);
		int cell[100][100][3][2] = { 0, };	// cell[i행][j열][0:크기,1:방향,2:병합용 보조변수][현재or미래]
		while (K--) {
			scanf("%d %d", &i, &j);
			scanf("%d %d", &cell[i][j][0][0], &cell[i][j][1][0]);
		}
		bool now = 0;	// 첫 실행시 현재는 0입니다.
		while (M--) {
			bool next = 1 - now;	// 첫 실행시 미래는 1입니다.

			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {	//각 인덱스를 돌면서
					if (cell[i][j][0][now]) {	//현재 군집이 있는 공간이라면
						int I = i + di[cell[i][j][1][now]], J = j + dj[cell[i][j][1][now]];

						cell[i][j][2][now] = cell[i][j][0][now];	//지금의 크기로 보조 변수를 갱신해줍니다.
						
						if (I == 0 || I == N - 1 || J == 0 || J == N - 1) {	//만약 외곽에 빠졌다면
							cell[I][J][0][next] = cell[i][j][0][now]/2;		//크기 절반
							cell[I][J][1][next] = RD[cell[i][j][1][now]];	//방향 반대
							cell[I][J][2][next] = cell[i][j][2][now]/2;		//그에 따라 보조변수도 절반의 크기
						}
						else if (cell[I][J][0][next]) {						//만약 미래에 이미 자리를 차지한 곳이라면
							cell[I][J][0][next] += cell[i][j][0][now];		//크기는 병합
							if (cell[I][J][2][next] < cell[i][j][2][now]) {	//만약 지금 들어갈 군집이 더크다면
								cell[I][J][2][next] = cell[i][j][2][now];	//지금 들어가는 군집의 크기로 보조변수가 변합니다.
								cell[I][J][1][next] = cell[i][j][1][now];	//방향또한 지금들어가는 군집의 방향으로 변합니다.
							}
						}
						else {												//두 경우 모두 속하지 않는다면
							cell[I][J][0][next] = cell[i][j][0][now];		//현재의 정보 그대로 미래로 옮깁니다.
							cell[I][J][1][next] = cell[i][j][1][now];
							cell[I][J][2][next] = cell[i][j][2][now];
						}
						cell[i][j][0][now]=0;								//현재의 정보를 지우고
						cell[i][j][1][now]=0;
						cell[i][j][2][now]=0;
					}
				}
			}
			now = next;		//기록한 미래가 곧 현재가 되고 이 과정이 반복됩니다.
		}

		for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					sum += cell[i][j][0][now];	//남아있는 군집을 모두 더해줍니다.
				}
			}
		printf("#%d %d\n", t, sum);

	}
}