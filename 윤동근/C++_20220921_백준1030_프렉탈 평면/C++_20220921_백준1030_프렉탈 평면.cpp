#include <iostream>
using namespace std;
char M[51][51];

int main(void) {
    int s, N, K, R1, R2, C1, C2;            //시간, 배열크기, 검은상자크기, 행시작,행끝,열시작,열끝
    int a, b, c, x, y;
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
    int section[11] = {1,};
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
            M[i][j] = '0';                 // 0으로 초기화 
    }
    for (int i = 1; i <= s; i++)
    {
        section[i] = section[i - 1] * N;   //s값에 따라 패턴 사이즈들 저장. 
    }
    for (int w = 1; w <= s; w++)
    {
        a = section[w];                  // 패턴의 1변의 크기.
        b = ((a - K*section[w-1]) / 2); // 패턴과 한쪽 변 사이의 거리 
        c = a - b;                      // 패턴 반대쪽과 한쪽 변 사이의 거리. 
        for (int i = R1; i <= R2; i++)
        {
            for (int j = C1; j <= C2; j++)
            {
                y = i % a;               // 패턴 길이로 나눈 나머지를 통해서 칠한다. 
                x = j % a;
                if (b <= y && y < c && b <= x && x < c) // 만약 나눈값이 검은색 칠할 영역 이라면 '1'로 칠한다.
                {
                    M[i - R1][j - C1] = '1';
                }
            }
        }

    }
    for (int i = 0; i <= R2-R1; i++)
    {
        for (int j = 0; j <= C2-C1; j++)
        {
            cout << M[i][j];
        }
        cout << '\n';
    }

}