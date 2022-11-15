#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int cnt = 0;
	int t = N;
	while (t)
	{
		vector<char> arr;
		string word;
		cin >> word;

		int flag = 0;
		arr.push_back(word[0]);

		for (int i = 1; i < word.length(); i++) {
			
			// 직전에 검사한 문자랑 현재 문자랑 다른 경우에 진입
			if (arr[arr.size() - 1] != word[i]) {

				// 현재까지 검사한 문자열을 돌면서 같은 문자있는지 체크
				for (int j = 0; j < arr.size()-1; j++) {

					// 같은 문자 있으면 카운트
					if (arr[j] == word[i]) {
						flag = 1;
						break;
					}
				}
			}

			if (flag) {
				cnt++;
				break;
			}
			else {
				arr.push_back(word[i]);
			}

		}
		t--;
	}
	cout << N-cnt;
	return 0;
}