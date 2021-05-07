#include <iostream>
#include <cmath>
using namespace std;

long long X, Y;
int main() {
	scanf_s("%lld %lld", &X, &Y);
	//Z가 절대 변하지 않을 경우	
	int Z = floor(double(Y)*100/double(X));
	if ((double(Y) * 100 / double(X)) >= 99) printf("-1");
	else {

		long long cnt = 0;
		long long result = -1;
		//이분 탐색!
		long long left = 1, right = 1000000000;
		while (left <= right) {
			long long mid = (left + right) / 2;
			long long val = (Y + mid) * 100 / (X + mid);
			if (Z+1 <= val) right = mid - 1, result = mid;
			else left = mid + 1;
		}
		printf("%lld", result);
	}
	
	return 0;
}
//https://zoomkoding.github.io/%EB%B0%B1%EC%A4%80/2019/09/30/baekjoon-1072.html