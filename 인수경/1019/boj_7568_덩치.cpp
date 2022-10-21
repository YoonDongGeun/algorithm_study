#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int N;
  cin >> N;
  vector< vector<int> > vec(N, vector<int>(2));
  vector<int>res(N);
  for(int i=0; i < N; i++){
    cin >> vec[i][0] >> vec[i][1];
  }

  for(int i=0; i < N; i++){
    int k = 1;
    int w = vec[i][0];
    int h = vec[i][1];
    for(int j=0; j < N; j++){
      if (i == j){
        continue;
      } 
      else {
        int com_w = vec[j][0];
        int com_h = vec[j][1];
        if (com_w > w && com_h > h) k += 1;
      }
    }
    res[i] = k;
  }
  for(int i=0; i < N; i++){
    cout << res[i] << ' ';
  }
}