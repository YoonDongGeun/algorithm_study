#include <iostream>
using namespace std;

int main(void)
{
  int arr[100000];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int val;
  cin >> val;
  int cnt = 0;

  int s = 0;
  int e = n - 1;

  for (int i = s; i < n; i++){
    for (int j = e; j >= i; j--){
      if (arr[i]+arr[j] == val){
        cnt++;
      }
    }
  }
  cout << cnt << '\n';
}