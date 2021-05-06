#include <iostream>
#include <unordered_map>
using namespace std;

int N;
int main() {
	cin >> N;
	unordered_map<long long , int> number_map;

	int max = -1;
	long long  max_number = 0;
	for (int i = 0; i < N; i++) {
		long long x;
		cin >> x;
		auto number = number_map.find(x);
		if (number != number_map.end()) {
			int cnt = number_map[x];
			number_map[x]++;
			if (max < cnt + 1) {
				max = cnt + 1;
				max_number = x;
			}
			else if (max == cnt + 1) {
				if (max_number > x) max_number = x;
			}
		}
		else {
			number_map.insert({ x,1 });
			if (max < 1) {
				max = 1;
				max_number = x;
			}
			else if (max == 1) {
				if (max_number > x) max_number = x;
			}
		}
	}

	cout << max_number<<'\n';
	return 0;


}