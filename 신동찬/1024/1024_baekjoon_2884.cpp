// 알람 시계
#include <iostream>
using namespace std;

int main() {
	int h, m;
	cin >> h >> m;

	if (m < 45) {
		m = m + 60 - 45;
		h = (h == 0) ? 23 : h - 1;
	}
	else {
		m -= 45;
	}
	cout << h << ' ' << m;
	
	return 0;
}

// <<조건 표현식>>
// (조건) ? a : b;
// 조건이 참이면 a반환, 거짓이면 b반환