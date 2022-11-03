#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


long long N, M, K;
long long ip[1000000];
long long st[3000000] = { 0, };


long long makesgt(long long n, long long l, long long r) {
	if (l == r) {
		st[n] = ip[l];
		return ip[l];
	}
	long long m = (l + r)/2;
	st[n] = makesgt(2 * n, l, m) + makesgt(2 * n + 1, m+1, r);
	return st[n];
}	//세그먼트 트리를 만드는 함수입니다.


void editsgt(long long n, long long l, long long r, long long idx, long long dn) {
	if (l <= idx && r >= idx) {
		st[n] += dn;
		if (l == r) return;
		long long m = (l + r) / 2;
		editsgt(2 * n, l, m, idx, dn);
		editsgt(2 * n + 1, m+1, r, idx, dn);
	}
}	//원래 배열의 인풋이 변경됨에 따라 세그먼트 트리를 수정하는 함수입니다.

long long sumsgt(long long n, long long l, long long r, long long l_, long long r_) {
	if (l_ <= l && r <= r_) return st[n];
	if (r < l_ || r_ < l) return 0;
	long long m = (r + l) / 2;
	return sumsgt(2 * n, l, m, l_, r_) + sumsgt(2 * n + 1, m + 1, r, l_, r_);
} //세그먼트 트리를 돌면서 구간합을 구하는 함수입니다.


int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int n = 0; n < N; ++n) scanf("%lld", &ip[n]);
	long long c, l, r;

	makesgt(1, 0, N - 1);

	for (int q = 0; q < M + K; ++q) {
		scanf("%lld %lld %lld", &c, &l, &r);
		if (c == 1) {
			editsgt(1, 0, N - 1, l - 1, r - ip[l - 1]);
			ip[l - 1] = r;
		}
		else if (c == 2) {
			printf("%lld\n",sumsgt(1, 0, N - 1, l - 1, r - 1));
		}
	}

}



