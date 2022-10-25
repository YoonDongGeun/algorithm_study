// 구구단
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < 10; i++) {
		cout << n << " * " << i << " = " << n * i << endl;
	}
	return 0;
}

// 한줄 교훈. 공백 들어가더라도 문자열이다.. ""써야함