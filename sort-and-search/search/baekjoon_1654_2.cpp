#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<long long> own;
vector<long long> answers;

void my_binary_search(long long start, long long end) {
	
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long cnt = 0;

		for (long long len : own) {
			cnt += len / mid;
		}

		if (cnt < N) {
			end = mid - 1;
		}
		else {
			answers.push_back(mid);
			start = mid + 1;
		}

	}
	return;
}
int main() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		long long x;
		scanf("%lld", &x);
		own.push_back(x);
	}

	sort(own.begin(), own.end());
	//ÃÖ´ë own[own.size()-1] -1;
	my_binary_search(1, own[own.size() - 1]);

	sort(answers.begin(), answers.end());
	printf("%lld", answers[answers.size() - 1]);
	return 0;
}