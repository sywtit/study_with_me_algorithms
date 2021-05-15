#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, r;
vector<int> v{ 1,2,3 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//먼저 오름 차순으로 정렬
	sort(v.begin(), v.end());

	do {
		for (auto it = v.begin(); it != v.end(); it++) {
			cout << *it << ' ';
		}
		cout << "\n";

	} while (next_permutation(v.begin(), v.end()));


	vector<int> data{ 1,2,3,4 };
	//n개 만큼 0의 값을 채워주고 1의 값을 r개 만큼 
	//채움
	vector<int> temp{ 1,1,0,0 };

	do {

		for (int i = 0; i < data.size(); i++) {
			if (temp[i] == 1) {
				cout << data[i] << ' ';
			}
		}
		cout << "\n";
	} while (prev_permutation(temp.begin(), temp.end()));

	return 0;
}

