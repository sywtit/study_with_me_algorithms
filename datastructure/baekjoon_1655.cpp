#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int N;
int main() {
	cin >> N;

	//maxHeaap, minHeap을 이용한 tree에 다음과 같은 데이터가 담김
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);


		if (maxHeap.size() == 0) {
			maxHeap.push(x);
		}
		else {
			if (maxHeap.size() > minHeap.size()) {
				minHeap.push(x);
			}
			else {
				maxHeap.push(x);
			}

			//max Heap의 top값 최소 값보다 크면 값을 교환
			if (maxHeap.top() > minHeap.top()) {
				int maxtop = maxHeap.top();
				int mintop = minHeap.top();
				maxHeap.pop();
				minHeap.pop();
				maxHeap.push(mintop);
				minHeap.push(maxtop);
			}


		}
		
		cout << maxHeap.top() << '\n';

	}
}

//https://regularmember.tistory.com/142 참고