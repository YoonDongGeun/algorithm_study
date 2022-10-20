#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int dd[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void change_vec(vector< vector<int> > &vec)
{
  vector< vector<int> > visited(N, vector<int>(M));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (vec[i][j] != 0)
      {
        visited[i][j] += 1;
        int cnt = 0;
        for (int p = 0; p < 4; p++)
        {
          int ni = i + dd[p][0];
          int nj = j + dd[p][1];
          if (ni >= 0 && ni < N && nj >= 0 && nj < M && vec[ni][nj] == 0 && visited[ni][nj] == 0)
          {
            cnt += 1;
          }
        }
        vec[i][j] -= cnt;
        if(vec[i][j] < 0) vec[i][j] = 0;
      }
    }
  }
}

void change_land(vector< vector<int> >&copy_vec,vector< vector<int> >&visited, int i, int j, int k){
  copy_vec[i][j] = k;
  visited[i][j] = 1;
  for (int p = 0; p < 4; p++){
    int ni = i + dd[p][0];
    int nj = j + dd[p][1];
    if (ni >= 0 && ni < N && nj >= 0 && nj < M && copy_vec[ni][nj] != 0 && visited[ni][nj] == 0){
      change_land(copy_vec, visited,ni,nj,k);
    }
  }
}

int main(void)
{
  cin >> N >> M;
  vector< vector<int> >vec(N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      int tmp;
      cin >> tmp;
      vec[i].push_back(tmp);
    }
  }

  int cnt = 0;

  while (true)
  {
    vector< vector<int> > copy_vec(N, vector<int>(M));
    vector< vector<int> > visited(N, vector<int>(M));
    copy(vec.begin(), vec.end(), copy_vec.begin());
    int k = 0;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        if (copy_vec[i][j] != 0 && visited[i][j] == 0)
        {
          k += 1;
          change_land(copy_vec, visited, i, j, k);
        }
      }
    }
    if (k == 0) { 
      cnt = 0;
      break;
    } else if (k >= 2) break;
    
    change_vec(vec);
    cnt += 1;
  }

  cout << cnt << '\n';
}