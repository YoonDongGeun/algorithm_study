#include <iostream>
#include <cmath>
using namespace std;

int main(void){
  double A,B,V;
  cin >> A >> B >> V;
  int day = ceil((V - A) / (A - B));
  cout << day+1;
}