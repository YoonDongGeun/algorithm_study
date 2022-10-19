#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct pos {
  int x;
  int y;
};

bool cmp(pos a, pos b) {
  if (a.y == b.y)
    return a.x < b.x;
  else
    return a.y < b.y;
}

int main(void){
  pos cnt[500000];
  int arr[500000] = {0,};
  int N;
  float avg = 0;
  cin >> N;
  int idx = floor(N/2);
  int mostCnt = 0;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
    avg += arr[i];
    bool found = false;
    for (int t = 0; t<N; t++){
      if(cnt[t].x ==arr[i]){
        cnt[t].y++;
        found = true;
      }
    }
    if(!found){
      cnt[i].x = arr[i];
      cnt[i].y = 1;
    }
  }

  avg /= N;
  if (round(avg) == -0)
    cout << round(-avg) << '\n';
  else
    cout << round(avg) << '\n';

  sort(arr,arr+N);
  
  cout << arr[idx] << '\n';

  sort(cnt,cnt+N,cmp);

  mostCnt = cnt[N-1].y;

  for(int i = 0; i < N; i++){
    if(cnt[i].y == mostCnt){
      if(i != N-1)
        cout << cnt[i+1].x << '\n';
      else
        cout << cnt[i].x << '\n';
      break;
    }
  }
  
  cout << arr[N-1] - arr[0] << '\n';

}
