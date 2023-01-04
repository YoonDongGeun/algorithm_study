#include <vector>
using namespace std;
vector<int> dx = {1, 0 , -1, 0};
vector<int> dy = {0, 1, 0, -1};

int search(vector<vector<int>> &board, vector<int> aloc, vector<int> bloc, int turn){
    int ny, nx;
    vector<int> &player = (turn%2)==0? aloc:bloc; //움직이는 플레이어 참조 변수로 설정
    if(board[player[0]][player[1]]==0){//현재 플레이어 위치가 0이면 turn 반환
        return turn;
    }
    
    int check =0;//check로 어느 방향 갈 수 있는지 가져오기.
    for(int i=0; i<4; i++){
        ny = player[0] + dy[i];
        nx = player[1] + dx[i];
        if(0<=ny && ny < board.size() && 0<= nx && nx < board[0].size() && board[ny][nx] == 1){
            check |= 1<<i;
        }
    }
    if(check==0){//check가 0이면 갈수 없으니 turn 반환
     return turn;   
    }
    
    board[player[0]][player[1]] = 0;
    vector<int> temp;
    for(int i=0; i<4; i++){
        if(check & 1<<i){//갈 수 있는 방향에 대해서 이동해보기
            player[0] += dy[i];
            player[1] += dx[i];
            temp.push_back(search(board, aloc, bloc, turn+1));
            player[0] -= dy[i];
            player[1] -= dx[i];
        }
    }
    board[player[0]][player[1]] = 1;
    int min_in2= -1;
    int min_in = 100;
    int check2 = 0;
    int now = turn%2;//현재턴 0 -> return값이 
    //어딜 가도 지는 상황 -> 상대방이 무조건 이긴다.
    for(int i=0; i<temp.size(); i++){
        if(now != temp[i]%2){
            check2 = 1;// temp[i]%2 값이 now와 같으면 패배하는곳, 다르면 승리하는곳. (승리하는 거 있으면 check2=1)
            if(min_in > temp[i]){
                min_in = temp[i]; // 승리한 곳 있을 때
            }
        }
        else{
            if(min_in2 < temp[i]){ //승리한 곳 없을 때
                min_in2 = temp[i];
            }
        }
    }
    if(check2==1){
        return min_in; // 이기는 거 있다.
    }
    return min_in2; //이기는 거 없다.
}


int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer;
    answer = search(board, aloc, bloc, 0);

    return answer;
}