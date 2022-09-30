#include <iostream>  //주소로 할때
#include <math.h>
 
struct pos {
    int y;
    int x;
};
struct now {
    int s;
    double cost;
};
double M[1001][1001], visited[1001][1001];
now Q[500000];                       // 큐
now *p = Q - 1;                     // 우선순위 구현하기 위한 주소 포인터
 
void push(now Q[], int a, double b); // 우선순위 큐 푸쉬
void pop(now Q[]);                   // 우선순위 큐 팝
 
 
 
int main(void)
{
    int T, N, position, cnt;
    double E, L, cost, price;
    long long A, dy, dx;
    pos island[1001];
    int visited[1001];
 
 
    std::cin >> T;
    for (int q = 1; q <= T; q++)
    {
        p = Q - 1;
        std::cin >> N;
        for (int i = 0; i < N; i++)
        {
            visited[i] = 0;
        }
        for (int i = 0; i < N; i++)
        {
            std::cin >> island[i].x;
        }
 
        for (int i = 0; i < N; i++)
        {
            std::cin >> island[i].y;
        }
 
        for (int i = 0; i < N; i++)
        {
            M[i][i] = -1;
        }
        std::cin >> E;                    //환경 부담율
        for (int i = 0; i < N; i++)                    //i섬에서 j섬으로 다리 지을때 비용 노드-간선 으로 만들기
        {
            for (int j = i + 1; j < N; j++)
            {
                dy = island[i].y - island[j].y;
                dx = island[i].x - island[j].x;
                L = std::sqrt(dy*dy + dx * dx);
                cost = E * L*L;
                M[i][j] = cost;
                M[j][i] = cost;
            }
        }
 
        push(Q, 0, 0);
        cnt = 0;
        price = 0;
        while (cnt != N)
        {
            L = Q[0].cost;
            position = Q[0].s;
            pop(Q);
            if (!visited[position])
            {
                cnt++;
                price += L;
                visited[position] = 1;
                for (int i = 0; i < N; i++)
                {
                    if (!visited[i])
                    {
                        push(Q, i, M[position][i]);
                    }
                }
            }
        }
        std::cout.precision(0);
        std::cout << std::fixed;
        std::cout << '#' << q << ' ' << price << '\n';
    }
    return 0;
}
 
 
 
 
void push(now Q[], int a, double b)
{
    if (Q > p)
    {
        p++;
        (*p).s = a;
        (*p).cost = b;
    }
    else
    {
        p++;
        (*p).s = a;
        (*p).cost = b;
        int now_index = p - Q;
        int parent_index = (now_index - 1) / 2;
        while (now_index)
        {
            if (Q[now_index].cost < Q[parent_index].cost)
            {
                now temp = Q[now_index];
                Q[now_index] = Q[parent_index];
                Q[parent_index] = temp;
                now_index = parent_index;
                parent_index = (parent_index - 1) / 2;
            }
            else
            {
                break;
            }
        }
    }
}
 
void pop(now Q[])
{
    Q[0] = (*p);
    p--;
    int now_index = 0;
    int child_index_left = 1;
    int child_index_right = 2;
    while (child_index_left <= p - Q)
    {
        if (p - Q < child_index_right)
        {
            if (Q[now_index].cost > Q[child_index_left].cost)
            {
                now temp = Q[now_index];
                Q[now_index] = Q[child_index_left];
                Q[child_index_left] = temp;
            }
            break;
        }
        if (Q[child_index_left].cost >= Q[child_index_right].cost)
        {
            if (Q[now_index].cost > Q[child_index_right].cost)
            {
                now temp = Q[now_index];
                Q[now_index] = Q[child_index_right];
                Q[child_index_right] = temp;
                now_index = child_index_right;
                child_index_left = (now_index + 1) * 2 - 1;
                child_index_right = (now_index + 1) * 2;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (Q[now_index].cost > Q[child_index_left].cost)
            {
                now temp = Q[now_index];
                Q[now_index] = Q[child_index_left];
                Q[child_index_left] = temp;
                now_index = child_index_left;
                child_index_left = (now_index + 1) * 2 - 1;
                child_index_right = (now_index + 1) * 2;
            }
            else
            {
                break;
            }
        }
    }
}