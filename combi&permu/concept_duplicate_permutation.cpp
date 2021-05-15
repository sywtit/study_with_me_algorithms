#include <iostream>
using namespace std;
#define MAX 100000

int n, r;
int ansArr[MAX] = { 0, };

void printArray(int* arr) {
	for (int i = 0; i < r; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';
	return;
}
void duplicate_permutation(int depth) {

	//±âÀú »ç·Ê
	if (depth == r) {
		printArray(ansArr);
		return;
	}

	for (int i = 1; i < n; i++) {
		ansArr[depth] = i;
		duplicate_permutation(depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r;
	duplicate_permutation(0);

	return 0;
}