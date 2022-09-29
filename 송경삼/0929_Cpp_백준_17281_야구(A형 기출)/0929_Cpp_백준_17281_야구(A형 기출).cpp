#include <iostream>

int start(int (*info)[10], int *comb,int &N) {  //타자순서에 따라 게임을 진행시키는 함수입니다.
	int i = 1, t=0, out_cnt=0, score=0;
	bool B[4] = { 0, };
	while (i <= N) {
		int heat = info[i][comb[t]];
		if (heat) {                       //아웃이 아닐경우
			B[0] = 1;                       //타자를 준비시키고
			for (int x = 3; x >= 0; --x) {  //주자들을 x루타 만큼 이동시킵니다.
				if (B[x]) {
					if (x + heat > 3) ++score;  //4루 이상간것이면 점수가 났습니다
					else B[x + heat] = 1;
					B[x] = 0;
				}
			}
		}
		else {                            //아웃일경우 아웃카운트+1
			if (++out_cnt == 3) {           //3아웃일경우
				++i;                          //이닝을 증가시키고
				out_cnt = 0;                  //아웃카운트 초기화
				for (int x = 3; x >= 0; --x) B[x] = 0;  //출루상황도 초기화합니다.
			}
		}
		++t %= 9;
	}
	return score;
}

void DFS(int n, int &N, int *ans, int *comb, bool *use, int (*info)[10]) {  //순열을 구하는 함수입니다.
	if (n == 8) {
		int temp = start(info, comb, N);  //8명의 타자를 다 배치했으면 게임을 진행시키고
		if (temp > *ans) *ans = temp;     //점수별로 최대값을 갱신합니다
	}
	else {
		for (int i = 2; i <10 ; ++i) {   
			if (!use[i]) {                  //사용되지 않은 번호면
				if (n > 2) {                  //4번타석 건너뛰고 배치합니다.
					comb[n +1] = i;
				}
				else comb[n] = i;
				use[i] = 1;                   
				DFS(n + 1, N, ans, comb, use,info);
				if (n > 2) {
					comb[n + 1] = 0;
				}
				else comb[n] = 0;
				use[i] = 0;
			}
		}
	}

}


int main() {
	int N,ans;
	int info[51][10];
	int o_cnt;
	scanf("%d", &N);
	for (int n = 1; n <= N; ++n) {
		for (int t = 1; t <= 9; ++t) {
			scanf("%d", &info[n][t]);
		}
	}
	bool use[10] = { 0, };
	use[1] = 1;
	int comb[9];
	comb[3] = 1;
	DFS(0, N, &ans, comb, use, info);
	printf("%d", ans);
}