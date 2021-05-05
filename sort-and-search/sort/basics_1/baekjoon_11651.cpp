#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> left, pair<int, int> right) {
	if (left.second < right.second) return true;
	else if (left.second == right.second) {
		if (left.first < right.first) return true;
		else return false;
	}
	return false;
}

int N;
int main() {
	cin >> N;

	//개수는 10만으로 적음
	vector<pair<int, int>> input;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		input.push_back({ x,y });
	}

	sort(input.begin(), input.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << input[i].first << " " << input[i].second << '\n';
	}

	return 0;
}