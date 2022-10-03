# 20221003_Cpp_백준_1005_ACM Craft_송경삼

### 1. 문제

![](1003_Cpp_백준_1005_ACM%20Craft_assets/2022-10-04-02-04-45-image.png)

위상 정렬이란 개념을 배우고 난 이후라, 위상 정렬로 풀면 되겠구나 생각하고 풀이를 시작했습니다.

### 2. 나의 풀이

```cpp
#include <iostream>
#include <vector>
#include <queue>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, K, b_t[1001],cnt[1001]={0,}, time[1001]={0,}, s, e, end;
        std::vector <int> edges[1001];            
        std::queue <int> Q;

        scanf("%d %d", &N, &K);
        for (int n = 1; n <= N; ++n) scanf("%d", &b_t[n]);      
        while (K--) {
            scanf("%d %d", &s, &e);
            edges[s].push_back(e);
            ++cnt[e];
        }
        scanf("%d", &end);

        for (int i = 1; i <= N; ++i) {    //진입차수 배열을 돌면서 진입 차수가 0인 곳을 큐에 푸쉬해줍니다.
            if (!cnt[i]) {
                Q.push(i);
                time[i] = b_t[i];
            }
        }
        while (cnt[end]) {                  //도착점의 진입차수가 0이 될 때까지 진행
            s = Q.front();              
            Q.pop();
            for (int i = 0; i < edges[s].size(); ++i) {     //다음 도착점 목록을 보면서
                e = edges[s][i];                      
                if (time[s] + b_t[e] > time[e]) time[e] = time[s] + b_t[e];   //만약 더 오래걸리는 루트가있다면 갱신해줍니다
                if (!(--cnt[e])) {  //새로 진입차수가 0이 된 곳이 있다면 큐에 넣어줍니다.
                    Q.push(e);
                }
            }
        }
        printf("%d\n", time[end]);

    }

}
```

진입 차수가 0인 곳들을 queue에 push하고 앞에서부터 pop하면서 처리해서, 목표점의 진입차수가 0이 될 때까지 반복했습니다. 

문제를 풀면서 들었던 한가지 의문점은, 진입 차수가 0인 곳을 다 해결하면 정답에 필요없는 간선도 다 포함되어있으니 오히려 정답 가지들로만 해결을 빠르게 할 수 있지 않을까? 생각했었습니다. 그래서 문제를 풀고 난 이후에 정답지에서부터 역으로 탐색하는 것을 코딩해보자 생각했습니다.



### 3. 다른풀이와 비교

```cpp
//ㅋ
```

ㅁㄴ

### 4. 개선 및 후기

```cpp
#include <iostream>
#include <vector>

void BT(std::vector<int> edges[],int b_t[],int e, int sum, int *MAX) {
    if (edges[e].empty()) {
        if (sum > *MAX) *MAX = sum;
    }
    else {
        for (int i = 0; i < edges[e].size(); ++i) {
            BT(edges, b_t, edges[e][i], sum + b_t[edges[e][i]], MAX);
        }
    }

}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, K, b_t[1001], s, e, end, MAX=0;
        std::vector <int> edges[1001];
        scanf("%d %d", &N, &K);
        for (int n = 1; n <= N; ++n) scanf("%d", &b_t[n]);
        while (K--) {
            scanf("%d %d", &s, &e);
            edges[e].push_back(s);
        }
        scanf("%d", &end);
        BT(edges, b_t, end, b_t[end], &MAX);
        printf("%d\n", MAX);
    }
}
```

![](1003_Cpp_백준_1005_ACM%20Craft_assets/2022-10-04-02-03-53-image.png)

개선은 아니지만 풀이과정에서 들었던 의문점을 해결하기 위해 간단한 DFS를 사용했습니다. 정답지로 올 수 있는 루트를 다 검사해서 최장 루트 하나만 뽑아내는 알고리즘 입니다. 제가 풀이과정에 품었던 예상 결과와 달리 시간초과가 난 것을 볼 수 있습니다. 왜그럴까? 생각해보니 위상 정렬을 사용해 하나씩 해결하다보면 DFS를 사용해 검사할 루트들을 여러개씩 한번에 처리한다는 생각이 들었습니다. 따라서 도착점으로 가는 루트내에서의 조합 연산 수 >>> 도착 루트에 포함되지 않는 연산 수 라는 결론을 내렸습니다. 위상정렬이란 개념의 힘을 느낄 수 있는 문제였습니다.



###### *출처

https://www.acmicpc.net/problem/1005

- 잘못된 조건을 찾은 사람: [annaria](https://www.acmicpc.net/user/annaria)
- 문제를 만든 사람: [author1](https://www.acmicpc.net/user/author1)
- 데이터를 추가한 사람: [djm03178](https://www.acmicpc.net/user/djm03178), [doju](https://www.acmicpc.net/user/doju), [minshogi](https://www.acmicpc.net/user/minshogi), [zzaa9898](https://www.acmicpc.net/user/zzaa9898)
- 어색한 표현을 찾은 사람: [gorisanson](https://www.acmicpc.net/user/gorisanson)
- 잘못된 데이터를 찾은 사람: [tncks0121](https://www.acmicpc.net/user/tncks0121)
- 문제의 오타를 찾은 사람: [xivnick](https://www.acmicpc.net/user/xivnick)
- 빠진 조건을 찾은 사람: [yclock](https://www.acmicpc.net/user/yclock)
