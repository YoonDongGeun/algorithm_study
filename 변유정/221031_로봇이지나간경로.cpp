#include <iostream>
#include <vector>
using namespace std;

// 알고리즘 분류 : DFS
// 
// 중요한 점 : 로봇 시작점 찾기
// 
// 나중에 추가해야할 점
// 1. 로봇이 지나친 점을 또 지나가는 경우의 루트
// 2. 시작점이 없고 원을 도는 경우

int H, W, dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
char dir[4] = { '>','v','<','^' };
char board[26][26];
int sy = -1, sx = -1, sdir = 0;
bool used[26][26];
vector <char> v;

void dfs(int y, int x, int d)
{
    if (board[y + dy[d] * 2][x + dx[d] * 2] == '#' && board[y+dy[d]][x+dx[d]] == '#')
    {
        used[y + dy[d]][x + dx[d]] = 1;
        used[y + 2 * dy[d]][x + 2 * dx[d]] = 1;
        v.push_back('A');
        dfs(y + dy[d] * 2, x + dx[d] * 2, d);
    }
    for (int i = 0; i < 4; i++)
    {
        if (i == d) continue;
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= H | nx >= W || board[ny][nx] == '.' || used[ny][nx]) continue;
        //used[ny][nx] = 1;
        if (d - i == 1 || d - i == -3) v.push_back('L');
        else v.push_back('R');
        dfs(y, x, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W;
    for (int i = 0; i < H; i++)
        cin >> board[i];
    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            if (board[y][x] == '#')
            {
                int k = 0, idx = -1;
                for (int i = 0; i < 4; i++)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || nx < 0 || ny >= H || nx >= W || board[ny][nx] == '.') k++;
                    else idx = i;
                }
                if (k == 3)
                {
                    sy = y;
                    sx = x;
                    sdir = idx;
                    break;
                }
            }
        }
        if (sy != -1) break;
    }
    cout << sy + 1 << " " << sx + 1 << '\n';
    cout << dir[sdir] << '\n';
    used[sy][sx] = 1;
    dfs(sy, sx, sdir);
    for (int i = 0; i < v.size(); i++)
        cout << v[i];
}