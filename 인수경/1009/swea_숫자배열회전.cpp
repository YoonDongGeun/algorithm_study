#include <iostream>
#include <string>

using namespace std;

int main(void){
  int t;
  cin >> t;
  for(int i=1; i<=t; i++){
    int n;
    cin >> n;
    int arr[7][7] = {0,};
    string res[7][3];
    for(int p = 0; p < n; p++){
      for(int q = 0; q < n; q++){
        cin >> arr[p][q];
      }
    }

    for(int q = 0; q < n; q++){
      string tmp;
      for (int p = n-1; p >= 0; p--){
        tmp += to_string(arr[p][q]);
       
      }
      res[q][0] = tmp;
    }

    for(int p=n-1; p >=0; p--){
      string tmp;
      for (int q = n-1; q >=0; q--){
        tmp += to_string(arr[p][q]);
      }
      res[n-p-1][1] = tmp;
    }

    for (int q=n-1; q >=0; q--){
      string tmp;
      for(int p = 0; p < n; p++){
        tmp += to_string(arr[p][q]);
      }
      res[n-q-1][2] = tmp;
    }

    cout << "#" << i << '\n';
    for (int p = 0; p < n; p++){
      for (int q = 0; q < 3; q++){
        cout << res[p][q] << ' ';
      }
      cout << '\n';
    }

  }
}