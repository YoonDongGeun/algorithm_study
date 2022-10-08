#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void){
  stack<int> s;
  string str;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> str;
    if (str == "push"){
      int num;
      cin >> num;
      s.push(num);
    }
    else if (str == "pop"){
      if(!s.empty()){
        cout << s.top() << "\n";
        s.pop();
      } else cout << -1 << "\n";
    } else if (str == "size"){
      cout << s.size() << "\n";
    } else if (str == "empty"){
      if(s.empty()){
        cout << 1 << "\n";
      } else cout << 0 << "\n";
    } else {
      if (!s.empty()){
        cout << s.top() << "\n";
      }else cout << -1 << "\n";
    }

  }
  return 0;
}