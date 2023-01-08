#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') ++j;
        else if (s[i] == ')') --j;
        if (j < 0) return false;
    }
    return j ? false : true;

}
