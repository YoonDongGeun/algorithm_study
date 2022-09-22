#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int X, Y, D, T;
	cin >> X >> Y >> D >> T;
	double dist = sqrt(X*X+Y*Y);
	cout.precision(60);
	double time = 0;
	if (D > T)
	{
		int d = dist / D;
		int t = T * d;
		time += t;
		dist -= D *d;				// 1. 점프해서 가까이 최대한 감.
		if (dist < T)
		{
			time += dist;
		}
		else if (time && D + T - dist < dist && D + T - dist < T)
		{
			time += T + D - dist;
		}
		else if (!time && D + T - dist < dist && D + T - dist < 2 * T)  // 뒤 갔다 앞으로 가는게 빠를때
		{
			
			time += T + D - dist;
		}
		else if (!time && 2 * T <= D + T - dist && 2 * T <= dist)   //점프 2번이 빠를때
		{
			time += 2 * T;
		}
		else if (time && T <=dist && T <= D+T-dist)
		{
			time += T;
		}
		else
		{
			time += dist;
		}
	}
	else          // 점프가 더 좁으면 걷기.
	{
		time = dist;
	}
	cout << time;

}
