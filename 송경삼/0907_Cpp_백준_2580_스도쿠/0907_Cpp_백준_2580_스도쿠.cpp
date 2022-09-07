#include <iostream>
#include <vector>
#include <stdlib.h>

struct D2 {
	int I;
	int J;
};

std::vector<D2> IJ;
int L[9][9];
int c,N;


bool check(int k, int l, int n) {
	for (int x = 0; x < 9; x++)  {
		if (L[x][l] == n) { return 1; }
	}
	for (int y = 0; y < 9; y++) {
		if (L[k][y] == n) { return 1; }
	}
	k = (k / 3)*3;
	l = (l / 3)*3;
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			if (L[k + x][l + y] == n) { return 1; }
		}
	}
	return 0;
}


void BT(int c){
	if (c == N) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				std::cout << L[i][j] << " ";
			}
			if (i!=8) std::cout << "\n";
		}
		exit(0);
	}


	else {
		int k = IJ[c].I,l = IJ[c].J;
		for (int n = 1; n <= 9; n++) {
			if (check(k, l, n)) { continue; }
			L[k][l] = n;
			BT(c + 1);
			k = IJ[c].I;
			l = IJ[c].J;
			L[k][l] = 0;
		}
	}
}


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cin >> L[i][j];
			if (L[i][j] == 0) {
				D2 ij = {i,j};
				IJ.push_back(ij);
			}
		}
	}
	N = IJ.size();
	BT(0);
}