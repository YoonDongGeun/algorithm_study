#include <iostream>

int max(int a, int b);
void search(int horses[], int go, int *cnt, int dice[], int M[]);
int move(int horse, int move);
int ans = 0;


int main(void)
{
	int dice[10];
	int M[22 + 3 + 2 + 3 + 3] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 13,16,19, 22,24,  28,27,26, 25,30,35 };
	int cnt = 0;
	int horses[4] = { 0,0,0,0 };
	// 분기점 index 5, 10, 15;
	for (int i = 0; i < 10; i++)
	{
		std::cin >> dice[i];
	}

	for (int i = 0; i <= 40; i += 2)
	{
		M[cnt++] = i;
	}
	M[cnt] = 0;
	cnt = 0;
	search(horses, 0, &cnt, dice, M);
	std::cout << ans;
	return 0;
}


int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void search(int horses[], int go, int *cnt, int dice[], int M[])
{
	if (go == 10)
	{
		if (*cnt > ans)
		{
			ans = *cnt;
		}
		return;
	}
	int temp, dist, flag;
	dist = dice[go];
	for (int i = 0; i < 4; i++)
	{
		if (horses[i]) //horse[i]가 진출 했으면
		{
			if (horses[i] != 21) //horses가 도착지점 아니면 이동해봐.
			{
				flag = 1;
				temp = horses[i];
				horses[i] = move(horses[i], dist);
				if (horses[i] != 21)  // 도착지점 아니면 겹치는지 체크.
				{
					for (int j = 0; j < 4; j++)
					{
						if (i != j && horses[i] == horses[j])       //겹치면 못이동해
						{
							flag = 0;
							break;                                   // 탐색 멈추기.
						}
					}
				}
				if (flag)
				{
					*cnt += M[horses[i]];
					search(horses, go + 1, cnt, dice, M);
					*cnt -= M[horses[i]];
				}
				horses[i] = temp;
				
			}

		}
		else                 //horse[i]가  진출안했으면
		{
			flag = 1;
			temp = horses[i];
			horses[i] = move(horses[i], dist);
			for (int j = 0; j < 4; j++)
			{
				if (i != j && horses[i] == horses[j])       //겹치면 못이동해
				{
					flag = 0;
					break;                                   // 탐색 멈추기.
				}
			}
			if (flag)
			{
				*cnt += M[horses[i]];
				search(horses, go + 1, cnt, dice, M);
				*cnt -= M[horses[i]];
			}
			horses[i] = temp;
			break;
		}
	}
	return;
}

int move(int horse, int move)
{
	if (0 <= horse && horse < 21)  //21은 도착지점
	{
		if (horse == 5)
		{
			if (move < 4)
			{
				horse = 21 + move;
			}
			else
			{
				horse = 29 + (move - 3);
			}
			
		}
		else if (horse == 10)
		{
			if (move < 3)
			{
				horse = 24 + move;
			}
			else
			{
				horse = 29 + (move - 2);
			}
			
		}
		else if (horse == 15)
		{
			if (move < 4)
			{
				horse = 26 + move;
			}
			else
			{
				horse = 29 + (move - 3);
			}
			
		}
		else
		{
			horse += move;
			if (horse > 20)
			{
				horse = 21;
			}
		}
		return horse;
	}
	else if (21 < horse && horse < 25)
	{
		horse += move;
		if (horse > 24)
		{
			if (horse > 27)
			{
				if (horse == 28)
					return 20;
				return 21;
			}
			return 5 + horse;
		}
		return horse;
	}
	else if (25 <= horse && horse < 27)
	{
		horse += move;
		if (horse > 26)
		{
			if (horse > 29)
			{
				if (horse == 30)
					return 20;
				return 21;
			}
			return 3 + horse;
		}
		return horse;
	}
	else if (27<= horse && horse <30)
	{
		horse += move;
		if (horse > 29)
		{
			if (horse > 32)
			{
				if (horse == 33)
					return 20;
				return 21;
			}
			return horse;
		}
		return horse;
	}
	else
	{
		horse += move;
		if (horse > 32)
		{
			if (horse == 33)
				return 20;
			return 21;
		}
		return horse;
	}
}