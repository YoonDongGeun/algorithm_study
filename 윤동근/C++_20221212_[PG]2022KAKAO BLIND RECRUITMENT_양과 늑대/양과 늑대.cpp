#include <string>
#include <vector>
using namespace std;

int check(vector<int> info, vector<vector<int>> tree, vector<int> member, int sheep, int wolf, int &answer) {
	if (sheep == wolf) {
		return 0;
	}
	int treelen = info.size();
	int sol = 0;
	for (int i = 0; i < treelen; i++) {
		if (member[i] == 2) {
			member[i] = 1;
			for (int j = 0; j < treelen; j++) {
				if (tree[i][j]) {
					member[j] = 2;
				}
			}
			if (info[i]) {
				sol = check(info, tree, member, sheep, wolf + 1, answer);
			}
			else {
				sol = check(info, tree, member, sheep + 1, wolf, answer);
			}
			member[i] = 2;
			for (int j = 0; j < treelen; j++) {
				if (tree[i][j]) {
					member[j] = 0;
				}
			}
			sol > answer ? answer = sol : answer = answer;
		}
	}


	return sheep > answer ? sheep : answer;
}

int solution(vector<int> info, vector<vector<int>> edges) {
	int answer = 1;
	int treelen = info.size();
	vector<vector<int>> tree(treelen, vector<int>(treelen, 0));
	for (int i = 0; i < edges.size(); i++) {
		tree[edges[i][0]][edges[i][1]] = 1;
	}
	vector<int> member(treelen, 0);
	member[0] = 1;
	for (int i = 0; i < treelen; i++) {
		if (tree[0][i]) {
			member[i] = 2;
		}
	}
	check(info, tree, member, 1, 0, answer);
	return answer;
}