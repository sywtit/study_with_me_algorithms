#include <iostream>
#include <algorithm>
using namespace std;

int N;
bool cnt[2000002] = { false, };
int main() {
	//100만 이하의 숫자
	//counting sort? with bool data type
	cin >> N;
	int different = 1000001;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		if (x < 0) x = abs(x);
		else x += different;

		if (!cnt[x]) cnt[x] = true;
	}

	for (int i = 1000000; i >0 ; i--) {
		if (cnt[i]) cout << -i << '\n';
	}
	for (int i = 1000001; i <= 2000001; i++) {
		if (cnt[i]) cout << i- 1000001 << '\n';
	}
	return 0;
	
}