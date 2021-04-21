#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, chart;
//student, value, time
vector<pair<int, pair<int,int>>> picture;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.first < b.first) return true;
	else return false;
}

int main() {
	cin >> N;
	cin >> chart;

	for (int i = 0; i < chart; i++) {
		int who = 0;
		cin >> who;

		int find = -1;
		for (int j = 0; j < picture.size(); j++) {
			if (picture[j].first == who) {
				find = j;
				break;
			}
		}

		if (find!=-1) {
			picture[find].second.first++;
		}
		else {
			//picture에 공간이 남았을 경우
			if (picture.size() < N) {
				picture.push_back({ who,{1,i} });
			}
			else {
				//추천받은 횟수가 가장 작은 학생의 사진을 삭제
				int min = 1001;
				int index = 0;
				for (int j = 0; j < picture.size(); j++) {
					if (min > picture[j].second.first) {
						index = j;
						min = picture[j].second.first;
					}
					else if (min == picture[j].second.first) {
						if (picture[index].second.second > picture[j].second.second) {
							index = j;
						}
					}
				}

				picture[index].first = who;
				picture[index].second.first = 1;
				picture[index].second.second = i;
				
			}
		}

	}

	//정렬
	sort(picture.begin(), picture.end(), compare);

	for (int i = 0; i < N; i++) {
		if (i == N - 1) cout << picture[i].first;
		else cout << picture[i].first << " ";
	}

	return 0;
}