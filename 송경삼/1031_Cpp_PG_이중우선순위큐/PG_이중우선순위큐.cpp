#include <string>
#include <vector>

using namespace std;


void swap(int *a,int*b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heappush(vector<int>& maxheap, vector<int>& minheap, vector<int>& maxidx, vector<int>& minidx, int ip) {
    int idx = maxheap.size();
    maxheap.push_back(ip);
	maxidx.push_back(idx);
    while (idx > 1 && maxheap[idx / 2] < maxheap[idx]) {
        swap(maxheap[idx / 2], maxheap[idx]);
		swap(maxidx[idx / 2], maxidx[idx]);
        idx /= 2;
    }
    int idx2 = minheap.size();
    minheap.push_back(ip);
	minidx.push_back(idx2);
    while (idx2 > 1 && minheap[idx2 / 2] > minheap[idx2]) {
        swap(minheap[idx2 / 2], minheap[idx2]);
		swap(minidx[idx2 / 2], minidx[idx2]);
        idx2 /= 2;
    }
}



void maxheappop(vector<int>& maxheap, vector<int>& minheap, vector<int>& maxidx, vector<int>& minidx) {
    int last_idx = maxheap.size() - 1;
	int min_idx_to_pop = minidx[maxidx[1]];

    swap(maxheap[1], maxheap[last_idx]);
	swap(maxidx[1], maxidx[last_idx--]);

    maxheap.pop_back();
	maxidx.pop_back();

    int idx = 1;
    while (1) {
        if ((last_idx >= (2 * idx + 1) && maxheap[2 * idx] >= maxheap[2 * idx + 1] && maxheap[idx] < maxheap[2 * idx]) || (last_idx == (2 * idx) && maxheap[2 * idx] > maxheap[idx])) {
            swap(maxheap[idx], maxheap[2 * idx]);
			swap(maxidx[idx], maxidx[2 * idx]);
            idx *= 2;
        }
        else if (last_idx >= (2 * idx + 1) && maxheap[2 * idx + 1] > maxheap[2 * idx] && maxheap[idx] < maxheap[2 * idx + 1]) {
            swap(maxheap[idx], maxheap[2 * idx + 1]);
			swap(maxidx[idx], maxidx[2 * idx + 1]);
            idx = 2 * idx + 1;
        }
        else break;
    }

	idx = min_idx_to_pop;
	last_idx = minheap.size() - 1;
	swap(minheap[idx], minheap[last_idx]);
	swap(minidx[idx], minidx[last_idx--]);
	minheap.pop_back();
	minidx.pop_back();

	if (idx > last_idx) return;
	while (idx > 1 && minheap[idx / 2] > minheap[idx]) {
		swap(minheap[idx / 2], minheap[idx]);
		swap(minidx[idx / 2], minidx[idx]);
		idx /= 2;
	}

	while (1) {
		if ((last_idx >= (2 * idx + 1) && minheap[2 * idx] <= minheap[2 * idx + 1] && minheap[idx] > minheap[2 * idx]) || (last_idx == (2 * idx) && minheap[2 * idx] < minheap[idx])) {
			swap(minheap[idx], minheap[2 * idx]);
			swap(minidx[idx], minidx[2 * idx]);
			idx *= 2;
		}
		else if (last_idx >= (2 * idx + 1) && minheap[2 * idx + 1] < minheap[2 * idx] && minheap[idx] > minheap[2 * idx + 1]) {
			swap(minheap[idx], minheap[2 * idx + 1]);
			swap(minidx[idx], minidx[2 * idx + 1]);
			idx = 2 * idx + 1;
		}
		else break;
	}

}

void minheappop(vector<int>& maxheap, vector<int>& minheap, vector<int>& maxidx, vector<int>& minidx) {
	int last_idx = minheap.size() - 1;
	int max_idx_to_pop = maxidx[minidx[1]];

	swap(minheap[1], minheap[last_idx]);
	swap(minidx[1], minidx[last_idx--]);

	minheap.pop_back();
	minidx.pop_back();

	int idx = 1;
	while (1) {
		if ((last_idx >= (2 * idx + 1) && minheap[2 * idx] <= minheap[2 * idx + 1] && minheap[idx] > minheap[2 * idx]) || (last_idx == (2 * idx) && minheap[2 * idx] < minheap[idx])) {
			swap(minheap[idx], minheap[2 * idx]);
			swap(minidx[idx], minidx[2 * idx]);
			idx *= 2;
		}
		else if (last_idx >= (2 * idx + 1) && minheap[2 * idx + 1] < minheap[2 * idx] && minheap[idx] > minheap[2 * idx + 1]) {
			swap(minheap[idx], minheap[2 * idx + 1]);
			swap(minidx[idx], minidx[2 * idx + 1]);
			idx = 2 * idx + 1;
		}
		else break;
	}


	last_idx = maxheap.size() - 1;
	idx = max_idx_to_pop;
	swap(maxheap[idx], maxheap[last_idx]);
	swap(maxidx[idx], maxidx[last_idx--]);
	maxheap.pop_back();
	maxidx.pop_back();


	if (idx > last_idx) return;
	while (idx > 1 && maxheap[idx / 2] > maxheap[idx]) {
		swap(maxheap[idx / 2], maxheap[idx]);
		swap(maxidx[idx / 2], maxidx[idx]);
		idx /= 2;
	}

	while (1) {
		if ((last_idx >= (2 * idx + 1) && maxheap[2 * idx] >= maxheap[2 * idx + 1] && maxheap[idx] < maxheap[2 * idx]) || (last_idx == (2 * idx) && maxheap[2 * idx] > maxheap[idx])) {
			swap(maxheap[idx], maxheap[2 * idx]);
			swap(maxidx[idx], maxidx[2 * idx]);
			idx *= 2;
		}
		else if (last_idx >= (2 * idx + 1) && maxheap[2 * idx + 1] > maxheap[2 * idx] && maxheap[idx] < maxheap[2 * idx + 1]) {
			swap(maxheap[idx], maxheap[2 * idx + 1]);
			swap(maxidx[idx], maxidx[2 * idx + 1]);
			idx = 2 * idx + 1;
		}
		else break;
	}

}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> maxheap(1, 0);
    vector<int> minheap(1, 0);
    vector<int> maxidx(1, 0);
	vector<int> minidx(1, 0);

    for (int a = 0; a < operations.size(); ++a) {
        if (operations[a] == "D 1" && maxheap.size()>1){
			maxheappop(maxheap, minheap, maxidx, minidx);
        }

        else if (operations[a] == "D -1" && minheap.size() > 1) {
			minheappop(maxheap, minheap, maxidx, minidx);
        }

        else if (operations[a][0]=='I'){
            string num(operations[a], 2, operations[a].length() - 2);
            int n = stoi(num);
            heappush(maxheap,minheap,maxidx,minidx, n);
        }

    }
    if (maxheap.size() > 1) answer.push_back(maxheap[1]);
    else answer.push_back(0);
    if (minheap.size() > 1) answer.push_back(minheap[1]);
    else answer.push_back(0);
    return answer;
}