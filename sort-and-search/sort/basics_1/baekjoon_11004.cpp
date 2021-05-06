#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> numbers;
int main() {
	//오름차순 정렬할 때 앞에서부터 K번째 있는 수
	//NlogN
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		numbers.push_back(x);
	}

	sort(numbers.begin(), numbers.end());
	printf("%d", numbers[K-1]);

	return 0;
}
