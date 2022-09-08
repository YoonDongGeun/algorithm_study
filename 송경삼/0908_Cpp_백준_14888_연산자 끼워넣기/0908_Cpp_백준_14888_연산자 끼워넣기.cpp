#include <iostream>
using namespace std;

int N;					
int num[12];		//숫자 저장 배열입니다.
int op[4];			//연산자 개수 카운트 배열입니다.
int M=-1e10, m=1e10;


void BT(int c) {
	if (c == N) {	//재귀깊이 끝에 다다르면
		if (num[c-1] > M)M = num[c-1];	//최대 최소값을 갱신합니다.
		if (num[c-1] < m)m = num[c-1];	
	}
	for (int a = 0; a < 4; a++) {	//연산자를 순회하면서

		if (op[a]) {	//만약 해당 연산자의 개수가 남았다면
			op[a]--;	//하나를 쓰고
			int sub = num[c];	//값을 계산하기전 미리 sub에 저장해놓습니다.
			if (a == 0) num[c] += num[c - 1];
			else if (a == 1) num[c] = num[c - 1]-num[c];
			else if (a==2) num[c] *= num[c - 1];
			else if (a==3) num[c] = num[c - 1]/num[c];	//연산자의 종류에 따라 계산한 후
			BT(c + 1);	//다음 재귀로 넘어갑니다.
			num[c] = sub;	//돌아왔다면 sub로 다시 복구해주고
			op[a]++;			//연산자도 채워줍니다.
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];	//숫자들을 배열에 저장합니다.
	}
	for (int j = 0; j < 4; j++) {
		cin >> op[j];		//각 연산자 개수를 저장합니다.
	}
	BT(1);
	cout << M <<"\n"<<m;
}