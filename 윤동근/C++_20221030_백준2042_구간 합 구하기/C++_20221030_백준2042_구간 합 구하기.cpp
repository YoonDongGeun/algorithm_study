#include <iostream>
using namespace std;
//세그먼트 트리
long long N, M, K;
long long A[4200000];
long long B[1000002];
long long C[1000002];
long long sum2(long long L, long long R, long long L2, long long R2, long long idx);


long long sum(long long L, long long R, long long idx) // 함수 이름이 이상하지만, segment 트리를 만드는 함수.
{
	if (L == R)
	{
		C[L] = idx; // L번째 숫자의 인덱스 저장하기.
		return A[idx] = B[L];
	}
	return A[idx] = sum(L, (L+R)/2, idx*2) + sum((L+R)/2+1, R, idx*2+1); // ex) A[1] = A[2] + A[3] (A[2]와 A[3]은 구해야함) -> A[2] = A[4]+A[5] ...
}

long long sum2(long long L, long long R, long long L2, long long R2, long long idx) // 트리의 L2~R2까지의 합을 구하는 함수.
{
	if (R < L)
	{
		return 0;
	}
	if (L2 <= L && R2 >= R)
	{
		return A[idx];
	}
	if (R < L2 || R2 < L)
	{
		return 0;
	}
	return sum2(L, (L + R) / 2, L2, R2, idx * 2) + sum2(((L + R) / 2) + 1, R, L2, R2, idx * 2 + 1);

}

int main(void)
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long temp, c;
	long long a, b, index1;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) //N개의 수 입력받기 B에는 1번인덱스부터 N번 인덱스 까지 값 저장.
	{
		cin >> B[i];
	}
	sum(1, N, 1);
	for (long long i = 0; i < M+K; i++) // a==1 이면 b번째 수를 c로 바꾸고 세그먼트 트리 수정, a==2이면 b~c까지 합 구하기.
	{
		cin >> a >> b >> c;
		if (a == 1)  //바꾸기
		{
			temp = B[b] - c;
			B[b] = c;
			index1 = C[b];
			A[index1] = c;
			index1 /= 2;
			while (index1)         // index1이 바꾼 숫자의 인덱스인데 이를 바탕으로 상위 부모트리들 값 바꿔주기.
			{
				A[index1] -= temp;
				index1 /= 2;
			}
		}
		else         // b~c까지 합 구하기
		{
			cout << sum2(1, N, b, c, 1) << '\n';  // b~c까지 구간합 구하기.
		}

	}
	return 0;
}