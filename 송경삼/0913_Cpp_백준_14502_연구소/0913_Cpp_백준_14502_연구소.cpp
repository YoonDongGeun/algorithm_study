//#include <iostream>
//#include <vector>
//#include <string.h>
//using namespace std;
//
//struct IJ {
//	int I;
//	int J;
//};
//
//int N, M, num, cnt_safe, ans=0;
//int room[8][8];
//int room_copy[8][8];
//vector <IJ>v;
//IJ sub;
//int di[4] = { 1,0,-1,0 }, dj[4]={0,-1,0,1};
//
//int virus() {
//	int cnt_virus=0;
//	IJ d_sub;
//	vector<IJ> stack;
//	stack = v;
//	while (!stack.empty()) {
//		sub = stack.back();
//		stack.pop_back();
//		for (int d = 0; d < 4; ++d) {
//			d_sub.I = sub.I + di[d];
//			d_sub.J = sub.J + dj[d];
//			if (d_sub.I >= 0 && d_sub.I < N && d_sub.J >= 0 && d_sub.J < M && !room_copy[d_sub.I][d_sub.J]) {
//				room_copy[d_sub.I][d_sub.J] = 2;
//				stack.push_back(d_sub);
//				cnt_virus++;
//			}
//		}
//	}
//
//	return cnt_safe - cnt_virus;
//}
//
//
//void BT(int c,int n) {
//	if (c == 0) {
//		memcpy(room_copy, room, sizeof(room));
//		num=virus();
//		if (num > ans) ans = num;
//		return;
//	}
//	for (int i = 0; i < N; ++i) {
//		for (int j = 0; j < M; ++j) {
//			if (!room[i][j] && M*i+j>n) {
//				room[i][j] = 1;
//				BT(c - 1,M*i+j);
//				room[i][j] = 0;
//			}
//		}
//	}
//}
//
//
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M;
//	for (int i = 0; i < N; ++i) {
//		for (int j = 0; j < M; ++j) {
//			cin >> room[i][j];
//			if (!room[i][j]) ++cnt_safe;
//			if (room[i][j] == 2) { sub.I = i; sub.J = j; v.push_back(sub); }
//		}
//	}
//	cnt_safe -= 3;
//	BT(3,-1);
//	cout << ans << "\n";
//}