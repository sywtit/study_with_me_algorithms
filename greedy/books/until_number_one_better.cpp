#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

int main()
{
	//time_t start_time = time(0);

	int N, K;
	int result = 0;
	cin >> N >> K;

	int count = 0;

	while (1) {
		//나누어 떨어지는 수가 되기 위해서 1씩 먼저 빼기
		int target = (N / K) * K;
		result += (N - target);

		N = target;

		if (N < K) break;

		//k로 나눔
		result += 1;
		N /= K;
	}

	result += N - 1;
	cout << result << endl;

	/*time_t end_time = time(0);
	cout << "time : " << end_time - start_time << endl;
	time = 1*/

	return 0;
}