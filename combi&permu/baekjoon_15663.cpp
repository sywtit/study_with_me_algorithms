#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
bool check[8]; //중복된 수를 고르지 않기 위한 배열
int Nums[8], result[8];

void solve(int count) {
	
	//M개를 골랐다면 출력
	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int prev_num = -1;
	for (int i = 0; i < N; i++) {
		if (!check[i] && prev_num != Nums[i]) {
			check[i] = true;
			result[count] = Nums[i];
			prev_num = Nums[i];
			solve(count + 1);
			check[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> Nums[i];
		
		//순서와 상관없이 고르는 방법 with sort
	}

	sort(Nums, Nums + N);
	solve(0);
	return 0;

}

//https://seokeeee.tistory.com/151