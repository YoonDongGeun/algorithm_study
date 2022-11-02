#include <string>
#include <vector>

using namespace std;
void make(int n, int x, int now, int cnt, vector<int> &a, vector<int> &b, int &max_, vector<int> &c) // 경우의수 10점부터 0점까지 돌면서 계산하기.
{
    if(n<x)
    {
        return;
    }
    if(now==10)
    {
        if(max_>cnt)
        {
            max_ = cnt;
            for(int i=0; i<11; i++)
            {
                c[i] = a[i];
            }
        }
        else if(max_==cnt)
        {
            for(int i=10; 0<=i; i--)
            {
                if(c[i]<a[i])
                {
                    for(int i=0; i<11; i++)
                    {
                        c[i] = a[i];
                    }
                    return;
                }
                if(c[i]>a[i])
                {
                    return;
                }
            }
        }
        return;
    }

    //10점부터 0점까지 각각 점수 얻기vs점수 안얻기로 최소 2^10만큼 연산이 필요하다.
    make(n, x, now+1, cnt, a, b, max_, c); //10-now점 건너띄고 넘어가기. 
    a[now] += b[now];  
    if (b[now] == 1) //10-now점 얻고 넘어가기.
	{
		make(n, x + b[now], now + 1, cnt - 10 + now, a, b, max_, c);
	}
	else          //10-now점 얻고 넘어가기.
	{
		make(n, x + b[now], now + 1, cnt - 20 + now*2, a, b, max_, c);
	}
	a[now] -= b[now]; // 
    
}


vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11);
    vector<int> c(11);
    int max_=0, cnt=0;
    for(int i=0; i<11; i++)
    {
        if(info[i])
        {
            cnt += 10-i;
        }
        info[i]++;
    }
    
    make(n, 0, 0, cnt, answer, info, max_, c);
    if(max_ >= 0) // max_ 값에 변화가 없으면 경우가 없는 것이기 때문에 -1 반환. 
    {
        return {-1};
    }
    max_ = 0;
    for(int i=0; i<11; i++)
    {
        answer[i] = c[i];
        max_ += c[i];
    }
    answer[10] += n-max_;
    return answer;
}