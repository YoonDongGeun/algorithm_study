#include <iostream>


#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    int N;
    if (s == "1") return { 0, 0 };
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') ++answer[1];
    }
    answer[0]++;
    N = s.length() - answer[1];

    while (N != 1) {
        answer[0]++;
        int temp=0;
        for (int i = 0; (1 << i) <= N; ++i) {
            if (N & (1 << i)) ++temp;
            else answer[1]++;
        }
        N = temp;
    }
    return answer;
}


int main() {
    vector <int > a;
    a = solution("1");
    printf("%d %d", a[0], a[1]);
}