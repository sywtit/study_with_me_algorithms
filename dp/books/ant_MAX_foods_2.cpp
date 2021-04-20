#include <iostream>
#include <algorithm>

using namespace std;
int N;
int k[101];
int dp[101] = { 0, };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> k[i];
	}

	dp[0] = k[0];
	dp[1] = max(k[0], k[1]);

	for (int i = 2; i < N; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + k[i]);
	}

	cout << dp[N - 1] << endl;
	return 0;
}