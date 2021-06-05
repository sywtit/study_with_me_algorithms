#include <iostream>
using namespace std;

int N, type;
long long K;
long long fiboValue[21] = { 0, };
bool visited[21] = { false, };
int key[21] = { 0, };
void get_fiboValue() {

	if (N == 1) {
		fiboValue[0] = 1;
	}
	else {
		for (int i = N ; i >= 1; i--) {
			long long  answer = 1;
			for (int j = 0; j < i; j++) {
				answer *= (i - j);
			}
			fiboValue[i] = answer;
		}
	}
	return;
}
void solution_1() {
	for (int i = N-1; i >= 1; i--) {
		int value = 0;
		if (K == fiboValue[i + 1]) value = (long long)K / fiboValue[i] - 1;
		else if (K == 1) value = 0;
		else if (K % fiboValue[i] == 0 && K / fiboValue[i] >= 1) value = (long long)K / fiboValue[i] - 1;
		else value = (long long)K / fiboValue[i];
		int j = 0;
		int index = 1;
		while (1) {
			if (!visited[index-1]) j++;
			if (value == j-1) {
				cout << index << " ";
				visited[index-1] = true;
				K = K - fiboValue[i] * value;
				break;
			}
			index++;
		}
	}
	int index = 0;
	while (1) {
		if (!visited[index]) {
			cout << index + 1 << '\n';
			return;
		}
		index++;
	}
	return;
}

void solution_2() {
	long long answer = 0;
	for (int i = 0; i < N-1; i++) {
		int each_key = key[i];
		int index = 0;
		int j = 0;
		while (1) {
			if (!visited[index]) j++;
			if (each_key-1 == index) break;
			index++;
		}
		answer += (long long)(j - 1) * fiboValue[N - 1 - i];
		visited[each_key - 1] = true;
	}
	cout << answer+1 <<'\n';
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//펙토리얼 값들을 집어 넣음
	cin >> N;
	get_fiboValue();

	cin >> type;
	if (type == 1) {
		cin >> K;
		solution_1();
		return 0;
	}
	else {
		for (int i = 0; i < N; i++) {
			cin >> key[i];
		}
		solution_2();
		return 0;
	}
	
}