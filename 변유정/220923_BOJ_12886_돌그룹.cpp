#include <iostream>
#include <queue>
using namespace std;

// BFS
//  1. 배열을 짤 때 범위는 넉넉히
//  2. 3개 돌 그룹의 합은 언제나 일정하다는 걸 사용하자 (굳이 배열 3개 짜리 사용하지 말고)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int summ = a + b + c;
	queue <pair<int, int>> rock;
	int used[501][501] = {0,};
	used[a][b] = 1;
	rock.push({ a,b });

	if (summ % 3 != 0) cout << 0;
	else
	{
		int k = summ / 3;
		while (!rock.empty())
		{
			int one = rock.front().first;
			int two = rock.front().second;
			int thr = summ - one - two;
			rock.pop();

			if (one != two)
			{
				if (one < two && !used[2 * one][two - one])
				{
					used[2 * one][two - one] = 1;
					rock.push({ 2 * one,two - one });
				}
				else if (one > two && !used[one - two][2 * two])
				{
					used[one - two][2 * two] = 1;
					rock.push({ one - two,2 * two });
				}
			}

			if (two != thr)
			{
				if (two < thr && !used[2 * two][thr - two])
				{
					used[2 * two][thr - two] = 1;
					rock.push({ 2 * two ,thr - two });
				}

				else if (two > thr && !used[two - thr][2 * thr])
				{
					used[two - thr][2 * thr] = 1;
					rock.push({ two - thr, 2 * thr });
				}
			}

			if (thr != one)
			{
				if (one < thr && !used[2 * one][thr - one])
				{
					used[2 * one][thr - one] = 1;
					rock.push({ 2 * one, thr - one });
				}

				else if (one > thr && !used[one - thr][2 * thr])
				{
					used[one - thr][2 * thr] = 1;
					rock.push({ one - thr, 2 * thr });
				}
			}
		}
		cout << used[k][k];
	}
}