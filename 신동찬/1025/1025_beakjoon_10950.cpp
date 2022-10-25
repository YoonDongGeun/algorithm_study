#include <iostream>
using namespace std;

int main() {
	int t, a, b;
	cin >> t ;

	for (t;  t > 0; t -= 1) {
		cin >> a >> b;
		cout << a + b << endl;
	}
	return 0;
}