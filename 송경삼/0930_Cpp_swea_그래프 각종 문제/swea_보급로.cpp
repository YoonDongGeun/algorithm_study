#include <iostream>
#define INF 1e10;
int last;

int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

struct Edge{
	int v;
	int i;
	int j;
};

void swap(Edge *a, Edge*b) {
	Edge temp = *a;
	*a = *b;
	*b = temp;
}

void heap_push(Edge edges[], Edge edge) {
	int id = last;
	edges[last++] = edge;
	if (id == 1) return;
	while (edges[id].v < edges[id / 2].v) {
		swap(&edges[id], &edges[id / 2]);
		id /= 2;
		if (id == 1)break;
	}
}

Edge heap_pop(Edge edges[]) {
	int id = 1; 
	Edge temp = edges[1];
	edges[1] = edges[--last];
	while (1) {
		if (2 * id +1< last) {
			if (edges[2 * id + 1].v < edges[2*id].v && edges[2*id+1].v < edges[id].v) {
				swap(&edges[2 * id + 1], &edges[id]);
				id = 2 * id + 1;
			}
			else if (edges[2 * id + 1].v >= edges[2 * id].v && edges[2 * id].v < edges[id].v) {
				swap(&edges[2 * id], &edges[id]);
				id = 2 * id;
			}
			else break;
		}
		else if (2 * id < last) {
			if (edges[2 * id + 1].v >= edges[2 * id].v && edges[2 * id].v < edges[id].v) {
				swap(&edges[2 * id], &edges[id]);
				id = 2 * id;
			}
			else break;
		}
		else break;
		
	}
	return temp;
}



int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int N, ground[100][100],DP[100][100];
		last = 1;
		Edge PQ[10000],sub;
		char ip[101];
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%s", &ip);
			for (int j = 0; j < N; ++j) {
				ground[i][j] = ip[j] - '0';
				DP[i][j] = INF;
			}
		}
		DP[0][0] = 0;
		sub = { 0,0,0 };
		heap_push(PQ, sub);


		while (1) {
			sub = heap_pop(PQ);
			if (sub.i == N - 1 && sub.j == N - 1) break;

			for (int d = 0; d < 4; ++d) {
				int I = sub.i + di[d];
				int J = sub.j + dj[d];
				if (I < 0 || I >= N || J < 0 || J >= N) continue;
				if (DP[I][J] > DP[sub.i][sub.j] + ground[I][J]) {
					DP[I][J] = DP[sub.i][sub.j] + ground[I][J];
					Edge temp = { DP[I][J],I,J };
					heap_push(PQ, temp);
				}

			}

		}
		printf("#%d %d\n", t, DP[N - 1][N - 1]);


	}
}
//
//
//Edge edges[1000];
//
//Edge edge;
//
//edge.v = 5;
//edge.i = 1;
//edge.j = 1;
//heap_push(edges, edge);
//
//edge.v = 7;
//edge.i = 1;
//edge.j = 1;
//heap_push(edges, edge);
//
//
//edge.v = 3;
//edge.i = 1;
//edge.j = 1;
//heap_push(edges, edge);
//
//
//edge.v = 9;
//edge.i = 1;
//edge.j = 1;
//heap_push(edges, edge);
//
//edge.v = 7;
//edge.i = 1;
//edge.j = 1;
//heap_push(edges, edge);
//
//edge.v = 4;
//edge.i = 1;
//edge.j = 1;
//heap_push(edges, edge);
//
//edge.v = 1;
//edge.i = 1;
//edge.j = 1;
//heap_push(edges, edge);
//
//edge.v = 0;
//edge.i = 1;
//edge.j = 1;
//heap_push(edges, edge);
//
//edge.v = 15;
//edge.i = 1;
//edge.j = 1;
//heap_push(edges, edge);
//
//for (int i = 1; i < last; ++i) printf("%d ", edges[i].v);
//printf("\n");
//
//printf("¹¹°¡ ³ª¿Ô³ª?:%d\n", heap_pop(edges));
//for (int i = 1; i < last; ++i) printf("%d ", edges[i].v);
//printf("\n");
//
//
//printf("¹¹°¡ ³ª¿Ô³ª?:%d\n", heap_pop(edges));
//for (int i = 1; i < last; ++i) printf("%d ", edges[i].v);
//printf("\n");
//
//
//printf("¹¹°¡ ³ª¿Ô³ª?:%d\n", heap_pop(edges));
//for (int i = 1; i < last; ++i) printf("%d ", edges[i].v);
//printf("\n");