#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 조합으로 BFS로 돌리는 방식
// 순서
// 1. main 조합 길이 정하기
// 2. comb 조합 생성
// 3. bfs 돌려서 이게 맞는 조합인지 (연결되어서 진행될 수 있는 조합인지 확인)
// 4. 맞는 조합이면 comb 로 돌아가서 ans의 최솟값 업데이트
//
// 벡터 큐 사용 안하고 배열로만 풀려고 했는데 자꾸 실패... 다시 도전!

int N, people[11], Edge[11][11] = { 0, };
int result = 0;
int ans = 1e9;
int used[11] = { 0, };
int flag;

void small()
{
	// 0, 1로 그룹 나눔
	vector<int> group1, group2;
	queue <int> q;
	int used_2[11] = { 0, };

	for (int i = 1; i <= N; i++)
	{
		if (used[i]) group1.push_back(i);
		else group2.push_back(i);
	}
	q.push(group1[0]);
	used_2[group1[0]] = 1;
	int cnt = 1;

	// 1 그룹 - 벡터에 있는데 아직 더해주지 않는 것 찾기
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (Edge[temp][i] == 1)
			{
				if (find(group1.begin(), group1.end(), i) != group1.end())
				{
					if (used_2[i] == 0)
					{
						cnt++;
						used_2[i] = 1;
						q.push(i);
					}
				}
			}
		}
	}
	// 값이 같으면 0그룹 확인, 아니면 틀린 표시 (flag)
	if (cnt != group1.size()) flag = 0;

	// 0 그룹
	cnt = 1;
	q.push(group2[0]);
	used_2[group2[0]] = 1;

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (Edge[temp][i] == 1)
			{
				if (find(group2.begin(), group2.end(), i) != group2.end())
				{
					if (used_2[i] == 0)
					{
						cnt++;
						used_2[i] = 1;
						q.push(i);
					}
				}
			}
		}
	}
	if (cnt != group2.size()) flag = 0;
}

void comb(int cnt, int now,int start)
{
	if (now == cnt)
	{
		flag = 1;
		small();
		if (flag)
		{
			int ret1 = 0;
			int ret2 = 0;
			for (int i = 1; i <= N; i++)
			{
				if (used[i]) ret1 += people[i];
				else ret2 += people[i];
			}
			ans = min(ans, abs(ret1 - ret2));
		}
		return;
	}

	for (int i = start; i <= N; i++)
	{
		if (used[i]) continue;
		used[i] = 1;
		comb(cnt, now + 1,i);
		used[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> people[i];

	for (int i = 1; i <= N; i++)
	{
		int cnt;
		cin >> cnt;
		for (int k = 0; k < cnt; k++)
		{
			int temp;
			cin >> temp;
			Edge[i][temp] = 1;
			Edge[temp][i] = 1;
		}
	}

	for (int i = 1; i <= N/2; i++)
	{
		comb(i, 0,1);
		if (ans == 0) break;
	}
	if (ans == 1e9) cout << -1;
	else cout << ans;
}

//길이 작은 코드
//#include <stdio.h>
//#include <string.h>
//int N, Pop[12];
//int NumConnected[12];
//int V[12];
//int Map[12][12];
//int grp[12];
//int total, p_grp[2];
//void dfs(int s, int grp_n) {
//	for (int i = 1; i <= NumConnected[s]; ++i) {
//		int n = Map[s][i];
//		if (V[n] || grp[n] != grp_n)	continue;
//		V[n] = 1;
//		p_grp[grp_n] += Pop[n];
//		dfs(n, grp_n);
//	}
//}
//int main() {
//	int ret = 987654321;
//	scanf("%d", &N);
//	for (int i = 1; i <= N; ++i) {
//		scanf("%d", &Pop[i]);
//		total += Pop[i];
//	}
//	for (int i = 1; i <= N; ++i) {
//		scanf("%d", &NumConnected[i]);
//		for (int j = 1; j <= NumConnected[i]; ++j)
//			scanf("%d", &Map[i][j]);
//	}
//	int max_i = (1 << N) - 1;
//	for (int i = 1; i < max_i; ++i) {
//		int s0, s1;
//		memset(grp, 0, sizeof(grp));
//		for (int j = 0; j < N; ++j) {
//			int tmp = 1 << j;
//			tmp = tmp & i;
//			p_grp[0] = p_grp[1] = 0;
//			memset(V, 0, sizeof(V));
//			if (tmp) {
//				grp[j + 1] = 1;
//				s1 = j + 1;
//			}
//			else	s0 = j + 1;
//		}
//		V[s0] = 1;
//		p_grp[0] = Pop[s0];
//		dfs(s0, 0);
//
//		V[s1] = 1;
//		p_grp[1] = Pop[s1];
//		dfs(s1, 1);
//
//		int ans = 987654321;
//		if (p_grp[0] + p_grp[1] == total) {
//			ans = p_grp[0] - p_grp[1];
//			if (ans < 0)	ans *= -1;
//			ret = ret < ans ? ret : ans;
//		}
//	}
//	if (ret == 987654321)	printf("-1");
//	else	printf("%d", ret);
//}