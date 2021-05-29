//#include <iostream>
//using namespace std;
//
//int numbers[101] = { 0, };
//int n;
//int answer = 0;
//int dp[99][21];
//
//int main() {
//	/*ios::sync_with_stdio(0);
//	cin.tie();*/
//
//	cin >> n;
//	for (int i = 1; i < n+1; i++) {
//		scanf_s("%d", &numbers[i]);
//	}
//
//	dp[1][numbers[1]] = 1;
//	//조합을 구할 때 제일 
//
//	for (int i = 2; i <= n; i++) {
//		for (int j = 0; j <= 20; j++) {
//			if (dp[i - 1][j] >= 0) {
//				if (j - numbers[i] >= 0)
//					dp[i][j - numbers[i]] += dp[i - 1][j];
//				if (j + numbers[i] <= 20)
//					dp[i][j + numbers[i]] += dp[i - 1][j];
//			}
//		}
//	}
//
//	cout << dp[n - 1][numbers[n]] << endl;
//	return 0;
//	
//
//}


#include <iostream>
using namespace std;

int n;
int numbers[101] = { 0, };
unsigned long long dp[101][30] = { 0, };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
	}

	dp[1][numbers[1]] = 1;

	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] >= 0) {
				//중간에 나오는 수가 20 이하이고
				//음수가 나오면 안됨
				if (j - numbers[i] >= 0)
					dp[i][j - numbers[i]] += dp[i-1][j];
				if (j + numbers[i] <= 20)
					dp[i][j + numbers[i]] += dp[i-1][j];
			}
		}
	}

	cout << dp[n - 1][numbers[n]] << '\n';
	return 0;
}
//https://life-with-coding.tistory.com/184