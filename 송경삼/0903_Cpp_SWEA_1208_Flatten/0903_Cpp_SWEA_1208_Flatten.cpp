#include <iostream>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int t = 0,sub;
	while (t++ < 10) {
		int N;
		std::cin >> N;
		int cnt_arr[101]{};					//0으로 초기화 된 카운트 배열입니다.
		for (int i = 1; i <= 100; i++) {
			std::cin >> sub;
			cnt_arr[sub] +=1;				//인풋을 받으며 인덱스만큼의 높이가 몇개있는지 체크합니다.
		}
		sub = 0;
		for (int j = 100; j >= 1; j--) {	//거꾸로 돌며 해당 높이에 총 블럭이 몇개있는지 체크합니다.
			sub += cnt_arr[j];
			cnt_arr[j] = sub;
		}

		int B = 0, B_sum=0, T = 100, T_sum=0;	//T는 탑에서 바텀으로 , B는 바텀에서 탑으로 올라갑니다.
		
		while (B_sum <= N) { B_sum += 100 - cnt_arr[++B]; }	//바텀에서 채워갑니다.
		while (T_sum <= N) { T_sum += cnt_arr[T--]; }		//탑에서 비워갑니다.
		std::cout <<"#"<<t<<" "<< T - B+2 << "\n";

	}
}