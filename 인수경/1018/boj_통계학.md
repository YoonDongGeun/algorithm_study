### 문제

수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.

1. 산술평균 : N개의 수들의 합을 N으로 나눈 값
2. 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
3. 최빈값 : N개의 수들 중 가장 많이 나타나는 값
4. 범위 : N개의 수들 중 최댓값과 최솟값의 차이

N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

### 입력

첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 단, N은 홀수이다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

### 출력

첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

둘째 줄에는 중앙값을 출력한다.

셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

넷째 줄에는 범위를 출력한다.



-------

저번 코드는 구조체를 이용해서 직접 정렬을 다 했었다. 입력값이 50만인걸 고려하지 않아 정렬 시간이 매우 오래걸려서 시간초과가 나왔다. 이번에는 정렬을 직접 하지 말라는 경삼님(스터디원)의 조언에 따라 카운트배열을 이용해서 각 숫자의 갯수만 카운팅한 후 각각의 값들을 찾았다.



#### **얻은 인사이트**

1. 초기화해야할 배열의 크기가 너무 클 경우 함수 안이 아니라 바깥에서 전역 변수로 사용할 것. 값이 너무 크면 파일이 실행이 안되기 때문.

2. int와 int로 나누기를 할 경우 소수점 아래가 아예 버림으로 처리됨. 소수점 반올림이 필요할 경우 두 숫자 중에 한 가지는 실수형으로 바꿀 것. 그래야 나누기를 했을 때 실수형으로 반환됨. (처음에 N과 avg를 둘다 int형으로 설정해서 평균값이 이상하게 나왔다.)

3. 실수형을 사칙연산해야할때는 float보다 double이 정확하므로 double을 사용할 것. (avg를 처음에는 float으로 설정했다가 40~50퍼에서 틀렸습니다가 나왔다.)


