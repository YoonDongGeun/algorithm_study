#include <iostream>
using namespace std;
int N;
int T[1<<17];
int cntL=0, cntR=0;
int Lflag = 2, Rflag = 2;
int Lsize=0, Rsize=0;
void push(int a);
void alignR(int index);
void alignL(int index);
void alignR2();
void alignL2();

void alignL(int index)
{
	if (index < 2)
		return;
	while (index != 2)
	{
		int index2 = index / 2;
		if (T[index] > T[index2])
		{
			int temp = T[index];
			T[index] = T[index2];
			T[index2] = temp;
		}
		else
		{
			break;
		}
		index = index2;
	}
	return;
}
void alignR(int index)
{
	if (index < 3)
		return;
	while (index != 3)   //최소힙 정렬
	{
		int index2 = index / 2;
		if (T[index] < T[index2])
		{
			int temp = T[index];
			T[index] = T[index2];
			T[index2] = temp;
		}
		else
		{
			break;
		}
		index = index2;
	}
	return;
}



void alignR2()
{
	int index = 3;
	while (index <= Rsize/2)
	{
		int idx1 = index * 2 + 1;
		int idx2 = index * 2;
		if (T[idx2] < T[idx1])
		{
			if (T[index] > T[idx2])
			{
				int temp = T[index];
				T[index] = T[idx2];
				T[idx2] = temp;
				index = idx2;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (T[index] > T[idx1])
			{
				int temp = T[index];
				T[index] = T[idx1];
				T[idx1] = temp;
				index = idx1;
			}
			else
			{
				break;
			}
		}
	}
}

void alignL2()
{
	int index = 2;
	while (index <= Lsize / 2)
	{
		int idx1 = index * 2 + 1;
		int idx2 = index * 2;
		if (T[idx2] < T[idx1])
		{
			if (T[index] < T[idx1])
			{
				int temp = T[index];
				T[index] = T[idx1];
				T[idx1] = temp;
				index = idx1;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (T[index] < T[idx2])
			{
				int temp = T[index];
				T[index] = T[idx2];
				T[idx2] = temp;
				index = idx2;
			}
			else
			{
				break;
			}
		}
	}
}
void push(int a)
{
	if (cntL < cntR) //오른쪽 크면 왼쪽넣어
	{
		cntL++;
		if (Lflag <= cntL)  //2개되면 4개되면  8개 되면  
		{
			Lflag *= 2;
		}
		int insert = Lflag + cntL - Lflag / 2;

		if (T[1] >= a) //a가 작으면 a를 왼쪽 넣어
		{
			T[insert] = a;
		}
		else // a가 크면 T[1]을 왼쪽넣고 a는 T[1]넣어
		{
			if (a > T[3])
			{
				T[insert] = T[1];
				T[1] = T[3];
				T[3] = a;
				alignR2(); //index 3에서 뒤로
			}
			else
			{
			T[insert] = T[1];
			T[1] = a;
			}
		}
		Lsize = insert;
		alignL(insert);
	}
	else           //같으면 오른쪽 넣어. 오른쪽 최소힙 왼쪽 최대힙
	{
		cntR++;
		int insert = Rflag + cntR;
		if (cntR >= Rflag-1)
		{
			Rflag *= 2;
		}
		// 새로온 얘를 오른쪽 갈지, 기존 얘를 오른쪽 갈지.
		if (T[1] <= a) // a를 오른쪽으로 넣어
		{
			T[insert] = a;
		}
		else            // T[1]을 오른쪽으로 , a는 T[1]으로
		{
			if (a < T[2])
			{
				T[insert] = T[1];
				T[1] = T[2];
				T[2] = a;
				alignL2();
			}
			else
			{
				T[insert] = T[1];
				T[1] = a;
			}

		}
		Rsize = insert;
		alignR(insert);
	}

	cout << T[1] << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 2; i < 100000; i *= 2)
	{
		for (int j = 0; j < (i/2); j++)
		{
			T[i + j] = -20000;
		}
	}
	for (int i = 2; i < 100000; i *= 2)
	{
		for (int j = 1; j <= i/2; j++)
		{
			T[i*2 - j] = 20000;
		}
	}
	int temp;
	cin >> temp;
	T[1] = temp;
	cout << temp << '\n';

	for (int i = 1; i < N; i++)
	{
		cin >> temp;
		push(temp);
	}
}