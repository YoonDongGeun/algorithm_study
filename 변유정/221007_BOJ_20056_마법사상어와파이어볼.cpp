#include <iostream>
#include <vector>
using namespace std;

// 문제 - 구현 시뮬레이션
// 문제 구현 단계
// - move_fireball()
// 1. 격자 상관없이 우선 파이어볼 움직여주기
// 2. 이동 끝난 후, 2개 이상 파이어볼이 있으면 계산!
// 3. 계산 했을 때 질량 == 0 이면 다시 넣어주지 않기
// 4. 질량 0이 아니면 방향에 따라서 다시 넣어주기
// 5. K만큼 반복!

// 맵 안에서 반복한다고 s(속력) 바꿔주지 말기.....(s = s%N)

struct Data
{
	int m, s, d;
};

int N, M, K;
vector <Data> Fireball[52][52];
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

void move_fireball()
{
	// 1단계
	vector <Data> tmp[52][52];
	for (int y = 0;y<N;y++)
		for (int x = 0; x < N; x++)
		{
			if (Fireball[y][x].size() >= 1)
			{
				int k = Fireball[y][x].size();
				while (k--)
				{
					Data temp = Fireball[y][x].back();
					Fireball[y][x].pop_back();
					int ny = y + dy[temp.d] * temp.s;
					int nx = x + dx[temp.d] * temp.s;
					// 1-1. 격자 벗어나면 그만큼 계산해주기
					while (ny >= N) ny -= N;
					while (ny < 0) ny += N;
					while (nx >= N) nx -= N;
					while (nx < 0) nx += N;
					tmp[ny][nx].push_back(temp);
				}
			}
		}
	// 2단계
	for (int y = 0;y<N;y++)
		for (int x = 0; x < N; x++)
		{
			if (tmp[y][x].size() > 1)
			{
				int k = tmp[y][x].size();
				int weight = 0;
				int speed = 0;
				int flag = 0;
				int now = k;
				while(now--)
				{
					Data temp = tmp[y][x].back();
					tmp[y][x].pop_back();
					weight += temp.m;
					speed += temp.s;
					flag += temp.d % 2;
				}
				int p_weight = weight / 5;
				int p_speed = speed / k;
				// 3단계
				if (p_weight == 0) continue;
				// 4단계
				for (int i = 0; i < 4; i++)
				{
					// 모두 짝수,홀수 or 아님에 따라서 나누기
					if (flag == 0 || flag == k) tmp[y][x].push_back({ p_weight,p_speed,i * 2 });
					else tmp[y][x].push_back({ p_weight,p_speed,i * 2 + 1 });
				}
			}
		}
	// 5. 다시 세팅해주기
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			for (int i = 0; i < tmp[y][x].size(); i++)
				Fireball[y][x].push_back(tmp[y][x][i]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		Fireball[r-1][c-1].push_back({ m,s,d });
	}
	while (K--)
		move_fireball();
	
	int ans = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			for (int i = 0; i < Fireball[y][x].size(); i++)
				ans += Fireball[y][x][i].m;
	cout << ans;
}