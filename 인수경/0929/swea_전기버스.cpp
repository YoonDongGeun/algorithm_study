#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++)
  {
    int k, n, m;
    cin >> k >> n >> m;
    int stop[101] = {
        0,
    };
    for (int i = 0; i < m; i++)
    {
      int tmp;
      cin >> tmp;
      stop[tmp] = 1;
    }
    int p = k;
    int res = 0;
    int cnt = 0;
    while (p < n)
    {
      if (stop[p] == 1)
      {
        cnt = 0;
        res += 1;
        p += k;
      }
      else
      {
        p -= 1;
        cnt += 1;
      }

      if (cnt == k)
        break;
    }
    if (cnt != 0)
    {
      res = 0;
    }

    cout << '#' << tc << ' ' << res << endl;

    fill_n(stop, 101, 0);
  }
}