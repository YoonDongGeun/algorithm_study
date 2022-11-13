#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> croa = { "c=", "c-", "d-", "lj", "nj", "s=",};
	string data;
	cin >> data;

	int ans = data.size();

	for (int i = 0; i < data.size() - 1; i++) {
		string temp = data.substr(i, 2);
		if (temp == "z=") {
			if (i > 0 && data[i - 1] == 'd') {
				ans -= 2;
			}
			else
			{
				ans -= 1;
			}
		}
	}

	for (int i = 0; i < data.size()-1; i+=1) {
		string temp = data.substr(i, 2);
		
		for (int j = 0; j < croa.size(); j++) {
			if (temp == croa[j]) {
				ans -=1;
				break;
			}
		}
	}

	cout << ans;
	return 0;
}