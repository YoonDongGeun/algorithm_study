#include <iostream>


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int T;
	std::cin >> T;
	for (int i = 1; i <= T;i++) {
		int ans=0;
		char ip[50];
		std::cin >> ip;
		for (int j = 1; ip[j] != '\0'; j++) {
			if ((ip[j - 1] == '|' and ip[j] == ')') or (ip[j - 1] == '(' and (ip[j] == ')' or ip[j] == '|'))) {
				ans += 1;
			}
		}
		std::cout << "#"<<i<<" "<< ans << "\n";
	}



}
