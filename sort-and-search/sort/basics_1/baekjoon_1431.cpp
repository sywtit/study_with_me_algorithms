#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> guitar;

bool compare(string left, string right) {
	if (left.length() < right.length()) {
		return true;
	}
	else if (left.length() == right.length()) {
		//AÀÇ ÀÚ¸´¼ö, BÀÇ ÀÚ¸´¼ö
		int numA = 0, numB = 0;
		for (char a : left) {
			if (isdigit(a)) {
				numA += (int)(a - '0');
			}
		}
		for (char b : right) {
			if (isdigit(b)) {
				numB += (int)(b - '0');
			}
		}
		if (numA < numB) return true;
		else if (numA == numB) {
			/*
			vector<string> string_index;
			string_index.push_back(left);
			string_index.push_back(right);
			sort(string_index.begin(), string_index.end());
			if (string_index[0] == left) return true;
			else return false;
			*/
			return left < right;
		}
		else return false;
	}
	else {
		return false;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		guitar.push_back(input);
	}
	sort(guitar.begin(), guitar.end(), compare);
	
	for (string answer : guitar) {
		cout << answer << '\n';
	}
	
	return 0;
}