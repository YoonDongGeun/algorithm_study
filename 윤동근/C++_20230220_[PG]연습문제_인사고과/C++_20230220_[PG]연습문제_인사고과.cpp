#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int comp(vector<int> a,vector<int> b){
    return a[0]<b[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    int scores_rows = scores.size();
    int score_list[200002] = {0,};
    vector<vector<int>> scores2;
    int target = scores[0][0]+scores[0][1];
    int targetx = scores[0][0];
    int targety = scores[0][1];
    for(int i=1; i<scores_rows; i++){
        if(scores[i][0]+scores[i][1] > target){
            scores2.push_back(scores[i]);
        }
    }
    scores_rows = scores2.size();
    sort(scores2.begin(), scores2.end(), comp);
    for(int i=0; i<scores_rows; i++){
        if(targetx < scores2[i][0] && targety < scores2[i][1]){
                return -1;
            } 
    }
    
    
    
    
    for(int i=0; i<scores_rows; i++){
        int check = 1;
        for(int j=scores_rows-1; j>i; j--){
            if(scores2[i][1] < scores2[j][1] && scores2[i][0] < scores2[j][0]){
                check=0;
                break;
            } 
        }
        if(check){
            score_list[scores2[i][0] + scores2[i][1]] += 1;
        }  
    }
    
    for(int i=200000; i>=0; i--){
        score_list[i] += score_list[i+1];
    }
    answer = score_list[target+1]+1;
    return answer;
}