#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<int, pair<int, string>> left, pair<int, pair<int, string>> right) {
	if (left.first < right.first) return true;
	else if (left.first == right.first) {
		if (left.second.first < right.second.first) return true;
		else return false;
	}
	return false;
}

int N;
int main() {
	cin >> N;

	//나이 //순서 //사람이름
	vector<pair<int, pair<int, string>>> people;

	for (int i = 0; i < N; i++) {
		int x;
		string name;
		cin >> x >> name;
		people.push_back({ x,{i,name} });
	}

	sort(people.begin(), people.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << people[i].first << " " << people[i].second.second << '\n';
	}

	return 0;
}