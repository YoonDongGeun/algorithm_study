#include <iostream>
using namespace std;

int main(void)
{
  int coin[10];
  fill_n(coin,10,0);
  int n;
  int k;
  int res = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> coin[i];
  }

  for (int i = 9; i >= 0; i--)
  {
    if (coin[i] != 0)
    {
      while (k >= coin[i])
      {
        k -= coin[i];
        res++;
      }
    }
  }
  cout << res;
  
}