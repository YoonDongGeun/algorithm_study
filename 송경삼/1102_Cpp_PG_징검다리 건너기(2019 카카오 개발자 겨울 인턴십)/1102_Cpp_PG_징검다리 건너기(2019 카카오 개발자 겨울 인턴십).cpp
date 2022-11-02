#include <iostream>
//-------------------------------------------------------------------
#include <set>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 0;
	answer = 1e9;
	multiset <int> s;

	for (int i = 0; i < k; ++i) {
		s.insert(stones[i]);
	}
	multiset<int>::iterator end = --(s.end());
	if (*end < answer) answer = *end;

	for (int i = k; i < stones.size(); ++i) {
		multiset<int>::iterator q = s.find(stones[i - k]);
		s.insert(stones[i]);
		s.erase(q);
		multiset<int>::iterator end = --(s.end());
		if (*end < answer) answer = *end;
	}

	return answer;
}

//-------------------------------------------------------------------
int main() {
	vector<int> stones;
	stones = { 0, 0, 0, 3, 2, 1, 4, 2, 4, 3 };
	printf("%d", solution(stones, 3));
}