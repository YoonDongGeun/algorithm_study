#include <iostream>

using namespace std;

int N, M;
int map[1000][1000];
int dy[4] = { 1, 0, -1 ,0 };
int dx[4] = { 0, 1, 0, -1 };
int max1 = 1000000000;
int visite[1000][1000];
int temp_y[1000000];
int temp_x[1000000];
int temp_y2[1000000];
int temp_x2[1000000];
void bfs2(int x, int y);
void bfs(int x, int y);
int *storex = &temp_x2[0];
int *storey = &temp_y2[0];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin.get();						/*버리는 것*/
		for (int j = 0; j < M; j++)
		{
			map[i][j] = cin.get() - '0'; /* int형으로 받으려고 '0'을 뻇다.*/
			visite[i][j] = 0;
		}
	}
	int x = 0, y = 0;
	visite[0][0] = 1;
	bfs(0, 0);							/* 순환 */
	if (map[N - 1][M - 1] == 1)		    /*만약 도착지점이 돌이면 어처피 부셔야함 생략.*/
	{

	}
	else
	{
		visite[N - 1][M - 1] = 1;	/*도착지점 돌 아니면 도착지점에서 거꾸로 돌기*/
		map[N - 1][M - 1] = 2;		/*이때, 기존 탐색 안하기 위해 지난곳 map 2로 바꿈*/
		bfs2(M - 1, N - 1);		    /* 거꾸로 탐색*/
		for (int i = 0; i < storex - temp_x2; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int ny = temp_y2[i] + dy[j]; /*temp_y2, temp_x2에 색칠한 돌들 위치 저장*/
				int nx = temp_x2[i] + dx[j]; /*그 돌의 상하좌우에서 지나간길 값 더해서 작은값 반환*/
				if (map[ny][nx] == 2 && visite[ny][nx] + visite[temp_y2[i]][temp_x2[i]]<max1)
					max1 = visite[ny][nx] + visite[temp_y2[i]][temp_x2[i]];
			}
		}
	}

	if (max1 == 1000000000)
		cout << -1 << endl;
	else
		cout << max1;
	return 0;
}





void bfs2(int x, int y)
{
	int nx, ny;
	int *cntx = &temp_x[1];
	int *cnty = &temp_y[1];
	int *cntxe = &temp_x[1];
	int *cntye = &temp_y[1];
	*cntx = x;
	*cnty = y;
	while (cntx - cntxe != 1)/*bfs 시행*/
	{
		if (max1 <= visite[*cntye][*cntxe])
			break;

		for (int i = 0; i < 4; i++)
		{
			ny = *cnty + dy[i];
			nx = *cntx + dx[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N)
			{
				if (map[ny][nx] == 0)
				{
					map[ny][nx] = 2; /*지나간길 2로 색칠해서 다시 탐색 안돼게.*/
					cntye++;
					cntxe++;
					*cntxe = nx;
					*cntye = ny;
					visite[ny][nx] = visite[*cnty][*cntx] + 1;

				}

			}
		}
		cntx++;
		cnty++;
	}
}

void bfs(int x, int y)
{
	int nx, ny;
	int *cntx = &temp_x[1];
	int *cnty = &temp_y[1];
	int *cntxe = &temp_x[1];
	int *cntye = &temp_y[1];
;
	*cntx = x;
	*cnty = y;

	while (cntx - cntxe != 1)/*bfs 시행*/
	{
		if (*cntx == M - 1 && *cnty == N - 1)
		{
			max1 = visite[*cnty][*cntx];
			break;
		}
		else
		{
			for (int i = 0; i < 4; i++) 
			{
				ny = *cnty + dy[i];
				nx = *cntx + dx[i];
				if (0 <= nx && nx < M && 0 <= ny && ny < N)
				{
					if (map[ny][nx] == 0)
					{
						if (visite[ny][nx] == 0)
						{
							cntye++;
							cntxe++;
							*cntxe = nx;
							*cntye = ny;
							visite[ny][nx] = visite[*cnty][*cntx] + 1; 
						}
					}
					else /* 만약 가고자하는 방향  돌이면*/
					{

						if (visite[ny][nx] == 0) /*돌에 몇번째에 지났는지 적고, 그값들 저장*/
						{
							visite[ny][nx] = visite[*cnty][*cntx] + 1;
							*storex = nx;
							*storey = ny;
							storex++;
							storey++;
						}

					}
				}

			}
		}
		cntx++;
		cnty++;
	}
}