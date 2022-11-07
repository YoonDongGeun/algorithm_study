#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<vector<int>> temp;
	vector<int> answer;
	
	int N = enroll.size();
	map<string, int> trans;
	vector<int> edges;
	vector<int> cnt;
	int q = 0;
	for (int i = 0; i < N; ++i) trans[enroll[i]]= i;
	trans["-"] = N;

	edges.resize(N+1, N);
	cnt.resize(N+1,0);
	answer.resize(N,0);
	temp.resize(N + 1);
	for (int i = 0; i < N; ++i) {
		edges[i] = trans[referral[i]];
		cnt[edges[i]] += 1;
	}

	for (int i = 0; i < seller.size(); ++i) temp[trans[seller[i]]].push_back(amount[i]*100);

	vector<int> key;
	for (int i = 0; i < N; ++i) if (!cnt[i]) key.push_back(i);
	
	while (!key.empty()) {
		int i = key.back();
		key.pop_back();
		if (i == N) continue;
		int next = edges[i];
		if (--cnt[next] == 0) key.push_back(next);
		for (int j = 0; j < temp[i].size(); ++j) {
			int c = temp[i][j] / 10;
			answer[i] += temp[i][j] - c;
			if (!c) continue;
			temp[next].push_back(c);
		}
	}

	return answer;

}



int main() {
	solution({ "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" }, { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" }, { "young", "john", "tod", "emily", "mary" }, { 12, 4, 2, 5, 10 });
}

