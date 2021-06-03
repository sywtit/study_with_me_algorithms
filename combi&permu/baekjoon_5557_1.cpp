#include <iostream>
using namespace std;

int N;
int input[101];
//dp[숫자 N개][나올 수 있는 값]
unsigned long long dp[101][21] = { 0, };

void solution() {

	dp[1][input[1]] = 1;

	for (int i = 2; i < N; i++) {
		for (int j = 0; j <= 20; j++) {
			//이전 값이 존재하는지 확인
			if (dp[i-1][j] >= 0) {
				//조건이 맞는지 확인
				if (j - input[i] >= 0) {
					dp[i][j - input[i]] += dp[i - 1][j];
				}
				if (j + input[i] <= 20) {
					dp[i][j + input[i]] += dp[i - 1][j];
				}
			}
		}
	}
	
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i < N+1; i++) {
		cin >> input[i];
	}

	//dp에 담을 값
	//dp[등식의 결과 값] = 경우의 수
	solution();

	cout << dp[N-1][input[N]] << '\n';
	return 0;
}