#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> own;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		own.push_back(x);
	}

	sort(own.begin(), own.end());

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int x;
		scanf("%d", &x);
		printf("%d ", upper_bound(own.begin(), own.end(), x) - lower_bound(own.begin(), own.end(),x));
	}
	return 0;
}