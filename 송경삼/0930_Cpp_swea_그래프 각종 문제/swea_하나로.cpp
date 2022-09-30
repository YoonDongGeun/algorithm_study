#include <iostream>
#include <algorithm>

using namespace std;

struct Edge{
	long double cost;
	int a, b;
};
Edge edges[500501];
bool comp(Edge a, Edge b) {
	return a.cost < b.cost;
}
int FD(int a, int *Parent) {
	while (a != Parent[a]) a = Parent[a];
	return a;
}
void UN(int a, int b, int *Parent) {
	Parent[FD(b, Parent)] = FD(a, Parent);
}

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		std::cin >> N;
		int X[1000], Y[1000];
		long double ans, sum = 0;
		int Parent[1000], cnt=0;
		int c1 = 0, c2 = 0;
		for (int i = 0; i < N; ++i) Parent[i] = i;
		for (int n = 0; n < N; ++n) { std::cin >> X[n]; }
		//for (int n = 0; n < N; ++n) { std::cout << n << " : " << X[n] << "\n"; }

		for (int n = 0; n < N; ++n) { std::cin >> Y[n]; }
		//for (int n = 0; n < N; ++n) { std::cout << n << " : " << Y[n] << "\n"; }



		std::cin >> ans;

		int id = -1; long double M = 0;
		for (int i = 0; i < N-1; ++i) {
			for (int j = i + 1; j < N; ++j) {
				edges[++id].cost = (long double)(X[i] - X[j])*(long double)(X[i] - X[j]) + (long double)(Y[i] - Y[j])*(long double)(Y[i] - Y[j]);
				//std::cout << "이번 X:" << X[i] - X[j] << " / 이번 Y:" << Y[i] - Y[j] << "비용:" << "\n";;
				//std::cout << "이번 X길이:"<< (X[i] - X[j])*(X[i] - X[j]) << " / 이번 Y길이:"<< (Y[i] - Y[j])*(Y[i] - Y[j]) <<"비용:"<< edges[id].cost << "\n";;
				edges[id].a = i;
				edges[id].b = j;
				
			}
		}
		std::sort(edges, edges + id + 1, comp);
		//for (int i = 0; i <= id; ++i) std::cout << edges[i].cost << " ";;

		for (int i = 0; i <= id; ++i) {
			if (FD(edges[i].a, Parent) != FD(edges[i].b, Parent)) {
				sum += edges[i].cost;
				UN(edges[i].a, edges[i].b, Parent);
				if (++cnt == N - 1) break;
			}
		}
		sum *= ans;
		cout << fixed;
		std::cout.precision(0);
		std::cout << "#" << t << " " << sum <<"\n" ;
	}

}