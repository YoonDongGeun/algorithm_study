// #include <iostream>
// using namespace std;

// void func(int stack[], char c[], int *t, int *p)
// {
//   if (c[0] == "push")
//   {
//     stack[*p] = c[1];
//     *p += 1;
//   }
//   else if (c[0] == "pop")
//   {
//     if (stack[*t] != 0){
//       cout << stack[*t] << "\n";
//       *t += 1;
//     }
//     else cout << -1;
//   }
//   else if (c[0] == "size")
//   {
//     cout << *p - *t << "\n";
//   }
//   else if (c[0] == "empty")
//   {
//     if (*p - *t == 0){
//       cout << 1 << "\n";
//     }
//     else cout << 0 << "\n";
//   }
//   else {
//     if (stack[*t] != 0){
//       cout << stack[*t] << "\n";
//     }
//     else cout << -1 << "\n";
//   }
// }

// int main(void)
// {
//   int N;
//   int stack[10000];
//   fill_n(stack, 10000, 0);
//   int t = 0;
//   int p = 0;

//   cin >> N;
//   for (int i = 0; i < N; i++)
//   {
//     char com[3] = {0,0,0};
//     cin >> com[0];
//     if (com[0] == "push")
//     {
//       cin >> com[1];
//     }
//     func(stack, com, &t, &p);
//     fill_n(com, 3, 0);
//   }
// }