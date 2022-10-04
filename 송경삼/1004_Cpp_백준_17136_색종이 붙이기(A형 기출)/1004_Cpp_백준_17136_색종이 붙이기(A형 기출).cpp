#include <iostream>

int min=26;
int feild[10][10] = { 0, };
long long cnt[6];

void dfs() {
	int notyet=0,i,j;		// notyet= 아직 가려야할 곳이 남았다는 표시입니다

	for (i = 0; i < 10; ++i) {
		for (j = 0; j < 10; ++j) {		//전체를 돌면서
			if (feild[i][j]) { notyet = 1; break; }	//만약 1이 남은곳이있다면 멈춥니다.
		}
		if (notyet) break;
	}

	if (notyet) {	//1이 남아있는 경우
		for (int l = 5; l > 0; --l) {	//5번종이부터 1번종이까지 순회합니다
			if (cnt[l]) {
				int check = 0;		//이번 종이가 들어갈 수 있는지 확인하고자합니다.
				for (int di = 0; di < l; ++di) {
					for (int dj = 0; dj < l; ++dj) {
						if (i+di>9 || j+dj>9 || !feild[i + di][j + dj]) {
							check = 1; break;	//못들어간다면 못들어간다고 표시하고 다음 종이로넘어갑니다
						}
					}
				}
				if (!check) { //들어갈수있다면 들어가고
					for (int di = 0; di < l; ++di) {
						for (int dj = 0; dj < l; ++dj) {
							feild[i + di][j + dj] = 0;	//종이를 놓는 곳을 0으로 만듭니다.
						}
					}
					--cnt[l];	//종이 개수를 빼주고
					dfs();	//다음 dfs로 넘어갑니다.
					++cnt[l];	//돌아왔다면 종이 개수를 다시 더해주고
					for (int di = 0; di < l; ++di) {
						for (int dj = 0; dj < l; ++dj) {
							feild[i + di][j + dj] = 1;
						}	//종이를 치웁니다.
					}
				}
			}
		}
	}
	else {	//다 놓여져있다면 최소값일 경우에 갱신해줍니다
		if (min > (25 - cnt[1] - cnt[2] - cnt[3] - cnt[4] - cnt[5])) {
			min = (25 - cnt[1] - cnt[2] - cnt[3] - cnt[4] - cnt[5]);
		}
	}
}

int main() {
	for (int i = 0; i < 6; ++i) cnt[i] = 5;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			scanf("%d", &feild[i][j]);
		}
	}
	dfs();
	if (min == 26) {
		printf("%d", -1);
	}
	else printf("%d", min);
}