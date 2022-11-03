#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct pos { //자료구조 pos
	int fare;
	int go;
	pos(int far, int g) : fare(far), go(g) {}
};

struct cmp{ //우선순위 큐에 적용할 비교함수. fare값이 더 큰 친구가 인덱스 큼.
	bool operator()(pos a, pos b)
	{
		return a.fare > b.fare;
	}
};

priority_queue<pos, vector<pos>, cmp> diks; //diks라는 우선순위 큐 구현.

void dikstra(int n, int from, vector<vector<int>> &fares, vector<int> &visited) {//n번구역에서 모든 점까지의 최소 거리 구하기.
	diks.push(pos(0, from)); //시작지점 from(s, a, b 중 1개로 시작)에서 비용 0 으로 시작.
	int now, fare;
	while (!diks.empty())
	{
		now = diks.top().go;
		fare = diks.top().fare;
		diks.pop();
		if (visited[now] > fare) {
			visited[now] = fare;
		}
		else//큐데 담은게 이미 방문한 지점보다 더 크면 넘어가기.
		{
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			if (fares[now][i])
			{
				diks.push(pos(fare+fares[now][i], i));
			}
		}

	}

}



int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 200000051;//최대값으로 정답 시작.
	vector<vector<int>> nodes(n + 1, vector<int>(n + 1, 0));
	vector<int> visiteds(n + 1, 200000050); // n개의 구역에 비용 최대값 보다 훨씬 크게 넣기.
	vector<int> visiteda(n + 1, 200000050);
	vector<int> visitedb(n + 1, 200000050);
	for (int i = 0; i < fares.size(); i++) //fare벡터를 nodes로 만들어 비용 정리.
	{
		nodes[fares[i][0]][fares[i][1]] = fares[i][2];
		nodes[fares[i][1]][fares[i][0]] = fares[i][2];
	}
	dikstra(n, s, nodes, visiteds); //a,b,s 를 시작점으로 할때 각 구역까지의 최소 비용 구하기.
	dikstra(n, a, nodes, visiteda);
	dikstra(n, b, nodes, visitedb);
	int temp;
	for (int i = 1; i <= n; i++)
	{
		temp = visiteds[i] + visiteda[i] + visitedb[i];
		if (answer > temp)// 각 구역에서 s,a,b까지 가는 비용 최소값 구하기.
		{
			answer = temp;
		}
	}
	//모든 점에서 a, b, s 에 대한 비용 계산한 결과값 answer에 최소값이 들어감.
	return answer;
}