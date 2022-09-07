#include <iostream>
#include <vector>
 
int main() {
    int T;
    std::cin >> T;
    for (int t=1; t <= T;t++) {
        int N, CAN=1;
        std::cin >> N;
        std::vector<std::vector<int>> s(1, std::vector<int> {});    //2차원 벡터생성
        std::vector<int> sub;
 
        for (int i = 0; i < N; i++) {
            std::vector<std::vector<int>> SUB;      //갱신용 서브
            for (int q = 0; q < s.size(); q++) {    //s의 모든 경우를 순회하면서
                for (int j = 0; j < N; j++) {       //N보다 작은 값이 들어갈수있는지 볼겁니다.
                    sub = s[q];                     //현재 돌고 있는 s의 q번째 항입니다.
                    int t = j, b = j, can = 1;
 
                    if (sub.empty() != 1) {         //빈 벡터가 아니라면
                        for (int k = sub.size() - 1; k >= 0; k--) {
                            if (sub[k] == j or ++t == sub[k] or --b == sub[k]) {
                                can = 0;    //이번 j에 퀸이 들어갈 수 있는지 보고 들어갈수없다면 빠져나옵니다.
                                break;
                            }
                        }
                    }
                    if (can) {                  //빈벡터거나 들어갈수 있는 자리라면
                        sub.push_back(j);       //j를 추가해주고 SUB에 추가해줍니다.
                        SUB.push_back(sub);
                    }
                }
                }
                if (SUB.empty()) { CAN = 0; break; }    //만약 SUB가 비었다면 더이상 진행할수 없으므로 빠져나옵니다.
                else s = SUB;                           //아니라면 s를 SUB로 바꾸고 진행합니다.
 
            if (CAN==0) break;
        }
 
    std::cout << "#"<<t<<" "<< (CAN?s.size():0) << "\n";} 
     
}