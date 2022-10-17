#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// A (접수 창구) , B (정비 창구) 순서대로 구현해줘야함
//jungjunb 구현 단계
// 1. 시간과 일치하는 고객있으면 wait_a에 넣기
// 2. 빈 접수 창구가 있으면 고객 채워넣기
// 3. 시간이 다된 고객이 있으면 접수창구에서 빼내기 (+ wait_b 에 넣기)
// 4. 빈 정비 창구가 있으면 고객 채워넣기 (wait_b에 있으면)
// 5. 시간 다된 고객이 있으면 정비 창구에서 빼내기 + 고객 세기
// 6. 접수 + 정비 다 끝낸 고객이 총 고객 수 (K)와 같으면 끝내기)

int N, M, K, A, B;

int info[1002][3];
int a_data[11][3];
int b_data[11][3];

queue <int> wait_a;
queue <int> wait_b;

void jungjub()
{
	int customers = 0;
	int now = 0;
	for (int i = 0; i <= 11; i++)
		a_data[i][1] = -1;
	for (int i = 0; i <= 11; i++)
		b_data[i][1] = -1;
	while (true)
	{
		for (int i = 1; i <= K; i++)
			if (info[i][0] == now)
				wait_a.push(i);

		for (int i = 1; i <= N; i++)
		{
			if (a_data[i][1] == now)
			{
				a_data[i][1] = -1;
				wait_b.push(a_data[i][2]);
			}
		}

		for (int i = 1; i <= N; i++)
		{
			if (wait_a.empty())
				break;
			if (a_data[i][1] == -1)
			{
				a_data[i][1] = a_data[i][0] + now;
				a_data[i][2] = wait_a.front();
				info[a_data[i][2]][1] = i;
				wait_a.pop();
			}
		}

		for (int i = 1;i<=M;i++)
			if (b_data[i][1] == now)
			{
				b_data[i][1] = -1;
				customers++;
			}
		for (int i = 1; i <= M; i++)
		{
			if (wait_b.empty())
				break;
			if (b_data[i][1] == -1)
			{
				b_data[i][1] = b_data[i][0] + now;
				b_data[i][2] = wait_b.front();
				info[b_data[i][2]][2] = i;
				wait_b.pop();
			}
		}
		if (customers == K)
			break;
		now++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M >> K >> A >> B;
		for (int i = 1; i <= N; i++)
			cin >> a_data[i][0];
		for (int i = 1; i <= M; i++)
			cin >> b_data[i][0];
		for (int i = 1; i <= K; i++)
			cin >> info[i][0];
		jungjub();
		int ans = 0;
		for (int i = 1; i <= K; i++)
			if (info[i][1] == A && info[i][2] == B) ans += i;
		if (ans == 0) cout << '#' << tc << " " << -1 << '\n';
		else cout << '#' << tc << ' ' << ans << '\n';
	}
}

//수정할 코드

//#include <iostream>
//#include <queue>
//#include <cstring>
//using namespace std;
//
//// 접수 창구 개수 N, 정비 창구 개수 M, 차량 정비소 방문 고객수 K
//// N개의 ai : i번째 접수 창구에서 고장 접수 처리하는 시간
//// M개의 bi : i번째 정비 창구에서 차량 정비 처리하는 시간
//// K개의 tk : 고객이 방문하는 시간
//
//// 지갑 두고간 고객 이용 접수 창구번호  A, 정비 창구번호 B
//int N, M, K, A, B;
//int jub[11], jung[11], gogek[1001]; // N , M , K
//int ans;
//int used[11][2];
//int Data[1001][2];
//int who[11];
//queue <int> wait_jub;
//queue <int> wait_jung;
//
//void chuli()
//{
//	int time = 0;
//	int idx = 1;
//	while (time < K + 40)
//	{
//		if (!wait_jub.empty() && wait_jub.front() <= time)
//		{
//			for (int i = 1; i <= N; i++)
//			{
//				if (used[i][0] == 0 && wait_jub.front() <= time)
//				{
//					wait_jub.pop();
//					if (who[i] > 0)wait_jung.push(who[i]);
//					who[i] = idx;
//					Data[idx][0] = i;
//					used[i][0] = jub[i];
//					idx++;
//				}
//				else if (used[i][0] > 0) used[i][0]--;
//			}
//		}
//		for (int i = 1; i <= M; i++)
//		{
//			if (used[i][1] == 0 && !wait_jung.empty())
//			{
//				int temp = wait_jung.front();
//				wait_jung.pop();
//				Data[temp][1] = i;
//				used[i][1] = jung[i];
//			}
//			else if (used[i][1] > 0) used[i][1]--;
//		}
//		time++;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int T;
//	cin >> T;
//	for (int tc = 1; tc <= T; tc++)
//	{
//		cin >> N >> M >> K >> A >> B;
//		for (int i = 1; i <= N; i++)
//			cin >> jub[i];
//		for (int i = 1; i <= M; i++)
//			cin >> jung[i];
//		for (int i = 1; i <= K; i++)
//		{
//			cin >> gogek[i];
//			wait_jub.push(gogek[i]);
//		}
//		ans = 0;
//		memset(Data, 0, sizeof(Data));
//		memset(used, 0, sizeof(used));
//		memset(who, 0, sizeof(who));
//		chuli();
//		for (int i = 1; i <= K; i++)
//			if (Data[i][0] == A && Data[i][1] == B) ans += i;
//
//		if (ans == 0) cout << "#" << tc << " " << -1 << '\n';
//		else cout << "#" << tc << " " << ans << '\n';
//	}
//}