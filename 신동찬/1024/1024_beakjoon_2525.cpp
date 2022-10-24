// ¿Àºì½Ã°è
#include <iostream>
using namespace std;

int main() {
	int h, m, cook;
	cin >> h >> m >> cook;
	m += cook;
	
	h += m / 60;
	m %= 60;
	h = (h > 23) ? h -= 24 : h;

	cout << h << ' ' << m;
	return 0;
}