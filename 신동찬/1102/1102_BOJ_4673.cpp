#include <iostream>
#include <vector>
using namespace std;

int self_n(int n) {
	int new_n;
	new_n = n;

	while (n)
	{
		new_n += n % 10;
		n /= 10;
	}
	
	if (new_n <= 10000) {
		return new_n;
	}
}
	

int main() {
	vector<int> arr(10001, 0);

	for (int i = 1; i < 10001; i++) {
		arr[self_n(i)] = 1;
		
	}
	for (int i = 1; i < 10001; i++) {
		if (!arr[i]) cout << i << "\n";
	}

	return 0;
}