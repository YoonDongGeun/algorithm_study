```
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++)
  {
    int stop[5001];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int a, b;
      cin >> a >> b;
      for (int j = a; j <= b; j++)
      {
        stop[j]++;
      }
    }
    int p;
    cin >> p;
    int res[p];
    for (int i = 0; i < p; i++)
    {
      int tmp;
      cin >> tmp;
      res[i] = stop[tmp];
    }
    cout << "#" << tc << ' ';
    for (int i = 0; i < p; i++)
    {
      cout << res[i] << ' ';
    }
    cout << '\n';

    fill_n(stop, 5001, 0);
  }
}
```

cin, cout는 cpp의 scanf, printf이다.
cin에서 받아온 값을 변수에 담을 때는 >> 을 사용하고, 반대로 cout에서는 <<을 이용한다.
8번쨰 줄을 보면 변수 두개를 담기 위해 cin >> a >> b; 이런식으로 썼다.
cout에서 문자와 변수를 구분해줄때는 <<를 이용하면 된다. 그냥 문자열을 큰 따옴표 안에다 쓰면 된다.
마지막으로 배열을 초기화 할때는 fill_n()함수를 쓰며, fill_n(배열이름, 배열 크기, 초기화할 값)을 넣어주면 된다.
