#include <iostream>
#include <cmath>
using namespace std;

int arr[500000] = { 0, };

int main(void) {
    int cnt_arr[8001] = { 0, };
    int N;
    cin >> N;
    int k = 0;
    double avg = 0;
    int maxV = 0;
    int center = (N / 2) + 1;
    int oftenV = -5000;
    int val_max = 0;
    int val_min = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        avg += arr[i];
        cnt_arr[arr[i] + 4000]++;
    }

    if (round(avg / N) == -0)
        cout << 0 << '\n';
    else
        cout << round(avg / N) << '\n';

    
    for (int i = 0; i < 8001; i++) {
        if (cnt_arr[i] != 0)
            k += cnt_arr[i];

        if (k >= center) {
            cout << i - 4000 << '\n';
            break;
        }
    }

    for (int i = 0; i < 8001; i++) {
        if (cnt_arr[i] > maxV)
            maxV = cnt_arr[i];
    }

    for (int i = 0; i < 8001; i++) {
        if (cnt_arr[i] == maxV) {
            if (oftenV != -5000) {
                oftenV = i - 4000;
                break;
            }
            else
                oftenV = i - 4000;
        }
    }
    cout << oftenV << '\n';


    for (int i = 0; i < 8001; i++) {
        if (cnt_arr[i] != 0) {
            val_min = i - 4000;
            break;
        }
    }
    
    for (int i = 8000; i >= 0; i--) {
        if (cnt_arr[i] != 0) {
            val_max = i - 4000;
            break;
        }
    }

    cout << val_max - val_min << '\n';
}