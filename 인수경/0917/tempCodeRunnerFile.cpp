#include <iostream>
using namespace std;

int main(void)
{
  int a;
  int b;

  scanf("%d %d", &a, &b);

  if (a > b)
  {
    printf(">");
  }
  else if (a < b)
  {
    printf("<");
  }
  else
  {
    printf("==");
  }

  return 0;
}