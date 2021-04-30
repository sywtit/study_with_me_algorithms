#include <iostream>
#include <functional>
#include <queue>

using namespace std;
int N;
int main() {
	scanf("%d", &N);

	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i = 0; i < N; i++) {
		long long x;
		scanf("%lld", &x);

		if (x == 0) {
			if (minHeap.size() == 0) cout << 0 << "\n";

			else {
				cout << minHeap.top() << "\n";
				minHeap.pop();
			}
		}
		else {
			minHeap.push(x);
		}
		
	}

	return 0;
}