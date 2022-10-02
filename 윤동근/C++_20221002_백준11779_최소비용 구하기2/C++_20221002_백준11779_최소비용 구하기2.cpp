#include <iostream>
int Map[1001][1001];
int nec[500000];

// 전략
// 1. 우선순위 큐 혹은 힙큐를 사용하면 훨씬 빠르게 구할 수 있을 것이다.(여기서는 일반 배열 사용) 
// 2. 가장 낮은 비용을 계속 갱신해야한다. 이때 자기자신으로 0만큼 이동하는 것이 있을 수 있기 때문에 초기화 해준다.
// 3. 다른곳으로 가는데 비용이 0이면 계속 무한루프가 발생할 확률이 있기 때문에 잘 생각해야 한다.
int main(void)
{
	int N, M, st, ed, cost, start, mid, end, nn, nc, cnt;
	int visited[1001] = { 0, };
	int tree[1001];
	std::cin >> N;                         // 마을 수
	std::cin >> M;						   // 버스 경로 수
	for (int i = 1; i <= N; i++)
	{
		tree[i] = i;                       // set를 표현한다. 최소비용일 경우 어디서 어디로 가는지 알 수 있다.
		visited[i] = 100000001;            // 최소 비용 저장할 리스트
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			Map[i][j] = -1;                // 이동 경로들 -1로 초기화
	}

	for (int i = 0; i < M; i++)
	{
		std::cin >> st >> ed >> cost;
		if (Map[st][ed] == -1)
		{
			Map[st][ed] = cost;         // 어디서 어디로 갈때 비용 몇인지 넣어준다
		}
		else
		{
			if (Map[st][ed] > cost)
				Map[st][ed] = cost;
		}
	}
	for (int i = 1; i <= N; i++)        // 변수 받고나서 자기 자신으로 오는거 다 초기화
	{
		Map[i][i] = -1;
	}
	
	std::cin >> st >> ed;
	visited[st] = 0;
	nec[0] = st;
	start = 0, end = 1;
	while (start != end)               // 이제 BFS로 최소비용을 구해본다. (이때 힙큐를 쓰면 훨씬 빠를게 구할 수 있다.)
	{
		mid = end;
		while (start != mid)
		{
			nn = nec[start];
			for (int i = 1; i <= N; i++)
			{
				if (Map[nn][i] >= 0)
				{
					nc = visited[nn] + Map[nn][i];
					if (visited[i] > nc)
					{
						visited[i] = nc;
						tree[i] = nn;
						nec[end] = i;
						end++;
					}
				}
			}
			start++;
		}
	}
	end = ed;
	cnt = 1;
	visited[0] = ed;
	while (tree[end] != end)   //visited 리스트를 임시로 사용하여 노선 순서대로 넣어주기.
	{
		visited[cnt] = tree[end];
		cnt++;
		end = tree[end];
	}
	std::cout << visited[ed] << '\n';   // 비용 얼마인지 출력
	std::cout << cnt << '\n';          // 몇개의 도시 방문했는지 출력
	cnt--;
	while (cnt!=-1)        // 노선 출력
	{
		std::cout << visited[cnt] << ' ';
		cnt--;
	}



	return 0;
}