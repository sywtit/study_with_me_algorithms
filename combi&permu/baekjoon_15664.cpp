#include<algorithm>
#include<iostream>
using namespace std;

bool check[8]; // 중복된 수를 고르지 않기 위한 배열
int n, m, num[8], result[8];

// 입력받은 n개의 수들 중에서 골랐던 수열과 똑같은 수열을
// 고르지 않게 m개를 고르고 출력해주는 함수
void getResult(int count, int start) {

    // m개를 골랐다면 출력합니다
    if (count == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    int prev_num = -1; // 바로 직전에 골랐던 수를 저장하는 변수

    // 함수의 인자로 받은 start부터 수를 골라야 합니다
    for (int i = start; i < n; i++) {
        if (!check[i] && prev_num != num[i]) {
            check[i] = true;
            result[count] = num[i];
            prev_num = num[i];

            getResult(count + 1, i);
            check[i] = false;
        }
    }
}

int main(void) {

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num, num + n);

    getResult(0, 0);
    return 0;
}

//https://seokeeee.tistory.com/152