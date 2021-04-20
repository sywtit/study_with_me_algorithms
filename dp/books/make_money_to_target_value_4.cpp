#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int money[101] = { 0, };
int dp[10001] = { 0, };
int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> money[i];
	}

	fill_n(dp, 10001, 10001);

	//dp[M]를 구하자
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = money[i]; j <= M; j++) {
			if (dp[j - money[i]] != 10001)
				dp[j] = min(dp[j], dp[j - money[i]] + 1);
		}
	}

	if (dp[M] == 10001) cout << -1 << endl;
	else cout << dp[M] << endl;
	return 0;
}