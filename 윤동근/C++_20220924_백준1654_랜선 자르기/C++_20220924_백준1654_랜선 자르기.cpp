#include <iostream>
#include <algorithm>

int main(void) {
	long long K, N, min, max, cnt;
	min = 10000, max = 0;
	int LS[10000];
	std::cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		std::cin >> LS[i];
		if (LS[i] < min)
			min = LS[i];
		if (LS[i] > max)
			max = LS[i];
	}
	long long pro1, proL, proR, proM;
	N%K == 0 ? pro1 = N / K : pro1 = N / K + 1;
	proL = min / pro1;
	proR = max / pro1;
	cnt = 0;
	for (int i = 0; i <  K; i++)
	{
		cnt += LS[i] / proR;
	}
	if (cnt != N)		//오른쪽 틀리면 왼쪽 검사.
	{
		while (proL!=proR)	//이진탐색 시작.
		{
			proM = (proL + proR+1) / 2;
			cnt = 0;
			for (int i = 0; i < K; i++)
			{
				cnt += LS[i] / proM;
			}
			if (cnt < N) {
				proR = proM-1; //줄여! 줄이면
			}
			else if (N < cnt)  //너무 수가 많으니 자르는 길이를 줄여
			{
				proL = proM;
			}
			else				// 수가 같으면
			{
				proL = proM;
			}
		}
	}
	std::cout << proR;

	return 0;
}