#include <iostream>
#include <vector>
using namespace std;

int N;
int cnt;

void promising(vector<int> &cands, int i, vector< vector<int> > &vec)
{
  for (int j = 0; j < N; j++)
  {
    int k = 0;
    for (int p = 0; p < i + 1; p++)
    {
      if (vec[p][j] == 1)
      {
        k += 1;
        break;
      }
    }
    if (k != 0)
    {
      continue;
    }

    int ni = i - 1;
    int pj = j + 1;
    int mj = j - 1;

    while (true)
    {
      if (0 <= ni && ni < N)
      {
        if (0 <= pj && pj < N)
        {
          if (vec[ni][pj] == 1)
          {
            k += 1;
            break;
          }
          else 
          {
             pj += 1;
          }
        }

        if (0 <= mj && mj < N)
        {
          if (vec[ni][mj] == 1)
          {
            k += 1;
            break;
          }
          else
          {
            mj -= 1;
          }
        }
        ni -= 1;
      }
      else
      {
         break;
      }
    }

    if (k != 0)
    {
      continue;
    }
    cands.push_back(j);
  }
}

void checknode(int i, vector< vector<int> > &vec)
{
  if (i == N)
  {
    cnt += 1;
  }
  else
  {
    vector<int> cands;
    promising(cands, i, vec);
    for (int j = 0; j < cands.size(); j++)
    {
      vec[i][cands[j]] = 1;
      checknode(i + 1, vec);
      vec[i][cands[j]] = 0;
    }
  }
}

int main(void)
{
  cin >> N;
  vector< vector<int> > vec(N, vector<int>(N));
  cnt = 0;
  checknode(0, vec);
  cout << cnt;
}