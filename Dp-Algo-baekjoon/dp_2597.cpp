#include<iostream>
#define MAX(a,b) ((a)>(b)?(a):(b))

int stairs[302] = { 0, };
int MaxScore[302] = { 0, };

int getMaxScore(int T) {

    MaxScore[1] = stairs[1];
    MaxScore[2] = stairs[1] + stairs[2];

    for (int i = 3; i < T; i++) {
        if (MaxScore[i - 1] != stairs[i - 1] + MaxScore[i - 3]) {
            MaxScore[i] = MAX(MaxScore[i - 2], MaxScore[i-3] +stairs[i-1]) + stairs[i];
        }
        else {
            MaxScore[i] = MAX(MaxScore[i - 2], MaxScore[i - 1]) + stairs[i];
        }
    }

    if (MaxScore[T - 2] < MaxScore[T - 3] + stairs[T - 1]) {

        MaxScore[T - 1] = MaxScore[T - 3] + stairs[T - 1];
        MaxScore[T] = stairs[T] + MaxScore[T - 1];
    }
    else {
        MaxScore[T] = stairs[T] + MaxScore[T - 2];
    }

    return MaxScore[T];

}
int main_2597() {
    int T;
    std::cin >> T;

    for (int i = 1; i < T + 1; i++) {
        std::cin >> stairs[i];
    }

    std::cout << getMaxScore(T) << std::endl;

    return 0;

}