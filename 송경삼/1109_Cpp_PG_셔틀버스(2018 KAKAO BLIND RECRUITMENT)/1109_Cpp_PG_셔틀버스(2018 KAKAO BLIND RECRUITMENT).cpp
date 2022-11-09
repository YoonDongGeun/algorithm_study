#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int ans = 0;
	vector<int> cntbytime(1440, 0);

	for (int i = 0; i < timetable.size(); ++i) ++cntbytime[stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3, 2))];
	int bus_time = 9 * 60;
	int people_time = 0;
	int bus_n = 0;
	int people;


	while (++bus_n<=n) {
		people = 0;
		for (int time =people_time; time <= bus_time; ++time) {
			while (cntbytime[time]) {
				cntbytime[time]--;
				if(++people==m) break;
			}
			if (people == m) {
				people_time = time;
				break;
			}
			else {
				people_time = bus_time;
			}
		}
		bus_time += t;
	}
	if (people == m) people_time--;

	string hour = (people_time / 60) < 10 ? ("0" + to_string(people_time / 60)) : to_string(people_time / 60);
	string sec = (people_time % 60) < 10 ? ("0" + to_string(people_time % 60)) : to_string(people_time % 60);
	answer = hour + ":" + sec;
	return answer;
}

int main() {
	cout << solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" }) << "\n";
}