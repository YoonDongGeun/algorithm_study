#include <iostream>
using namespace std;

int main(void)
{
  int n, m, k;
  scanf("%d %d", &n, &m);
  int arr[n][m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  scanf("%d", &k);

  for (int i = 0; i < k; i++)
  {
    int a, b, x, y, sumV;
    scanf("%d %d %d %d", &a, &b, &x, &y);

    for (int p = a - 1; p < x; p++)
    {
      for (int q = b - 1; q < y; q++)
      {
        sumV += arr[p][q];
      }
    }
    printf("%d\n", sumV);
    sumV = 0;
  }
}