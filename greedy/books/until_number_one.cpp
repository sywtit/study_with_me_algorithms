#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

int main_3()
{
	//time_t start_time = time(0);
	
	int N, K;
	cin >> N >> K;

	int count = 0;

	//N이 K보다 값이 크면 계속 나누기
	while (N >= K)
	{
		if (N % K == 0)
			N /= K;
		else
			N -= 1;
		count++;
	}

	count += N - 1;

	cout << count << endl;
	/*
	time_t end_time = time(0);

	cout << "time : " << end_time - start_time << endl;
	time = 2*/

	return 0;
}