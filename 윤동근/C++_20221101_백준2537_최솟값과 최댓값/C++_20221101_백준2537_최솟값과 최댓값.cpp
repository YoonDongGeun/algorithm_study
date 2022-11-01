#include <iostream>
using namespace std;
int N, M;
int nums[100001], index[100001], Ltree[1<<18], Stree[1<<18];
int makeLtree(int L, int R, int idx);
int makeStree(int L, int R, int idx);


int makeLtree(int L, int R, int idx) // Large 값 트리
{
	if (L == R)
	{
		index[L] = idx;
		return Ltree[idx] = nums[L];
	}
	return Ltree[idx] = makeLtree(L, (L + R) / 2, idx * 2) > makeLtree((L + R) / 2 + 1, R, idx * 2 + 1) ?Ltree[idx*2]:Ltree[idx*2+1];
}


int makeStree(int L, int R, int idx) // Small 값 트리
{
	if (L == R)
	{
		return Stree[idx] = nums[L];
	}
	return Stree[idx] = makeStree(L, (L+R)/2,idx*2) > makeStree((L+R)/2+1, R, idx*2+1) ? Stree[idx * 2+1] : Stree[idx * 2];
}

int Lcompare(int L, int R, int L2, int R2, int idx) //Large트리 에서 찾기 L, R사이 값들중 비교, L2~R2가 최대값 찾을 범위
{
	if (R < L2 || R2 < L)
	{
		return 0;
	}
	if (L2 <= L && R <= R2)
	{
		return Ltree[idx];
	}
	int a, b;
	a = Lcompare(L, (L + R) / 2, L2, R2, idx * 2);
	b = Lcompare((L + R) / 2 + 1, R, L2, R2, idx * 2 + 1);
	return a > b ? a : b;
}

int Scompare(int L, int R, int L2, int R2, int idx) // Small 트리에서 찾기
{
	if (R < L2 || R2 < L)
	{
		return 1000000000;
	}
	if (L2 <= L && R <= R2)
	{
		return Stree[idx];
	}
	int a, b;
	a = Scompare(L, (L + R) / 2, L2, R2, idx * 2);
	b = Scompare((L + R) / 2 + 1, R, L2, R2, idx * 2 + 1);
	return a > b ? b : a;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
	}
	makeLtree(1, N, 1);
	makeStree(1, N, 1);
	int temp1, temp2;
	for (int i = 0; i < M; i++)
	{
		cin >> temp1 >> temp2;
		cout << Scompare(1, N, temp1, temp2, 1) << ' ' << Lcompare(1, N, temp1, temp2, 1) << '\n';
	}



	return 0;
}