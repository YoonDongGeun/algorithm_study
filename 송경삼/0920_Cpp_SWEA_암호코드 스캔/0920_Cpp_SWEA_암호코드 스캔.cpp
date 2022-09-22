#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string sub;
int T, tc, N, M, l, r, temp, SUM;
char board[2000][501];
vector<string> secret;
vector<int> secret_key;
string SL[10] = { "0001101","0011001","0010011","0111101", "0100011","0110001", "0101111","0111011", "0110111","0001011" };

bool is_ok() {
	return !((3 * (secret_key[0] + secret_key[2] + secret_key[4] + secret_key[6]) + secret_key[1] + secret_key[3] + secret_key[5] + secret_key[7]) % 10);
}

void is_valid(int i) {
	int n = 0, b = secret[i].size(), C = -1;
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	while (secret[i][--b] == '1') ++c1;
	++c2;
	while (secret[i][--b] == '0') ++c2;
	++c3;
	while (secret[i][--b] == '1') ++c3;
	++c4;
	while (secret[i][--b] == '0') ++c4;
	C = min({ c1,c2,c3,c4 });
	while (secret[i].size() < 8 * 7 * C) {
		secret[i] = '0' + secret[i];
	}
	int a = secret[i].size() - 8 * 7 * C + 1;
	if (a > 1) {
		while (a > 0) {
			if (secret[i][--a] != '0') {
				break;
			}
		}
		if (a > 3) secret.push_back(secret[i].substr(0, a + 1));
		secret[i] = secret[i].substr(secret[i].size() - 8 * 7 * C, 8 * 7 * C);
	}
	sub = "";
	for (int z = 0; z < secret[i].size(); z += C) {
		sub += secret[i][z];
	}
	secret[i] = sub;
}




int main() {
	scanf("%d", &T);
	while (++tc <= T) {
		SUM = 0;
		secret.clear();

		scanf("%d %d", &N, &M);
		cin.ignore();

		for (int n = 0; n < N; ++n) {
			getline(cin, sub);
			strcpy(board[n], sub.c_str());
		}

		for (int i = 0; i < N; ++i) {
			for (l = 0; l < M; ++l) {
				if (board[i][l] != '0') {
					r = M;
					while (--r > l) {
						if (board[i][r] != '0') break;
					}
					secret.push_back(board[i].substr(l, r - l + 1));
					for (int dj = l; dj <= r; ++dj) {
						if (board[i][dj] == '0')continue;
						for (int di = 0; i + di < N; ++di) {
							if (board[i + di][dj] == '0') break;
							board[i + di][dj] = '0';
						}
					}

				}
			}

		}


		for (int i = 0; i < secret.size(); ++i) {
			cout << secret[i] << "\n";
		}

		for (int i = 0; i < secret.size(); ++i) {
			sub = "";
			for (int j = 0; j < secret[i].size(); ++j) {

				if (secret[i][j] >= '0' && secret[i][j] <= '9') {
					temp = secret[i][j] - '0';
				}
				else temp = secret[i][j] - 'A' + 10;
				for (int w = 3; w >= 0; --w) {
					if ((1 << w)&temp) sub += '1';
					else sub += '0';
				}
			}
			while (sub.back() == '0') sub.pop_back();
			secret[i] = sub;
		}

		for (int i = 0; i < secret.size(); ++i) {
			cout << secret[i] << "\n";
		}

		for (int i = 0; i < secret.size(); ++i) {
			is_valid(i);
		}

		for (int i = 0; i < secret.size(); ++i) {
			cout << secret[i] << "\n";
		}
		for (int i = 0; i < secret.size(); ++i) {
			secret_key = { 0,0,0,0,0,0,0,0 };
			for (int j = 0; j < 8; ++j) {
				sub = secret[i].substr(j * 7, 7);
				for (int x = 0; x < 10; ++x) {
					if (sub == SL[x]) {
						secret_key[j] = x;
						break;
					}
				}
			}
			if (is_ok()) {
				SUM += secret_key[0] + secret_key[1] + secret_key[2] + secret_key[3] + secret_key[4] + secret_key[5] + secret_key[6] + secret_key[7];
			}
		}
		printf("#%d %d\n", tc, SUM);
	}

}
