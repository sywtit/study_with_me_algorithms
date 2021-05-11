#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//집의 개수, 공유기의 개수
int N, C;
vector<int> home;
int my_binary_search(int left, int right) {

	int answer = 0;

	while (left <= right) {
		
		//가장 인접한 두 공유기 사이의 거리
		int mid = (left + right) / 2;
		int start = home[0];
		int cnt = 1;

		for (int home_pos : home) {
			if (home_pos - start >= mid) {
				cnt++;
				start = home_pos;
			}
		}

		if (cnt >= C) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}

	}
	return answer;
}
int main() {
	cin >> N >> C;
	
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		home.push_back(x);
	}

	sort(home.begin(), home.end());

	int start = home[0];
	int end = home[home.size() - 1];
	int answer = my_binary_search(1,end - start);

	cout << answer << endl;
	return 0;
}