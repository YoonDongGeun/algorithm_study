#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 알고리즘 : 트리, 깊이 우선 탐색
// 위 : 트리 구조 활용한 dfs (100) / 아래 : dfs (13)
// 참고 : https://jeongboclass.tistory.com/163?category=1061898
// 참고 : https://saywoo.tistory.com/12

int N, Q, M;
vector <int> vect[250001], tree[250001];
int used[250001], check[250001], treeparent[250001];
// used - Q기록 남기기용
// check - tree 구조 만들때, 사용한 노드인지 확인하기용
// treeparent - 노드의 부모 남기기
long long ans; // 최대 ans = 250000 ^ 2
int leaf[250001], parent[250001];
long long cnt[250001];

int find(int p)
{
	if (parent[p] == p) return p; 
	// 여기까지 도달한 건 첫번째 노드(시작부모)
	else return parent[p] = find(parent[p]);
}

void make_tree(int idx)
{
	// 입력받은 그래프를 트리 구조로 만들기
	check[idx] = 1;
	for (int i = 0; i < vect[idx].size(); i++)
	{
		if (check[vect[idx][i]])continue;
		tree[idx].push_back(vect[idx][i]);
		make_tree(vect[idx][i]);
		treeparent[vect[idx][i]] = idx;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int a, b;
	for (int i = 0; i < N -1; i++)
	{
		cin >> a >> b;
		vect[a].push_back(b);
		vect[b].push_back(a);
	}
	make_tree(1);
	cin >> Q;
	for (int i = 1; i <= Q; i++)
	{
		ans = 0;
		cin >> M;
		for (int k = 0; k < M; k++)
		{
			cin >> leaf[k];
			used[leaf[k]] = i;
			cnt[leaf[k]] = 1;
			parent[leaf[k]] = leaf[k]; 
		}
		
		for (int k = 0; k < M; k++)
		{
			if (used[leaf[k]] == i && used[treeparent[leaf[k]]] == i)
			{
				int p = find(leaf[k]);
				int pp = find(treeparent[leaf[k]]);

				// 끝 부모 찾았으면 합쳐주기 (자식을 부모에 합치기)
				cnt[pp] += cnt[p];
				parent[p] = pp;
			}
		}
		
		for (int k = 0; k < M; k++)
			if (parent[leaf[k]] == leaf[k])
				ans += cnt[leaf[k]] * (cnt[leaf[k]] - 1) / 2;

		cout << ans << '\n';
	}
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int N, Q, ans;
//vector <int> vect[250001];
//vector <int> node;
//int flag;
//bool used[250001] = { 0, };
//
//void find_connect(int a, int b)
//{
//	if (a == b)
//	{
//		flag = 1;
//		return;
//	}
//	if (flag == 1) return;
//	for (int i = 0; i < vect[a].size(); i++)
//	{
//		if (used[vect[a][i]]) continue;
//		if (find(node.begin(),node.end(),vect[a][i]) == node.end()) continue;
//		used[vect[a][i]] = 1;
//		find_connect(vect[a][i], b);
//		used[vect[a][i]] = 0;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N;
//	for (int i = 0; i < N - 1; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		vect[a].push_back(b);
//		vect[b].push_back(a);
//	}
//	cin >> Q;
//	int k;
//	for (int i = 0; i < Q; i++)
//	{
//		int cnt;
//		cin >> cnt;
//		for (int j = 0; j < cnt; j++)
//		{
//			cin >> k;
//			node.push_back(k);
//		}
//		ans = 0;
//		if (cnt == 1) cout << ans << '\n';
//		else
//		{
//			for (int j = 0; j < cnt - 1; j++)
//			{
//				for (int k = j + 1; k < cnt; k++)
//				{
//					flag = 0;
//					used[node[j]] = 1;
//					find_connect(node[j], node[k]);
//					used[node[j]] = 0;
//					ans += flag;
//					flag = 0;
//				}
//			}
//			cout << ans << '\n';
//		}
//		node.clear();
//	}
//}