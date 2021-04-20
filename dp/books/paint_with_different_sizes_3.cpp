#include <iostream>
using namespace std;

int N;
int dp[1001] = { 0, };
int main() {
	cin >> N;

	//사실상 가로 = 1를 채우는 방법은 1가지
	//가로 = 2를 채우는 방법은 2가지
	dp[1] = 1;
	dp[2] = 3;
	
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 796796;
	}

	cout << dp[N] << endl;
	return 0;

}