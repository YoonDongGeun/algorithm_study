#include <iostream>
using namespace std;

int main() {
	// tc가 많아서 입출력을 빠르게 해야할 때
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t, a, b;
	cin >> t;
	for (t; t > 0; t -= 1) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return 0;
}

//--------------------------------------------------------

// sanf, printf 사용
#include <iostream>
using namespace std;

int main() {
	int t, a, b;
	scanf("%d", &t);

	for (t; t > 0; t -= 1) {
		scanf("%d%d", &a, &b);
		printf("%d\n", a + b);
	}

	return 0;
}
