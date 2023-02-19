# 표현 가능한 이진트리

- darklight

- sublimevimemacs

- C++ 

###### 문제 설명

당신은 이진트리를 수로 표현하는 것을 좋아합니다.

이진트리를 수로 표현하는 방법은 다음과 같습니다.

1. 이진수를 저장할 빈 문자열을 생성합니다.
2. 주어진 이진트리에 더미 노드를 추가하여 포화 이진트리로 만듭니다. **루트 노드는 그대로 유지합니다.**
3. 만들어진 포화 이진트리의 노드들을 가장 왼쪽 노드부터 가장 오른쪽 노드까지, 왼쪽에 있는 순서대로 살펴봅니다. **노드의 높이는 살펴보는 순서에 영향을 끼치지 않습니다.**
4. 살펴본 노드가 더미 노드라면, 문자열 뒤에 0을 추가합니다. 살펴본 노드가 더미 노드가 아니라면, 문자열 뒤에 1을 추가합니다.
5. 문자열에 저장된 이진수를 십진수로 변환합니다.

**이진트리에서 리프 노드가 아닌 노드는 자신의 왼쪽 자식이 루트인 서브트리의 노드들보다 오른쪽에 있으며, 자신의 오른쪽 자식이 루트인 서브트리의 노드들보다 왼쪽에 있다고 가정합니다.**

다음은 이진트리를 수로 표현하는 예시입니다.

주어진 이진트리는 다음과 같습니다.
![제목 없는 다이어그램.drawio \(4\).png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/c3331b5f-2151-4ebd-a20e-8df122709d3e/%E1%84%8C%E1%85%A6%E1%84%86%E1%85%A9%E1%86%A8%20%E1%84%8B%E1%85%A5%E1%86%B9%E1%84%82%E1%85%B3%E1%86%AB%20%E1%84%83%E1%85%A1%E1%84%8B%E1%85%B5%E1%84%8B%E1%85%A5%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7.drawio%20%284%29.png)

주어진 이진트리에 더미노드를 추가하여 포화 이진트리로 만들면 다음과 같습니다. **더미 노드는 점선으로 표시하였고, 노드 안의 수는 살펴보는 순서를 의미합니다.**
![제목 없는 다이어그램.drawio \(5\).png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/0eb238be-9bfe-479a-bed8-84e1abe63097/%E1%84%8C%E1%85%A6%E1%84%86%E1%85%A9%E1%86%A8%20%E1%84%8B%E1%85%A5%E1%86%B9%E1%84%82%E1%85%B3%E1%86%AB%20%E1%84%83%E1%85%A1%E1%84%8B%E1%85%B5%E1%84%8B%E1%85%A5%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7.drawio%20%285%29.png)

노드들을 왼쪽에 있는 순서대로 살펴보며 0과 1을 생성한 문자열에 추가하면 `"0111010"`이 됩니다. 이 이진수를 십진수로 변환하면 58입니다.

당신은 수가 주어졌을때, 하나의 이진트리로 해당 수를 표현할 수 있는지 알고 싶습니다.

이진트리로 만들고 싶은 수를 담은 1차원 정수 배열 `numbers`가 주어집니다. `numbers`에 주어진 순서대로 하나의 이진트리로 해당 수를 표현할 수 있다면 1을, 표현할 수 없다면 0을 1차원 정수 배열에 담아 return 하도록 solution 함수를 완성해주세요.

------

##### 제한사항

- 1 ≤

   

  ```
  numbers
  ```

  의 길이 ≤ 10,000

  - 1 ≤ `numbers`의 원소 ≤ 1015

------

##### 입출력 예

| `numbers`     | `result`  |
| ------------- | --------- |
| [7, 42, 5]    | [1, 1, 0] |
| [63, 111, 95] | [1, 1, 0] |

------

##### 입출력 예 설명

**입출력 예 #1**

7은 다음과 같은 이진트리로 표현할 수 있습니다.
![제목 없는 다이어그램.drawio \(7\).png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/f7e1fdb9-3344-420d-9238-e033a24e83ba/%E1%84%8C%E1%85%A6%E1%84%86%E1%85%A9%E1%86%A8%20%E1%84%8B%E1%85%A5%E1%86%B9%E1%84%82%E1%85%B3%E1%86%AB%20%E1%84%83%E1%85%A1%E1%84%8B%E1%85%B5%E1%84%8B%E1%85%A5%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7.drawio%20%287%29.png)

42는 다음과 같은 이진트리로 표현할 수 있습니다.
![제목 없는 다이어그램.drawio \(7\).png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/f7e1fdb9-3344-420d-9238-e033a24e83ba/%E1%84%8C%E1%85%A6%E1%84%86%E1%85%A9%E1%86%A8%20%E1%84%8B%E1%85%A5%E1%86%B9%E1%84%82%E1%85%B3%E1%86%AB%20%E1%84%83%E1%85%A1%E1%84%8B%E1%85%B5%E1%84%8B%E1%85%A5%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7.drawio%20%287%29.png)

