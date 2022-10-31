
#include <string>
#include <vector>

using namespace std;

void dfs(int n, int used, int& answer, vector<string>& user_id, vector<string>& banned_id, int&user_id_size, int&banned_id_size, int cnt[]) {
    if (n == banned_id_size) {
        if (!cnt[used])
        {
            ++answer;
            cnt[used] = 1;
        }
    }
    else {
        for (int i = 0; i < user_id_size; ++i) {
            if (!(used&(1<<i)) && banned_id[n].length() == user_id[i].length()) {
                int flag = 1;
                for (int j = 0; j < banned_id[n].length();++j) {
                    if (banned_id[n][j] != '*' && banned_id[n][j] != user_id[i][j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    dfs(n + 1, (used | (1 << i)), answer, user_id, banned_id, user_id_size, banned_id_size, cnt);
                }
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int cnt[1 << 8]={0,};
    int A = user_id.size();
    int B = banned_id.size();
    dfs(0, 0, answer, user_id, banned_id, A, B, cnt);
    return answer;
}
