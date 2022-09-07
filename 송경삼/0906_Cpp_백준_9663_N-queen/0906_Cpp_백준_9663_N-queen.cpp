#include <iostream>
#include <vector>

int N, cnt = 0;
std::vector<int> queen;
bool can=1;


void BT(int i) {
	if (i == N) {
		cnt++;
		return;
	}
	else {
		for (int j = 0; j < N; j++) {
			int l = j, r = j;
			for (int k = queen.size()-1; k >=0; k--) {
				if (queen[k] == j || --l == queen[k] || ++r == queen[k]) { can = 0; break; }
			}
			if (can == 0) { can = 1; continue; }
			queen.push_back(j);
			BT(i + 1);
			queen.pop_back();
		}
	}
	return;
}

int main() {
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> N;
	BT(0);
	std::cout << cnt << "\n";
	return 0;
}

