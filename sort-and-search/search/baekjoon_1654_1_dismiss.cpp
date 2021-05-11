#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//필요한 랜선의 개수, 이미 가지고 있는 랜선의 개수
int N, K;
vector<long long> own;
vector<long long> answers;
void get_maximum_unit(long long divide_start, long long divide_end) {
	
	while(divide_start <= divide_end){
		
		long long mid = (divide_start + divide_end) / 2;
		long long unit = own[own.size() - 1] / mid;
		long long  cnt = 0;
		for (long long len : own) {
			cnt += len / unit;
		}

		if (cnt < N) {
			divide_start = mid + 1;

		}
		else{
			answers.push_back(unit);
			divide_end = mid - 1;
		}
	
	}
	return;

}
int main() {
	cin >> K >> N;
	
	for (int i = 0; i < K; i++) {
		long long x;
		scanf("%lld", &x);
		own.push_back(x);
	}

	//sort
	sort(own.begin(), own.end());

	get_maximum_unit(1, N);

	sort(answers.begin(), answers.end());
	cout << answers[answers.size() - 1];
	return 0;
}