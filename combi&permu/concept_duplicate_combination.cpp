#include <iostream>
using namespace std;
#define MAX 100000

int n, r;
int ansArr[MAX] = { 0, };

void printArray(int* arr) {
	for (int i = 0; i < r; i++) {
		cout << arr[i] << ' ';
	}
	cout << "\n";
	return;
}
void duplicate_combination(int depth, int next) {

	//±âÀú »ç·Ê
	if (depth == r) {
		printArray(ansArr);
		return;
	}

	//Àç±Í ÇÔ¼ö
	for (int i = next; i <= n; i++) {
		ansArr[depth] = i;
		duplicate_combination(depth + 1, i);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r;
	duplicate_combination(0, 1);
	return 0;
}

//https://hongchan.tistory.com/5