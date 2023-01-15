#include <iostream>

#include <string>
#include <vector>

using namespace std;




int solution(int n, vector<vector<int>> computers) {
    
    int answer = 0;
    vector <bool> visit(n,0);
    for (int i = 0; i < n; ++i) {
        if (visit[i]) continue;
        answer++;
        vector <int> stack = {i};
        
        while (!stack.empty()) {
            int nowN = stack.back();
            stack.pop_back();
            visit[nowN] = 1;
            for (int j = 0; j < computers[nowN].size(); ++j) {
                if (!visit[j] && computers[nowN][j]) {
                    stack.push_back(j);
                }
            }
            
        }

    }
    return answer;
    
}


int main() {
    cout << solution(3,{ {1,1,0},{1,1,0},{0,0,1} });
}