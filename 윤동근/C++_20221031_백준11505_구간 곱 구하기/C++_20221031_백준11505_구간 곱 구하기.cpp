#include <iostream>
#include <vector>
using namespace std;
long long N, M, K, a, b, c;
#define r long long     // long long 계속 쓰기 힘드니 단축.
#define k 1000000007    // 나눠야 하는 수
vector<r> nums;         // 입력 받은 숫자들 인덱스 1부터 저장할 벡터
vector<r> tree (1<<21); // 100만개는 2^20 과 가깝다. 1+2+4+...2^20 = 2^21-1 



r maketree(r L, r R, r idx)  // 세그먼트 트리 만들기
{
	if (L == R)
	{
		return tree[idx] = nums[L];
	}
	return tree[idx] = (maketree(L, (L + R) / 2, idx * 2) * maketree((L + R) / 2 + 1, R, idx * 2 + 1))%k; //k로 나머지 해줘야 long long 범위 안넘어감
}



r sum(r L, r R, r SL, r SR, r idx)  // 인덱스 SL~SR 의 곱 구하기
{
	if (SR < L || R<SL)
	{
		return 1;
	}
	if (SL <= L && R <= SR)
	{
		return tree[idx];
	}
	return (sum(L, (L+R)/2, SL, SR, idx*2))*(sum((L+R)/2+1, R, SL, SR, idx*2+1))%k;
}

void change(r L, r R, r S, r n, r idx) // S번째 숫자 바꾼뒤, 부모 노드들 그 영향 반영하기
{
	if (S < L || R < S)
	{
		return;
	}
	if (L == R && R == S)
	{
		tree[idx] = n;
		while (idx != 1)
		{
			if (idx % 2)
			{
				tree[idx / 2] = (tree[idx] * tree[idx - 1])%k;
			}
			else
			{
				tree[idx / 2] = (tree[idx] * tree[idx + 1])%k;
			}
			idx /= 2;
		}
		return;
	}

	change(L, (L + R) / 2, S, n, idx * 2);
	change((L + R) / 2 + 1, R, S, n, idx * 2 + 1);
	return;


}


int main(void)
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	nums.push_back(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) // N개 수 nums 벡터에 입력받기
	{
		cin >> a;
		nums.push_back(a);
	}
	maketree(1, N, 1); // N개의 입력받은 수를 바탕으로 곱 트리 만들기
	for (int i = 0; i < M+K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			change(1, N, b, c, 1); // b번째 수를 c로 바꾼뒤 트리에 결과 반영
		}
		else
		{
			cout << sum(1, N, b, c, 1) << '\n'; // b번째부터 c번째 까지 구간 곱 구하여 출력.
		}
	}


	return 0;
}