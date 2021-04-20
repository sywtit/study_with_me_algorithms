#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int dir[2] = { 0, };
int visited[1000001] = { 0, };

int bfs() {

	//내려가야 될때, 내려가는 버튼이 없을 경우
	if (S > G && D == 0) return -1;
	if (S < G && U == 0) return -1;

	queue<int> q;
	q.push(S);
	visited[S] = 1;

	while (!q.empty()) {
		int pos = q.front();

		if (pos == G) return visited[pos];
		q.pop();

		for (int i = 0; i < 2; i++) {
			int new_pos = pos + dir[i];
			if (new_pos > F || new_pos <= 0) continue;
			if (visited[new_pos]!=0) continue;

			visited[new_pos] = visited[pos] + 1;

			//while (1) {
			//	int button_push = visited[new_pos];
			//	new_pos += dir[i];

			//	//올라가는 경우 //내려가는 경우
			//	if (i == 0) {
			//		if (new_pos >= G || visited[new_pos]!= 0) {
			//			new_pos -= dir[i];
			//			break;
			//		}
			//		else {
			//			visited[new_pos] = button_push + 1;
			//		}

			//	}
			//	else {
			//		if (new_pos <= G || visited[new_pos]!=0) {
			//			new_pos -= dir[i];
			//			break;
			//		}
			//		else {
			//			visited[new_pos] = button_push + 1;
			//		}
			//	}
			//}
			q.push(new_pos);
		}
	}

	return -1;
}
int main() {

	cin >> F >> S >> G >> U >> D;

	dir[0] = U;
	dir[1] = -D;

	int answer = bfs();
	if (answer == -1) cout << "use the stairs" << endl;
	else cout << answer-1 << endl;

	return 0;


}