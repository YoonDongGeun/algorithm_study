#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int L[10001]{};
	for (int i = 1; i <= 10000; i++) {
		int j = i;  // i부터 수식을 통해 만들어지는 수를
		while (1) {
			j = j + j % 10 + (j >= 10 ? ((j / 10) % 10) : 0) + (j >= 100 ? ((j / 100) % 10) : 0) + (j >= 1000 ? ((j / 1000) % 10) : 0);
            if (L[j]==1) j=10001;
            if (j < 10000) L[j] = 1;    //다 체크합니다.
			else break;                 //만이 넘어가면 멈춥니다
		}
	}
	for (int j = 1; j < 10000; j++) {
		if (L[j] == 0) {                //체크가 안된 수를 출력합니다.
			cout << j<<"\n";
		}
	}
}