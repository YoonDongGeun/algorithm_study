#include <iostream>
#include <vector>
using namespace std;

// 알고리즘 분류 : 수학, 애드 혹
// 애드 혹 : 정형화된 알고리즘을 적용하는 것이 아니라 해당 문제만을 위한 창의적인 아이디어를 찾아서 문제 해결

// 참고 코드 출처 : https://justicehui.github.io/koi/2019/03/17/BOJ14864/
// 위코드 : 100점
// 아래코드 : 7점

// 위코드 구현 단계 (숫자 더하고 빼기)
// 1. 우선 배열에 같은 인덱스만큼 숫자 부여 (인덱스 1 - 1, 2 - 2 ...)
// 2. M 만큼의 순서쌍이 들어왔을 때, 앞 숫자 인덱스 ++, 뒤 숫자 인덱스 --
// 3. 배열 확인 - 
// 3-1. 만약 배열 숫자 중 N을 넘거나 0이하이면 잘못된 숫자 배열
// 3-2. 만약 배열 중 이미 같은 카드의 숫자를 사용했으면 잘못된 숫자 배열

// 아래코드 구현 단계 (숫자 교환)
// 1. 우선 배열에 같은 인덱스만큼 숫자 부여
// 2. M 만큼의 순서쌍이 들어왔을 때, 숫자 서로 바꾸기
// 3. 배열 확인
// 3-1. 만약 바꾼 숫자와 맞지 않는 벡터가 있으면 잘못된 숫자 배열

vector <int> box;
int N, M;

void check()
{
	bool used[100001] = { 0, };
	for (int i = 1; i <= N; i++)
	{
		if (box[i] > N || box[i] <= 0)
		{
			cout << -1;
			exit(0);
		}
		if (used[box[i]])
		{
			cout << -1;
			exit(0);
		}
		used[box[i]] = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	box.resize(N + 1);

	for (int i = 1; i <= N; i++)
		box[i] = i;

	while (M--)
	{
		int a, b;
		cin >> a >> b;
		box[a]++;
		box[b]--;
	}
	check();
	for (int i = 1; i <= N; i++)
		cout << box[i] << ' ';
}

//int N, M, card[100001];
//vector <int> box[100001];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		box[a].push_back(b);
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		card[i] = i;
//		sort(box[i].rbegin(), box[i].rend());
//	}
//	for (int i = 1; i <= N; i++)
//	{
//		int idx = 0;
//		for (int k = N; k>= i ; k--)
//		{
//			if (idx != box[i].size() && box[i][idx] == k)
//			{
//				idx++;
//				if (card[i] < card[k])
//				{
//					int temp = card[i];
//					card[i] = card[k];
//					card[k] = temp;
//				}
//			}
//			else
//			{
//				if (card[i] > card[k])
//				{
//					int temp = card[i];
//					card[i] = card[k];
//					card[k] = temp;
//				}
//			}
//		}
//	}
//	bool flag = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		int idx = 0;
//		for (int k = N; k > i; k--)
//		{
//			if (card[i] > card[k])
//			{
//				if (box[i][idx] == k)
//					idx++;
//				else
//				{
//					flag = 1;
//					break;
//				}
//			}
//		}
//		if (flag == 1) break;
//	}
//
//	if (flag == 0)
//	{
//		for (int i = 1; i <= N; i++)
//			cout << card[i] << " ";
//	}
//	else cout << -1;
//}