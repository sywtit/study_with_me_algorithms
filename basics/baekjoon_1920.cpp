#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int M;
vector<int> A;

int binarySearch(int key) {

	int start = 0;
	int end = N - 1;
	int mid;

	while (end - start >= 0) {
		mid = (start + end) / 2;

		if (A[mid] == key) return 1;
		else if (A[mid] > key) end = mid - 1;
		else start = mid + 1;
	}
	return 0;
}
int main() {
	
	 scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int number = 0;
		scanf("%d", &number);
		A.push_back(number);
	}

	//그냥 탐색하면 시간 초과!
	/*cin >> M;
	for (int i = 0; i < M; i++) {
		int number = 0;
		cin >> number;
		
		if (find(A.begin(), A.end(), number) == A.end()) {
			cout << 0 << endl;
		}
		else {
			cout << 1 << endl;
		}
	
	}*/

	//이진 탐색 사용!
	sort(A.begin(), A.end());
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int number = 0;
		scanf("%d", &number);

		cout << binarySearch(number) << '\n';
	}

	return 0;

}