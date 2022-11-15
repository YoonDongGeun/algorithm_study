#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	// 봉지 개수가 적으려면, 5kg짜리를 가장 많이 사용한 case를 찾으면 된다.
	// 따라서, 5kg짜리를 최대로 쓰는 케이스부터 하나씩 줄여가며 보면 되겠지.
	int n;
	cin >> n;

	int cnt_5, cnt_3, res_5;

	cnt_5 = n / 5;
	res_5 = n % 5;	

	while (res_5 % 3 != 0 && cnt_5 != 0)	{
		cnt_5-=1;	
		res_5 = n - (cnt_5 * 5);
	}

	int ans = (res_5 % 3 == 0) ? cnt_5 + res_5 / 3 : -1;

	cout << ans;

	return 0;
}