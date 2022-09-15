#include <iostream>
using namespace std;

int water[20][20] = { 0 };
int sharkx, sharky;
int shark = 2;
int cnt = 0;
int cnt2 = 0;
struct food {
    int x;
    int y;
    int size;
};
food foods[400] = { {500,500,500}, };
food *f = &foods[0];


void search(int N)
{
    int min = 401;
    int dis = 402;
    food *ff;
    int nx=1, ny=1;
    for (int i = 0; i <= f-foods; i++)
    {
        
        if (foods[i].size < shark)
        {
            dis = abs(sharkx - foods[i].x) + abs(sharky - foods[i].y);
            if (min >= dis)
            {
                
                if (min == dis)
                {
                    if (ny > foods[i].y)
                    {
                        ny = foods[i].y;
                        nx = foods[i].x;
                        ff = &foods[i];
                        
                    }
                    if (ny == foods[i].y & nx > foods[i].x)
                    {
                        nx = foods[i].x;
                        ny = foods[i].y;
                        ff = &foods[i];
                    }
                }
                else
                {    
                    nx = foods[i].x;
                    ny = foods[i].y;
                    ff = &foods[i];
                    min = dis;
                }
            }
        }

    }
    if (min != 400)
    {
        cnt = cnt + min;
        (*ff).size = 10;
        sharkx = (*ff).x;
        sharky = (*ff).y;
        cnt2++;
        if (cnt2 == shark)
        {
            shark = shark + 1;
            cnt2 = 0;
        }
        search(N);
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> water[i][j];
            if (water[i][j] !=0)
            {
                if (water[i][j] != 9)
                {
                    (*f).y = i;
                    (*f).x = j;
                    (*f).size = water[i][j];
                    f++;
                }
                else
                {
                    sharky = i;
                    sharkx = j;
                    water[i][j] = 0;
                }

            }
        }
    }
    search(N);
    cout << cnt;
}