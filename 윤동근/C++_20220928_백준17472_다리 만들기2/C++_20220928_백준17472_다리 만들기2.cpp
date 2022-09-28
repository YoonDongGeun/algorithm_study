#include<iostream>
struct pos {
	int y;
	int x;
};

// 섬을 엣지로 만들기.
// 섬간의 지을수 있는 다리를 노드로 만들기
//

int main(void)
{
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	int N, M, num, ny, nx, flag, cnt;
	int MAP[10][10] = { 0, };
	int visited[10][10] = { 0, };
	int visited_node[7] = { 0, };
	int GP[7][7];
	pos now[100];
	pos *n, *s;
	int min, minnode , ans;
	std::cin >> N >> M;
	num = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)  //맵 입력
		{
			std::cin >> MAP[i][j];
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)   // 섬 번호 만들기
		{
			if (MAP[i][j] && !visited[i][j])
			{
				MAP[i][j] = num;
				visited[i][j] = 1;
				n = now+1;
				s = now;
				*s = { i,j };
				while (s != n)
				{
					for (int k = 0; k < 4; k++)
					{

						ny = (*s).y + dy[k];
						nx = (*s).x + dx[k];
						
						if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx])
						{
							if (MAP[ny][nx])
							{
								MAP[ny][nx] = num;
								visited[ny][nx] = 1;
								(*n).y = ny;
								(*n).x = nx;
								++n;
							}
							else
							{
								visited[(*s).y][(*s).x] = 2;
							}
						}
					}
					++s;
				}
				++num;
			}
		}
	for (int i = 1; i < num; i++)
		for (int j = 1; j < num; j++)
			GP[i][j] = 10;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)   // 노드 만들기
		{
			if (visited[i][j] == 2)   // 옆에 물인 곳 탐색
			{
				for (int k = 0; k < 4; k++)
				{
					ny = i + dy[k];
					nx = j + dx[k];
					if (0 <= ny && ny < N && 0 <= nx && nx < M && !MAP[ny][nx]) // 가는 방향 물이다.
					{
						cnt = 0;
						if (k == 0) // y축 +방향
						{
							for (int L = 2; L < N-i; L++)
							{
								
								ny += dy[k];
								cnt++;                                            //다리길이 cnt
								if (MAP[ny][nx]) //만약 육지라면
								{
									if (GP[MAP[i][j]][MAP[ny][nx]] > cnt && cnt>1)  //다리길이 1 초과면 넣기.
									{
										GP[MAP[i][j]][MAP[ny][nx]] = cnt;
										GP[MAP[ny][nx]][MAP[i][j]] = cnt;
									}
									break;
								}
							}
						}
						else if (k == 1) // x축 +방향으로 다리 건설
						{


							for (int L = 2; L < M - j; L++)
							{
								nx += dx[k];
								cnt++;

								if (MAP[ny][nx])
								{
									if (GP[MAP[i][j]][MAP[ny][nx]] > cnt  && cnt > 1)
									{
										GP[MAP[i][j]][MAP[ny][nx]] = cnt;
										GP[MAP[ny][nx]][MAP[i][j]] = cnt;
									}
									break;
								}
							}

						}
						else if (k == 2) //y축 -방향
						{
							for (int L = 1; L < i; L++)
							{
								ny += dy[k];
								cnt++;
								if (MAP[ny][nx])
								{
									if (GP[MAP[i][j]][MAP[ny][nx]] > cnt  && cnt > 1)
									{
										GP[MAP[i][j]][MAP[ny][nx]] = cnt;
										GP[MAP[ny][nx]][MAP[i][j]] = cnt;
									}
									break;
								}
							}
						}
						else   // x축 -방향
						{

							for (int L = 1; L < j; L++)
							{
								nx += dx[k];
								cnt++;
								
								if (MAP[ny][nx])
								{
									
									if (GP[MAP[i][j]][MAP[ny][nx]] > cnt  && cnt > 1)
									{
										GP[MAP[i][j]][MAP[ny][nx]] = cnt;
										GP[MAP[ny][nx]][MAP[i][j]] = cnt;
									}
									break;
								}
							}


						}
					}
				}
			}
		}
	//위에까지 노드 만들기 완료.
	for (int i = 1; i < 7; i++) //자기 자신으로 노드가 오는것들 없애기.
	{
		GP[i][i] = 10;
	}

	visited_node[1] = 1;
	ans = 0;
	for (int i = 1; i < num-1; i++) // 노드-1 개만큼 시행
	{
		min = 10;
		minnode = 0;
		for (int j = 1; j < num; j++) // 노드 1번부터 num-1번까지 탐색하며 연결된 노드들중 가장 작은거 탐색
		{
			if (visited_node[j])
			{
				for (int k = 1; k < num; k++)  // 방문했던 노드이면 최소값 찾아보기.
				{
					if (!visited_node[k] && min>GP[j][k])
					{
						min = GP[j][k];
						minnode = k;
					}
				}
			}
		}
		//여기까지 오면 노드 탐색 i회 완료
		if (minnode == 0) {   // 만약 노드 더이상 못찾았으면 break
			ans = -1;
			break;
		}
		else  //만약 찾았으면
		{
			visited_node[minnode] = 1;
			ans += min;
		}
	}
	std::cout << ans;
	return 0;

}
