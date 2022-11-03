- 합승 택시 요금

darklight

sublimevimemacs

C++ 

###### 문제 설명

**[본 문제는 정확성과 효율성 테스트 각각 점수가 있는 문제입니다.]**

밤늦게 귀가할 때 안전을 위해 항상 택시를 이용하던 `무지`는 최근 야근이 잦아져 택시를 더 많이 이용하게 되어 택시비를 아낄 수 있는 방법을 고민하고 있습니다. "무지"는 자신이 택시를 이용할 때 동료인 `어피치` 역시 자신과 비슷한 방향으로 가는 택시를 종종 이용하는 것을 알게 되었습니다. "무지"는 "어피치"와 귀가 방향이 비슷하여 택시 합승을 적절히 이용하면 택시요금을 얼마나 아낄 수 있을 지 계산해 보고 "어피치"에게 합승을 제안해 보려고 합니다.

![2021_kakao_taxi_01.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/715ff493-d1a0-44d8-9273-a785280b3f1e/2021_kakao_taxi_01.png)

위 예시 그림은 택시가 이동 가능한 반경에 있는 6개 지점 사이의 이동 가능한 택시노선과 예상요금을 보여주고 있습니다.  
그림에서 `A`와 `B` 두 사람은 출발지점인 4번 지점에서 출발해서 택시를 타고 귀가하려고 합니다. `A`의 집은 6번 지점에 있으며 `B`의 집은 2번 지점에 있고 두 사람이 모두 귀가하는 데 소요되는 예상 최저 택시요금이 얼마인 지 계산하려고 합니다.

- 그림의 원은 지점을 나타내며 원 안의 숫자는 지점 번호를 나타냅니다.
  - 지점이 n개일 때, 지점 번호는 1부터 n까지 사용됩니다.
- 지점 간에 택시가 이동할 수 있는 경로를 간선이라 하며, 간선에 표시된 숫자는 두 지점 사이의 예상 택시요금을 나타냅니다.
  - 간선은 편의 상 직선으로 표시되어 있습니다.
  - 위 그림 예시에서, 4번 지점에서 1번 지점으로(4→1) 가거나, 1번 지점에서 4번 지점으로(1→4) 갈 때 예상 택시요금은 `10`원으로 동일하며 이동 방향에 따라 달라지지 않습니다.
- 예상되는 최저 택시요금은 다음과 같이 계산됩니다.
  - 4→1→5 : `A`, `B`가 합승하여 택시를 이용합니다. 예상 택시요금은 `10 + 24 = 34`원 입니다.
  - 5→6 : `A`가 혼자 택시를 이용합니다. 예상 택시요금은 `2`원 입니다.
  - 5→3→2 : `B`가 혼자 택시를 이용합니다. 예상 택시요금은 `24 + 22 = 46`원 입니다.
  - `A`, `B` 모두 귀가 완료까지 예상되는 최저 택시요금은 `34 + 2 + 46 = 82`원 입니다.

---

#### **[문제]**

지점의 개수 n, 출발지점을 나타내는 s, `A`의 도착지점을 나타내는 a, `B`의 도착지점을 나타내는 b, 지점 사이의 예상 택시요금을 나타내는 fares가 매개변수로 주어집니다. 이때, `A`, `B` 두 사람이 s에서 출발해서 각각의 도착 지점까지 택시를 타고 간다고 가정할 때, 최저 예상 택시요금을 계산해서 return 하도록 solution 함수를 완성해 주세요.  
만약, 아예 합승을 하지 않고 각자 이동하는 경우의 예상 택시요금이 더 낮다면, 합승을 하지 않아도 됩니다.

#### **[제한사항]**

- 지점갯수 n은 3 이상 200 이하인 자연수입니다.
- 지점 s, a, b는 1 이상 n 이하인 자연수이며, 각기 서로 다른 값입니다.
  - 즉, 출발지점, `A`의 도착지점, `B`의 도착지점은 서로 겹치지 않습니다.
- fares는 2차원 정수 배열입니다.
- fares 배열의 크기는 2 이상 `n x (n-1) / 2` 이하입니다.
  - 예를들어, n = 6이라면 fares 배열의 크기는 2 이상 15 이하입니다. (`6 x 5 / 2 = 15`)
  - fares 배열의 각 행은 [c, d, f] 형태입니다.
  - c지점과 d지점 사이의 예상 택시요금이 `f`원이라는 뜻입니다.
  - 지점 c, d는 1 이상 n 이하인 자연수이며, 각기 서로 다른 값입니다.
  - 요금 f는 1 이상 100,000 이하인 자연수입니다.
  - fares 배열에 두 지점 간 예상 택시요금은 1개만 주어집니다. 즉, [c, d, f]가 있다면 [d, c, f]는 주어지지 않습니다.
- 출발지점 s에서 도착지점 a와 b로 가는 경로가 존재하는 경우만 입력으로 주어집니다.

---

##### **[입출력 예]**

| n   | s   | a   | b   | fares                                                                                                       | result |
| --- | --- | --- | --- | ----------------------------------------------------------------------------------------------------------- | ------ |
| 6   | 4   | 6   | 2   | [[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]] | 82     |
| 7   | 3   | 4   | 1   | [[5, 7, 9], [4, 6, 4], [3, 6, 1], [3, 2, 3], [2, 1, 6]]                                                     | 14     |
| 6   | 4   | 5   | 6   | [[2,6,6], [6,3,7], [4,6,7], [6,5,11], [2,5,12], [5,3,20], [2,4,8], [4,3,9]]                                 | 18     |

##### **입출력 예에 대한 설명**

---

**입출력 예 #1**  
문제 예시와 같습니다.

**입출력 예 #2**  
![2021_kakao_taxi_02.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/934fcb5a-f844-4b02-b7fa-46198123be05/2021_kakao_taxi_02.png)

- 합승을 하지 않고, `B`는 `3→2→1`, `A`는 `3→6→4` 경로로 각자 택시를 타고 가는 것이 최저 예상 택시요금입니다.
- 따라서 최저 예상 택시요금은 `(3 + 6) + (1 + 4) = 14`원 입니다.

**입출력 예 #3**  
![2021_kakao_taxi_03.png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/179cc8ad-73d2-46c9-95e9-2363f3cb345d/2021_kakao_taxi_03.png)

- `A`와 `B`가 `4→6` 구간을 합승하고 `B`가 6번 지점에서 내린 후, `A가`6→5` 구간을 혼자 타고 가는 것이 최저 예상 택시요금입니다.
- 따라서 최저 예상 택시요금은 `7 + 11 = 18`원 입니다.

## 나의 코드

```c
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
```

![](C++_20221103_[PG]2021%20KAKAO%20BLIND%20RECRUITMENT_합승%20택시%20요금assets/2022-11-03-23-52-18-image.png)

오랜만에 다익스트라를 써보느라 애먹었다. 그리고 무엇보다 priority queue를 쓰고 싶어서 자료를 찾아보는데 너무 복잡해 보여서 거의 따라치듯이 했다. 그냥 queue에서도 우선순위 큐를 그냥 <int,int>로 하여 쉽게 쓸수 있다고 알고 있는데, 그래도 많이 아는게 낫다고 생각하여 찾아가며 구현해 보았다. 좀더 vector나 queue에 대해서 익숙해져야하고 명령어를 다시한번 살펴봐야할 거 같다.
