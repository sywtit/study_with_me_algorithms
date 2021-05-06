#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> numbers;
vector<int> sorted_numbers;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		numbers.push_back(x);
	}
	sorted_numbers = numbers;
	sort(sorted_numbers.begin(), sorted_numbers.end());
	sorted_numbers.erase(unique(sorted_numbers.begin(), sorted_numbers.end()), sorted_numbers.end());

	for (int i = 0; i < N; i++) {

		if(i < N-1)
			cout << lower_bound(sorted_numbers.begin(), sorted_numbers.end(), numbers[i]) - sorted_numbers.begin() << " ";
		else
			cout << lower_bound(sorted_numbers.begin(), sorted_numbers.end(), numbers[i]) - sorted_numbers.begin();
	}

	return 0;

}