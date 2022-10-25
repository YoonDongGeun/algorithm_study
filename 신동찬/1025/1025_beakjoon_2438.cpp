#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k = i;
		while (k)
		{
			cout << "*";
			k -= 1;
		}
		cout << "\n";
	}
	return 0;
}