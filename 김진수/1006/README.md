# 221006_TIL

## 구조체

여러 개의 데이터를 하나로 묶어 한꺼번에 다룰 수 있는 C언어의 문법

객체 지향 프로그래밍의 클래스와 유사한 역할을 한다.

```cpp
#include <stdio.h>
#include <stdlib.h>

// 1. 학생 정보 입력하기
struct student { // student 라는 구조체
	int number;
	char name[10];
	double grade;
};

int main(void)
{
	struct student s; // 구조체를 불러와서 정보를 쉽게 입력할 수 있다.
	
	printf("학번을 입력하세요 : ");
	scanf("%d", &s.number);
	printf("이름을 입력하세요 : ");
	scanf("%s", s.name);
	printf("학점을 입력하세요 : ");
	scanf("%lf", &s.grade);

	printf("학번 : %d\n", s.number);
	printf("이름 : %d\n", s.name);
	printf("학점 : %.1f\n", s.grade);
	return 0;
}

// 2. 두 점의 좌표 받기
struct point { // point 라는 구조체
	int x;
	int y;
};

int main(void)
{
	struct point p1, p2; // 구조체를 활용해서 2개 점의 좌표를 쉽게 입력받을 수 있다.
	int xDiff, yDiff;
	double distance;
	
	printf("1번 점의 좌표를 입력하세요 : ");
	scanf("%d %d", &p1.x, &p1.y);
	
	printf("2번 점의 좌표를 입력하세요 : ");
	scanf("%d %d", &p2.x, &p2.y);
	
	xDiff = p1.x - p2.x;
	yDiff = p1.y - p2.y;
	
	distance = sqrt(xDiff * xDiff + yDiff * yDiff);
	printf("두 점 사이의 거리는 %f입니다.\n", distance);
	return 0;
}
```

### 구조체의 활용

```cpp
#include <stdio.h>
#include <math.h>

// 1. 사각형의 넓이와 둘레 구하기
struct point { // point라는 구조체
	int x;
	int y;
};

struct rect { // 를 활용하는 구조체 rect
	struct point p1;
	struct point p2;
};

int main(void)
{
	struct rect r; // 구조체 rect 형태를 갖는 r 생성
	int w, h, area, peri;
	
	printf("왼쪽 상단의 좌표를 입력하세요 : ");
	scanf("%d %d", &r.p1.x, &r.p1.y);
	
	printf("오른쪽 하단의 좌표를 입력하세요 : ");
	scanf("%d %d", &r.p2.x, &r.p2.y);
	
	w = abs(r.p2.x - r.p1.x);
	h = abs(r.p2.y - r.p1.y);
	
	area = w * h;
	peri = 2 * w + 2 * h;
	
	printf("사각형의 넓이는 %d이고, 둘레는 %d입니다.", area, peri);
	return 0;
}

// 2. 사용자 정의 함수에 활용하기
struct point {
	int x;
	int y;
};

// 구조체를 활용한 사용자 정의 함수
void comparePoint (struct point p1, struct point p2) {
	if((p1.x == p2.x) && (p1.y == p2.y))
	{
		printf("p1과 p2가 같습니다.");
	}
}

int main(void)
{
	struct point p1;
	struct point p2;
	
	p1.x = 30;
	p1.y = 10;
	
	p2.x = 30;
	p2.y = 10;
	
// 이렇게 함수에 구조체를 활용하면 훨씬 간결한 코드 작성이 가능하다
	comparePoint(p1, p2);
	
	return 0;
 }

// 3. 구조체의 배열 만들기
#define SIZE 5

struct student {
	int number;
	char name[20];
	double grade;
};

int main(void)
{
	struct student list[SIZE]; // 구조체의 배열을 선언하여 각 학생별 정보를 담을 수 있다.
	int i;
	
	for(i = 0; i < SIZE, i++)
	{
		printf("학번을 입력하세요 : ");
		scanf("%d", &list[i].number);
		printf("이름을 입력하세요 : ");
		scanf("%s", &list[i].name);
		printf("학점을 입력하세요 : ");
		scanf("%lf", &list[i].grade);
	}
	
	for(i = 0; i < SIZE; i++)
	{
		printf("학번 : %d, 이름 : %s, 학점 : %lf", list[i].number, list[i].name, list[i].grade);
	}
	return 0;
}
```