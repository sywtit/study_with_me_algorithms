#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> own;
int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf_s("%d", &x);
		own.push_back(x);
	}

	sort(own.begin(), own.end());

	scanf_s("%d", &M);
	for (int i = 0; i < M; i++) {
		int x;
		scanf_s("%d", &x);
		auto pos = binary_search(own.begin(), own.end(), x);

		if (pos) printf("1 ");
		else printf("0 ");
	}
	return 0;
}