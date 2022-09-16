#include <iostream>
#include <algorithm>

using namespace std;

struct ls {
	int I;
	int J;
	int C;
};

int N,MAX,sub3;
int forest[501][501];
int value[501][501];
ls od[255000];
ls sub, sub2;
int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

bool compare(ls a, ls b) {
	return (a.C < b.C);
}																					//sort용 비교함수

int main() {
	scanf("%d", &N);
	int a = -1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &forest[i][j]);					//input을 받아서 
			sub.I = i;
			sub.J = j;
			sub.C = forest[i][j];
			od[++a] = sub;								//od 배열에 담습니다.
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			value[i][j] = 1;								//value를 초기화 해주고
		}
	}

	sort(od, od + N * N, compare);	//대나무 값에 따라 정렬을 합니다

	for (int i = 0; i < N*N; ++i) {	// 가장 작은값부터
		sub = od[i];
		sub3 = 0;
		for (int d = 0; d < 4; ++d) {	//주변을 둘러보면서
			sub2.I = sub.I + di[d];
			sub2.J = sub.J + dj[d];
			sub2.C = forest[sub2.I][sub2.J];
			if (sub2.I >= 0 && sub2.I < N && sub2.J >= 0 && sub2.J < N && sub.C>sub2.C) {
				if (sub3 < value[sub2.I][sub2.J]) sub3 = value[sub2.I][sub2.J];
			}
		}																// 자기보다 작은값들 중에
		value[sub.I][sub.J] = sub3 + 1; // 제일 큰 값 +1로 갱신해주고
		if (value[sub.I][sub.J] > MAX) MAX = value[sub.I][sub.J];
	}												
	printf("%d", MAX);//출력합니다.
	
}