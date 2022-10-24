#include <iostream>
using namespace std;

int main()
{
	int yoon;

	cin >> yoon;

	if (yoon % 4 == 0 && yoon % 100 != 0 || yoon % 400 == 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}