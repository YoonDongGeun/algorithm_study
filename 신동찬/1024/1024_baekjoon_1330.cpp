// 두 수 비교하기
#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	if (a > b) {
		cout << '>';
	}
	else if (a < b) {
		cout << '<';
	}
	else {
		cout << "==";
	}
	return 0;
}