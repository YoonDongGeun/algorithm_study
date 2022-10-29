#include <string>
#include <vector>

using namespace std;


string solution(string s) {
    string answer = "";
    string temp = "";
    int min = 1000000000;
    int max = -min;
    for (string::iterator a = s.begin(); a < s.end(); ++a) {
        if (*a == ' ') {
            int b = stoi(temp);
            if (b > max) max = b;
            if (b < min) min = b;
            temp = "";
        }
        else temp += *a;
    }
    int b = stoi(temp);
    if (b > max) max = b;
    if (b < min) min = b;
    answer = to_string(min) + " " + to_string(max);
    return answer;
}