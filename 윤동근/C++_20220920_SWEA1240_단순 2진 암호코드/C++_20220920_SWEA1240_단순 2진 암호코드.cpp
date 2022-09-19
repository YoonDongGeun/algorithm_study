#include <iostream>
using namespace std;
struct pos {
	int x;
	int y;
};


int N, M;
char map[1002][1002];			// 테두리는 숫자2 혹은 문자2로 처리하기 위해 사용.
int visite[1002][1002];
int dy[4] = { 1, 0, -1 ,0 };
int dx[4] = { 0, 1, 0, -1 };
int const recovery = 1 << 19;  // 2^20이면 약 100만개
pos Q[recovery];			   //N,M은 최대1000, K는 최대 10 -> 최대 11000000가지보다 작음.
pos list[50000];
void bfs(int x, int y);
char a;


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N + 2; i++)
	{
		map[i][0] = '0'-1;
		map[i][M + 1] = '0'-1;
	}
	for (int i = 0; i < M + 2; i++)
	{
		map[0][i] = '0'-1;
		map[N + 1][i] = '0'-1;
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '1')
				visite[i][j] = 2;
			else
				visite[i][j] = 0;
		}
	}

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			if (visite[i][j] == 0)
				bfs(i,j);
		}
	}
	
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}



void bfs(int y, int x)
{
	pos *wall = list;
	int nx, ny;
	int QL = 0, QR = 1, QM;
	int cnt = 1;
	Q[0].x = x;
	Q[0].y = y;
	visite[y][x] = 1;
	while (QL != QR)				//큐의 가장 왼쪽과 오른쪽이 만나면 멈춘다.
	{
		QM = QR;
		while (QL != QM)			// 만약 큐의 왼쪽이 최근에 추가한 만큼 왔으면 1칸이 끝난것. 다시 추가된 것 만큼 돌아야한다.
		{
			for (int i = 0; i < 4; i++)
			{
				nx = Q[QL].x + dx[i];
				ny = Q[QL].y + dy[i];

				if (map[ny][nx] == '0' && visite[ny][nx]==0)
				{
					Q[QR].x = nx;
					Q[QR].y = ny;
					visite[ny][nx] = 1; //visite에 방문 여부 기록.
					QR++;
					QR &= ~recovery;
					cnt++;
				}
				else if (visite[ny][nx] == 2)   //벽은 visited 기본값2
				{
					visite[ny][nx] = 1; 
					(*wall).x = nx;
					(*wall).y = ny;
					wall++;                      //wall은 list의 주소값을 가리킨다. list에 1개씩 벽들 저장.
				}

			}
			QL++;
			QL &= ~recovery; // QL도 꽉차면 초기화 해준다.
		}
	}
	while (wall - list)						// 저장한 벽들 10나눈 나머지 더한뒤에 10 넘으면 또 10나눈 나머지 값 가지게 만들기.
	{
		wall--;
		visite[(*wall).y][(*wall).x] = 2;
		cnt %= 10;
		map[(*wall).y][(*wall).x] += cnt;
		if (map[(*wall).y][(*wall).x] > '9')
			map[(*wall).y][(*wall).x] -= 10;
	}

}

