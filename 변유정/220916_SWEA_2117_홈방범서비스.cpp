#include <iostream>
#include <vector>
using namespace std;

/// 
/// 시뮬레이션 + 구현 (?)
/// 1. 최적의 K값 범위 구하기 (K 범위 - 1~2*N)
/// 2. 마름모 범위 구하기 (벡터 사용) 절대값 y,x 더했을 때 범위 넘어가지 않으면 넣기
/// 3. 서비스 홈 cnt 갯수 구하기 (이때 cost가 0 미만이면 0으로 되돌려주기)
/// 4. cnt가 ans보다 크면 갱신하기

int T, N, M, K;
int city[21][21];
int ans = 0;
vector <pair<int, int>> service;


/// 2단계
void diamond(int area)
{
    for (int y = -area + 1; y < area; y++)
        for (int x = -area + 1; x < area; x++)
            if (abs(y) + abs(x) < area) service.push_back({ y,x });
}

/// 3단계
int secu(int cost, int y, int x)
{
    int cnt = 0;
    for (int i = 0; i < service.size(); i++)
    {
        int ny = y + service[i].first;
        int nx = x + service[i].second;
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (city[ny][nx] == 1)
        {
            cnt++;
            cost += M;
        }
    }
    if (cost < 0) return 0;
    else return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N >> M;
        int temp = 0;
        for (int y = 0; y < N; y++)
            for (int x = 0; x < N; x++)
            {
                cin >> city[y][x];
                if (city[y][x] == 1)
                    temp += M;
            }

        // 1단계
        for (K = N * 2; K >= 1; K--)
            if (K * K + (K - 1) * (K - 1) < temp) break;

        for (int i = 1; i <= K; i++)
        {
            // 새로운 마름모 범위 구하기
            service.clear();
            diamond(i);
            int cost = i * i + (i - 1) * (i - 1);
            for (int y = 0; y < N; y++)
            {
                for (int x = 0; x < N; x++)
                {
                    // 4단계
                    int tmp = secu(-cost, y, x);
                    if (ans < tmp) ans = tmp;
                }
            }
        }
        cout << "#" << tc << " " << ans << "\n";
        ans = 0;
    }
}

// 다른사람 코드 최적화
//#include <iostream>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false); cin.tie(0);
//    int t, hx[400], hy[400], idx, n, m, ans;
//    char a[20][20];
//    cin >> t;
//    for (int tc = 1; tc <= t; tc++) {
//        ans = idx = 0;
//        cin >> n >> m;
//        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
//            cin >> a[i][j];
//            if (a[i][j] == '1') hx[idx] = i, hy[idx++] = j;
//        }
//        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
//            int c[41] = { 0, };
//            for (int k = 0; k < idx; k++) c[abs(i - hx[k]) + abs(j - hy[k]) + 1]++;
//            for (int k = 1; k < 41; k++) {
//                c[k] += c[k - 1];
//                if (c[k] * m - ((k - 1) * (k - 1) + k * k) >= 0)
//                    ans = c[k] > ans ? c[k] : ans;
//            }
//        }
//        cout << "#" << tc << " " << ans << '\n';
//    }
//    return 0;
//}