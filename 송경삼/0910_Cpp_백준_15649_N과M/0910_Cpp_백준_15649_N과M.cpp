#include <iostream>
#include <vector>

int L[9]{};
bool v[9];
std::vector<int> ans;
int c, N, M;

void back_track(int c) {
	if (c == M) {
		for (int j = 0; j< ans.size(); j++) {
			std::cout << ans[j] << " ";
		}
		std::cout << "\n";		
	}
	else {
		for (int i = 0; i < N; i++) {
			if (v[i]) continue;
			v[i] = 1;
			ans.push_back(L[i]);
			back_track(c + 1);
			ans.pop_back();
			v[i] = 0;

		}
	}
}
 


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie();
	std::cout.tie();
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		L[i] = i + 1;
		v[i] = 0;

	}

	back_track(0);
}