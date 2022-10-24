//주사위 세개
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, gold, dice[7]={0,0,0,0,0,0,0};
	cin >> a >> b >> c;

	gold = 0;

	dice[a] += 1;
	dice[b] += 1;
	dice[c] += 1;

	for (int i = 1; i < 7; i++) {
		if (dice[i] == 3) {
			gold = 10000 + (i * 1000);
			break;
		}
		else if (dice[i] == 2) {
			gold = 1000 + (i * 100);
			break;

		}
	}

	if (gold == 0) {
		gold = max({ a,b,c }) * 100;
	}
	
	cout << gold;

	return 0;
}