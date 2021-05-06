#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct student {
	string name;
	int korean_score;
	int english_score;
	int math_score;
}student;

bool compare(student left, student right) {
	if (left.korean_score > right.korean_score) return true;
	else if (left.korean_score == right.korean_score) {
		if (left.english_score < right.english_score) return true;
		else if (left.english_score == right.english_score) {
			if (left.math_score > right.math_score) return true;
			else if (left.math_score == right.math_score) {
				if (left.name < right.name) return true;
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}
int N;
vector<student> students;
int main() {
	//많은 조건들을 비교해서 pair보단 구조체 선언이 나을듯
	cin >> N;
	for (int i = 0; i < N; i++) {
		string name;
		int korean_score, english_score, math_score;

		cin >> name >> korean_score >> english_score >> math_score;
		students.push_back({ name,korean_score,english_score,math_score });

	}

	sort(students.begin(), students.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << students[i].name << '\n';
	}
	return 0;
}