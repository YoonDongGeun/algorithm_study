#include <iostream>

using namespace std;

int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int main(void)
{
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++)
  {
    int N,M;
    cin >> N >> M;
    int arr[100][100];
    for (int i = 0; i < N; i++){
      for (int j = 0; j < M; j++){
        cin >> arr[i][j];
      }
    }

    int res = 0;
    for (int i = 0; i < N; i++){
      for (int j = 0; j < M; j++){
        int cnt = 0;
        for (int d = 0; d < 8; d++){
          int ni = i + dir[d][0];
          int nj = j + dir[d][1];
          if (0 <= ni && ni < N && 0 <= nj && nj < M && arr[ni][nj] < arr[i][j]){
            cnt++;
          }
        }
        if (cnt >= 4) res++;
      }
    }
    cout << "#" << tc << ' ' << res << '\n';
  }
  return 0;
}