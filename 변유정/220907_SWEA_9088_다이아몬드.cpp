#include <iostream>
#include <cstring>
using namespace std;

int T, N, K;
int diamond[10001] = { 0, };
// 개수를 크기에 따라서 배열에 저장

// 개수에 따라서 저장하지말고, 한번에 받아서 정렬후에 해도 좋을것 같다
// (vector 아니면 그냥 배열로)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> K;
		memset(diamond, 0, sizeof(diamond));
		int maxx = -1;
		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			diamond[a]++;
			if (maxx < a) maxx = a;
		}
		int ans = 0;
		if (maxx <= K)
		{
			for (int i = 1; i <= maxx; i++)
				ans += diamond[i];
		}
		else 
		{
			for (int i = 1; i <= maxx - K; i++)
			{
				int temp = 0;
				for (int k = 0; k <= K; k++)
				{
					temp += diamond[i + k];
				}
				if (ans < temp) ans = temp;
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
}

/// 크기에 따라서 비교해보기
/// 반복문 (tc) 안에 들어갈 코드
/// vector <int> v;
/// for (int i = 0;i<N;i++)
///	{
///		int a;
///		cin >> a;
///		v.push_back(a);
/// }
/// sort(v.begin(),v.end());
/// 
/// int cnt = 0;
/// int ans = 0;
/// for (int i = 0;i<N;i++)
/// {
///		for (int j = i+1;j<N;j++)
///		{
///			if (v[j] - v[i] <= K) cnt++;
///			else break;
///		}
///		if (cnt > ans) ans = cnt;
///		cnt = 0;
/// }
/// v.clear();
