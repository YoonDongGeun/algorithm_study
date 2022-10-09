#include <iostream>
#include <string>

using namespace std;

int main(void){
  int s[10000] = {0,};
  string str;
  int n;
  cin >> n;
  int t = -1;
  for(int i=0; i<n; i++){
    cin >> str;
    if(str == "push"){
      int num;
      cin >> num;
      s[t+1] = num;
      t++;
    } 
    else if(str == "pop") {
      if (t != -1){
        cout << s[t] << "\n";
        t--;
      } else {
        cout << -1 << "\n";
      }
    } 
    else if(str == "size") {
      cout << t + 1 << "\n";
    } 
    else if(str == "empty") {
      if (t == -1){
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    } 
    else {
      if (t != -1){
        cout << s[t] << "\n";
      } else {
        cout << -1 << "\n";
      }
    }
  }
}