#include <string>
#include <vector>

using namespace std;

string beans(int generation, int idx)
{
    string tmp = "";
    int gen_tmp = (generation - 1) * 2;
    idx--;
    while (gen_tmp--)
    {
        tmp += to_string(idx % 2);
        idx /= 2;
    }
    for (int i = generation - 1; i >= 0; i--)
    {
        if (tmp[2 * i] == '1' && tmp[2 * i + 1] == '1') return "rr";
        if (tmp[2 * i] == '0' && tmp[2 * i + 1] == '0') return "RR";
    }
    return "Rr";
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    int cnt = queries.size();
    for (int i = 0; i < cnt; i++)
    {
        if (queries[i][0] == 1)
        {
            answer.push_back("Rr");
            continue;
        }
        answer.push_back(beans(queries[i][0], queries[i][1]));
    }
    return answer;
}