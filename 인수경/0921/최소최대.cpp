#include <stdio.h>
using namespace std;

int main(void)
{
  int n;
  scanf("%d", &n);
  int arr[n];
  int maxV = -1000001;
  int minV = 1000001;

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  };

  for (int i = 0; i < n; i++)
  {
    if (arr[i] < minV)
    {
      minV = arr[i];
    }

    if (arr[i] > maxV)
    {
      maxV = arr[i];
    }
  };

  printf("%d %d", minV, maxV);

  return 0;
}