#include <iostream>

int main(void) {
	int N, sol;
	int LS[10004];
	int LSS[10004];
	std::cin >> N;
	LS[0] = 0;
	LS[1] = 0;
	LS[2] = 0;
	LS[3] = 0;
	LSS[0] = 0;
	LSS[1] = 0;
	LSS[2] = 0;
	LSS[3] = 0;
	for (int i = 4; i < N+4; i++)
	{
		std::cin >> LS[i];
		if (LSS[i - 4]+LS[i-1] > LSS[i - 2] && LSS[i - 4]+LS[i-1] > LSS[i - 3]+LS[i-1])  // 이 케이스는 2잔 연속 안마신 후 2잔을 연속으로 마시는 경우이다. 이 케이스 때문에 여러번 돌렸다. 찾기가 힘들다...
		{
			LSS[i] = LS[i] + LS[i - 1] + LSS[i - 4];
		}
		else
		{
			(LSS[i - 2] + LS[i]) >= (LS[i] + LS[i - 1] + LSS[i - 3]) ? LSS[i] = LSS[i - 2] + LS[i] : LSS[i] = LS[i] + LS[i - 1] + LSS[i - 3];  // 계속 1칸 빼고 마시거나 그냥 마실때 최대갯수.
		}
		
	}
	LSS[N + 3] >= LSS[N + 2] ? sol = LSS[N + 3] : sol = LSS[N + 2];	 // 마지막에 안마시는 경우와 마시는 경우가 있으므로, 둘중 최대값.
	std::cout << sol << '\n';
}