#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int N;
int main() {
	scanf("%d", &N);
	//maxheap delete and insert
	priority_queue<int, vector<int>, less<int>> maxHeap;
	//priority_queue<int> maxHeap µµ °¡´É

	//input
	for (int i = 0; i < N; i++) {
		long long x;
		scanf("%lld", &x);
		if (x == 0) {
			if (maxHeap.size() == 0) cout << 0 << "\n";
			else {
				cout << maxHeap.top() << "\n";
				maxHeap.pop();
			}
		}
		else {
			maxHeap.push(x);
		}

	}

	return 0;
}