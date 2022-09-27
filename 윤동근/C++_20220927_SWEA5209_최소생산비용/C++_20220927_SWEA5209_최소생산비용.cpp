#include <iostream>
void Back_dfs(int L[][15], int n, int N, int cnt, int used[], int &min)
{
    if (n == N)
    {
        if (cnt < min)
            min = cnt;
        return;
    }
 
    for (int i = 0; i < N; i++)
    {
        if (used[i])        //이미 i번째 공장에서 생산중이면 넘어가기.
            continue;
        used[i] = 1;        //i 번째 공장 사용 체크.
        cnt += L[n][i];        // 현재까지 비용 더하기.
        if (cnt <= min)      //cnt가 min보다 커지면 시행 돌아가기
            Back_dfs(L, n + 1, N, cnt, used, min);  //cnt 가 min보다 작으면 계속 가보기.
        cnt -= L[n][i];
        used[i] = 0;
    }
}
 
int main(void) {
    int T,N, min;
    int L[15][15];
    int used[15] = { 0, };
    std::cin >> T;
    for (int q = 1; q <= T; q++)
    {
        min = 1500;
        std::cin >> N;
        for (int j = 0; j < N; j++) //used 초기화
            used[j] = 0;
        for(int i = 0; i < N; i++)        //L에 숫자 넣기.
            for (int j = 0; j < N; j++)
            {
                std::cin >> L[i][j];
            }
        Back_dfs(L, 0, N, 0, used, min);
        std::cout << '#' << q << ' ' << min <<'\n';
    }
    return 0;
}