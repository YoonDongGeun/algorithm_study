#include <iostream>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	char pos[9] = "possible";
	char imp[11] = "impossible";

	int T;
	std::cin >> T;
	for (int t = 1; t <= T; t++) {
		char L[51][51];
		int N, M;
		std::cin >> N >> M;
		for (int i = 0; i < N; i++) {
			char* sub=new char[M+1];
			std::cin >> sub;
			std::cout << sub;
			for (int j = 0; j < M; j++) {
				L[i][j] = sub[j];

			}
		}
		int can1 = 1, can2 = 1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int s = (i + j) % 2;
				if (s and L[i][j] != '.') {
					continue;
				}
				else if (s == 0 and L[i][j] != '#') {
					continue;
				}
				else { can1 = 0; break; }

			}
			if (can1 == 0) break;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int s = (i + j) % 2;
				if (s and L[i][j] != '#') {
					continue;
				}
				else if (s == 0 and L[i][j] != '.') {
					continue;
				}
				else { can2 = 0; break; }

			}
			if (can2 == 0) break;
		}
		if (can1 or can2) {
			std::cout << "#" << t << " " << pos << "\n";
		}
		else std::cout << "#" << t << " " << imp << "\n";
		
	}
}