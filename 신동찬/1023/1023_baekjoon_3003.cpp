// Å·, Äý, ·è, ºñ¼ó, ³ªÀÌÆ®, Æù
#include <iostream>
using namespace std;
/*
int main() {
	int king, queen, rook, bishop, knight, pawn;
	cin >> king >> queen >> rook >> bishop >> knight >> pawn;
	cout << 1 - king << " " << 1 - queen << " " << 2 - rook << " " << 2 - bishop << " " << 2 - knight << " " <<  8 - pawn;
	return 0;
}
*/

int main() {
	int chess[6] = { 1, 1, 2, 2, 2, 8 };
	int input_pieces[6];

	for (int i = 0; i < 6; i++){
		cin >> input_pieces[i];
	}

	for (int i = 0; i < 6; i++) {
		cout << chess[i] - input_pieces[i] << " ";
	}
	return 0;
}
