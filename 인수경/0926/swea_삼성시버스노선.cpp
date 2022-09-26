#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++)
  {
    int stop[5001];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int a, b;
      cin >> a >> b;
      for (int j = a; j <= b; j++)
      {
        stop[j]++;
      }
    }
    int p;
    cin >> p;
    int res[p];
    for (int i = 0; i < p; i++)
    {
      int tmp;
      cin >> tmp;
      res[i] = stop[tmp];
    }
    cout << "#" << tc << ' ';
    for (int i = 0; i < p; i++)
    {
      cout << res[i] << ' ';
    }
    cout << '\n';

    fill_n(stop, 5001, 0);
  }
}