5는 이진트리로 표현할 수 없습니다.

따라서, [1, 0]을 return 하면 됩니다.

**입출력 예 #2**

63은 다음과 같은 이진트리로 표현할 수 있습니다.
![제목 없는 다이어그램.drawio \(8\).png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/ae334397-6cf6-4cb7-a76e-f760c080def3/%E1%84%8C%E1%85%A6%E1%84%86%E1%85%A9%E1%86%A8%20%E1%84%8B%E1%85%A5%E1%86%B9%E1%84%82%E1%85%B3%E1%86%AB%20%E1%84%83%E1%85%A1%E1%84%8B%E1%85%B5%E1%84%8B%E1%85%A5%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7.drawio%20%288%29.png)

111은 다음과 같은 이진트리로 표현할 수 있습니다.
![제목 없는 다이어그램.drawio \(10\).png](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/b6873b5d-421c-433e-a739-97f9ab1b62b8/%E1%84%8C%E1%85%A6%E1%84%86%E1%85%A9%E1%86%A8%20%E1%84%8B%E1%85%A5%E1%86%B9%E1%84%82%E1%85%B3%E1%86%AB%20%E1%84%83%E1%85%A1%E1%84%8B%E1%85%B5%E1%84%8B%E1%85%A5%E1%84%80%E1%85%B3%E1%84%85%E1%85%A2%E1%86%B7.drawio%20%2810%29.png)

95는 이진트리로 표현할 수 없습니다.

따라서, [1, 1, 0]을 return 하면 됩니다.

## 나의 풀이

```c++
#include <string>
#include <vector>


using namespace std;
bool Check(long long num);
long long Check2(long long num, long long arg, long long arg2);

vector<unsigned long long> powerList = {1};


bool Check(long long num){
    long long N=1;
    long long arg = 1;
    long long max_arg=1;
    // 자릿수 체크
    while(num > N){
        arg += 1;
        max_arg = powerList[arg]-1;
        N = powerList[max_arg]-1;
    }
    
    // 들어가는 자리 체크
        long long check_index = (max_arg/2);
        long long check_space = (check_index+1)/2;
        long long cnt1 = 0;
        for(int i=0; i<63; i++){
            if(num & (unsigned long long) 1<<i){
                cnt1++;
            }
        }
        if (cnt1 == Check2(num, check_index, check_space)){
            return 1;
        }
        else{
            return 0;
        }
        // 왜 위의 식 말고 바로 아래의 식으로 리턴하면 통과하지 못할까???... 알고싶다...
        //return (cnt1 == Check2(num, check_index, check_space))?1:0;

};

long long Check2(long long num, long long arg, long long arg2){
    
    if((0<=arg) && (arg < 63))
    {
        if (num & ((unsigned long long) 1 << arg)) {
            if (arg2 == 0) {
                return 1;
            }
            return 1 + Check2(num, arg - arg2, arg2 / 2) + Check2(num, arg + arg2, arg2 / 2);
        }
    }
    return 0;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    unsigned long long temp = 1;
    for(int i=1; i<64; i++){
        temp = temp*2;
        powerList.push_back(temp);
    }
    //2^1-1=1 최대값 2^1-1 들어가는지 체크하는 자리 2^0
    //2^2-1=3 최대값 2^3-1 들어가는지 체크하는 자리 2^1
    //2^3-1=7 최대값 2^7-1 들어가는지 체크하는 자리 2^3
    //2^4-1=15최대값 2^15-1  들어가는지 체크하는 자리 2^7
    //2^5-1=31
    //2^6-1=63
    // 1. 숫자의 범위체크하기(노드 높이체크)
    // 2. 숫자가 1이 반드시 들어가야하는 자리가 1인지 체크하기
    // 1<= numbers <= 10^15
    // 1<= numbers <= (2^15) * (5^15)
    // 1<= numbers <= 2^50;
    for(int i=0; i<numbers.size(); i++){
        answer.push_back(Check(numbers[i]));
    }
    
    return answer;
}
```

![image-20230115182424228](C++_20230115_%5BPG%5D2023KAKAO%20BLIND%20RECUITMENT_%ED%91%9C%ED%98%84%20%EA%B0%80%EB%8A%A5%ED%95%9C%20%EC%9D%B4%EC%A7%84%ED%8A%B8%EB%A6%AC.assets/image-20230115182424228.png)

제대로 된 풀이인데 계속 테스트 케이스 16~20번만 틀렸다. 그래서 혹시 범위의 문제인가 하고 unsigned long long으로 고치려 했는데 그것마저 안됐다. 그러다가 최대한 절차적으로 고쳐보려고 시도해 봤는데 3항 연산자를 쓰지 않으니 갑자기 정답으로 처리가 됐다. 그래서 대체 무엇이 문제인지 정말 알고 싶다..