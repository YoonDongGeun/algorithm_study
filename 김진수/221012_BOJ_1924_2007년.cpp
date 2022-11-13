#include <iostream>

int main(void)
{
	using namespace std;

	int x, y;
	cin >> x >> y;

	int cnt = 0;
	while (x != 0)
	{
		while (y != 0)
		{
			y--;
			cnt++;
		}
		x--;
		if (x == 4 || x == 6 || x == 9 || x == 11)
		{
			y = 30;
		}
		else if (x == 2)
		{
			y = 28;
		}
		else
		{
			y = 31;
		}
	}
	
	string day[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int i = cnt % 7;
	cout << day[i];

	return 0;
}