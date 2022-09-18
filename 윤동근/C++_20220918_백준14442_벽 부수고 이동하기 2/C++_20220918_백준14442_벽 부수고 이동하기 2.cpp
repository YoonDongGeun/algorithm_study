#include <iostream>
using namespace std;
struct pos {
	int x;
	int y;
	int wall;
};

int N, M, K;
char map[1002][1002];			// 테두리는 숫자2 혹은 문자2로 처리하기 위해 사용.
int visite[1002][1002];
int dy[4] = { 1, 0, -1 ,0 };
int dx[4] = { 0, 1, 0, -1 };
pos Q[11000000];			   //N,M은 최대1000, K는 최대 10 -> 최대 11000000가지보다 작음.
int bfs();


int main()
{
	cin >> N >> M >> K;
	K += 1;
	for (int i = 0; i < N + 2; i++)
	{
		map[i][0] = '2';
		map[i][M+1] = '2';
	}
	for (int i = 0; i < M + 2; i++)
	{
		map[0][i] = '2';
		map[N+1][i] = '2';
	}
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < M+1; j++)
		{
			cin >> map[i][j];
			visite[i][j] = K;
		}
	}
	Q[0].x = 1;
	Q[0].y = 1;
	Q[0].wall = 0;
	visite[1][1] = 0;
	cout <<bfs()<<'\n';
	return 0;
}



int bfs()
{
	int nx, ny, wall, wall2;
	int QL = 0, QR=1, QM;
	int cnt=0;

	while (QL != QR)				//큐의 가장 왼쪽과 오른쪽이 만나면 멈춘다.
	{
		QM = QR;
		cnt++;
		while (QL != QM)			// 만약 큐의 왼쪽이 최근에 추가한 만큼 왔으면 1칸이 끝난것. 다시 추가된 것 만큼 돌아야한다.
		{
			if (Q[QL].x == M && Q[QL].y== N)
			{
				return cnt;
			}
			for (int i = 0; i < 4; i++)
			{
				nx = Q[QL].x+dx[i];
				ny = Q[QL].y+dy[i];
				wall = Q[QL].wall;
				wall2 = wall + 1;

				if (map[ny][nx] == '0')
				{
					if (visite[ny][nx] > wall) // 벽 부셨는데 더 느리면 기록할 필요X 그래서 덮어 씌우기.
					{
						Q[QR].x = nx;
						Q[QR].y = ny;
						Q[QR].wall = wall;
						visite[ny][nx] = wall; //visite에는 벽 부순 횟수를 숫자로 기록.(
						QR++;
					}
				}
				else if (map[ny][nx] == '1' && visite[ny][nx] > wall2) //벽이고, 지금 부수려는 갯수가 최근 부순 갯수보다 작으면 추가.
				{													  
					Q[QR].x = nx;
					Q[QR].y = ny;
					Q[QR].wall = wall2;
					visite[ny][nx] = wall2;
					QR++;
				}

			}
			QL++;
		}

	}

	return -1;
}