#include <iostream>
#include <cstring>
using namespace std;

// int main(void)
// {
//   char join_id[51];
//   scanf("%s", join_id);

//   printf("%s?\?!", join_id);
//   return 0;
// }

int main(void)
{
  char join_id[51];
  char add_q[] = "?\?!";
  scanf("%s", join_id);

  printf("%s", strcat(join_id, add_q));
  return 0;
}