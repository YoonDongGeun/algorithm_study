#include <iostream>

int N;

//두 위치를 바꿔주는 함수입니다.
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//최대 힙 구조를 유지하면서 배열에 새로운 요소를 추가하는 함수입니다.
void push(int *heap,int idx, int num) {
	heap[idx] = num;
	while (idx >= 2 && heap[idx / 2] < heap[idx]) {
		swap(&heap[idx / 2], &heap[idx]);
		idx /= 2;
	}
}

//최대 힙 구조를 유지하면서 배열의 top을 교체하는 함수입니다.
void replace(int* heap,int idx, int num) {
	heap[1] = num;
	int a = 1;
	while (1) {
		if ((2 * a + 1 <= idx && heap[a]<heap[2 * a] && heap[2 * a]>=heap[2 * a + 1]) || (2 * a == idx && heap[a] < heap[2 * a])) {
			swap(&heap[2 * a], &heap[a]);
			a *= 2;
		}
		else if ((2 * a + 1 <= idx && heap[a] < heap[2 * a + 1] && heap[2 * a] < heap[2 * a + 1])) {
			swap(&heap[2 * a + 1], &heap[a]);
			a = 2 * a + 1;
		}
		else break;
	}
}


int main() {
	int max_heap[50005];
	int iM = 0;
	int min_heap[50005];
	int im = 0;
	int center;
	scanf("%d", &N);
	scanf("%d", &center);
	printf("%d\n", center);
	int sub;
	for (int n = 1; n < N; ++n) {
		scanf("%d", &sub);

		if (n % 2) { //새로운 항을 오른쪽 최소힙에 추가해야할 경우입니다.
			if (sub > center) {	//새로운 항이 중앙값보다 크다면 그냥 추가합니다.
				push(min_heap, ++im, -sub);
			}
			else if (iM==0 || sub > max_heap[1]) { //중앙값보다 작으나 왼쪽 최대힙의 top보다 크다면 중앙값을 교체하고 원래 중앙값을 오른쪽 최대힙에 추가합니다.
				push(min_heap, ++im, -center);
				center = sub;
			}
			else {	//왼쪽 최대힙의 top값보다 작다면 중앙값->오른쪽 최소 힙 에 추가, 왼쪽 top값 -> 중앙값 , 새로운 항 -> 왼쪽 최대 힙에 추가 합니다.
				push(min_heap, ++im, -center);
				center = max_heap[1];
				replace(max_heap, iM, sub);
			}
		}

		else { //새로운 항을 왼쪽 최대힙에 추가해야할 경우 위와 비슷하게 구성합니다.
			if (sub < center) {
				push(max_heap, ++iM, sub);
			}
			else if(im==0 || sub < -min_heap[1]) {
				push(max_heap, ++iM, center);
				center = sub;
			}
			else {
				push(max_heap, ++iM, center);
				center = -min_heap[1];
				replace(min_heap, im, -sub);
			}
		}
		printf("%d\n", center); //중앙값을 출력합니다.
	}
}