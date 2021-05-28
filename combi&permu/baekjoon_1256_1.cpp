#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
//201C101 조합의 개수
int dp[201][201];
int skip;

void solution(int x, int y, string answer) {

	//기저 사례
	if (skip < 0) return;
	if (x == 0 && y == 0) {
		if (skip == 0) cout << answer;
		skip--;
		return;
	}
	if (dp[x+y][y] <= skip) {
		skip -= dp[x + y][y];
		return;
	}
	if (x > 0) {
		solution(x - 1, y, answer + "a");
	}
	if (y > 0) {
		solution(x, y - 1, answer+"z");
	}

}
void makedp() {
	//0개를 뽑을 때나 mCm의 경우 값이 0인 것을 이용
	//이를 제외한 값들은 
	// mCn = m-1Cn + m-1Cn-1 방법을 이용한다.
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j) {
				dp[i][j] = 1;
				continue;
			}
			else {
				dp[i][j] = min(1000000000, dp[i - 1][j - 1] + dp[i - 1][j]);
			}
		}
	}
	return;
}
int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	//시간 제한을 맞추기 위해서 
	// mCn = m-1Cn + m-1Cn-1 방법을 이용한다.
	dp[0][0] = 1;
	makedp();

	//왜 k-1하는지 모르겟다.
	skip = k - 1;
	//dp의 값보다 skip값이 클 경우에 return -1
	if (dp[m + n][n] <= skip) {
		cout << "-1";
		return 0;
	}

	solution(n, m, "");
	return 0;

}

//https://chosh95.tistory.com/177