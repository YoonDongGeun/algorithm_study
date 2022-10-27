#include <iostream>
#include <string>
#define F(x,s,e) for (int x=s;x<s+e;++x)

using namespace std;
int N;
char arr[64][65];

string q(int i, int j, int n) {
	int flag = 1;
	char temp = arr[i][j];
	F(di, i, n) F(dj, j, n) if (arr[di][dj] != temp) { flag = 0; break; }
	if (flag) {
		string temp2;
		temp2=temp;
		return temp2;
	}
	int v = n / 2;
	return "(" + q(i, j, v) + q(i, j + v, v) + q(i + v, j, v) + q(i + v, j + v, v) + ")";

}

int main() {
	scanf("%d", &N);
	F(i, 0, N) scanf("%s", &arr[i]);
	std::cout << q(0,0,N) << "\n";
}