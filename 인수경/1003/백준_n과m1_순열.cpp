#include <iostream>
using namespace std;

void perm(int n, int k, int r, int p[], int used[], int arr[])
{
  if (k == r)
  {
    for (int i = 0; i < r; i++)
    {
      cout << p[i] << " ";
    }
    cout << '\n';
    return;
  }
  else
    for (int i = 0; i < n; i++)
    {
      if (used[i] == 0)
      {
        p[k] = arr[i];
        used[i] = 1;
        perm(n, k + 1, r, p, used, arr);
        used[i] = 0;
      }
    }
}

int main(void)
{
  int n, m;
  cin >> n >> m;
  int arr[8];
  int p[8];
  int used[8];

  fill_n(used, 8, 0);
  fill_n(p, 8, 0);
  fill_n(arr, 8, 0);

  for (int i = 1; i <= n; i++)
  {
    arr[i - 1] = i;
  }

  perm(n, 0, m, p, used, arr);
}
