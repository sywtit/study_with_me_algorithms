#include <iostream>
#include <algorithm>
using namespace std;
int X;
int dp[30001] = { 0, };
int get_one(int value) {
	
	if (value == 1) return 0;
	if (dp[value] != 0) return dp[value];
	
	int n1 = 30001, n2 = 30001, n3 = 30001, n4 = 30001;
	if (value % 5 == 0) {
		n1 = get_one(value / 5) + 1;
	}
	if (value % 3 == 0) {
		n2 = get_one(value / 3) + 1;
	}
	if (value % 2 == 0) {
		n3 = get_one(value / 2) + 1;
	}
	if (value - 1 >= 1) {
		n4 = get_one(value - 1) + 1;
	}
	int min_1 = min(n1, n2);
	int min_2 = min(n3, n4);

	return dp[value] = min(min_1, min_2);
	
}

int main() {
	cin >> X;

	////책의 풀이 
	//int d[30001];
	//// 다이나믹 프로그래밍(Dynamic Programming) 진행(보텀업)
	//for (int i = 2; i <= X; i++) {
	//	// 현재의 수에서 1을 빼는 경우
	//	d[i] = d[i - 1] + 1;
	//	// 현재의 수가 2로 나누어 떨어지는 경우
	//	if (i % 2 == 0)
	//		d[i] = min(d[i], d[i / 2] + 1);
	//	// 현재의 수가 3으로 나누어 떨어지는 경우
	//	if (i % 3 == 0)
	//		d[i] = min(d[i], d[i / 3] + 1);
	//	// 현재의 수가 5로 나누어 떨어지는 경우
	//	if (i % 5 == 0)
	//		d[i] = min(d[i], d[i / 5] + 1);
	//}
	//cout << d[X] << '\n';


	int answer = get_one(X);
	cout << answer << endl;
}