#include<iostream>
#include<string.h>
#define MAX(a,b) ((a)>=(b)?(a):(b))


int getMaxAdding(int** Triangle, int T) {

    int result = 0;

    int** MaxAdd = new int* [T + 1];
    MaxAdd[0] = new int[2];
    memcpy(MaxAdd[0], 0, sizeof(int) * 2);
    MaxAdd[1] = new int[2];
    memcpy(MaxAdd[1], 0, sizeof(int) * 2);

    for (int i = 2; i < T + 1; i++) {
        MaxAdd[i] = new int[i];
        memcpy(MaxAdd[i], 0, sizeof(int) * i);
    }

    MaxAdd[1][1] = Triangle[1][1];

    for (int i = 1; i <= T; i++) {
        for (int location = 1; location <= i; location++) {
            MaxAdd[i][location] = MAX(MaxAdd[i - 1][location - 1], MaxAdd[i - 1][location]) + Triangle[i][location];
        }
    }

    for (int location = 1; location <= T; location++) {
        if (result < MaxAdd[T][location]) result = MaxAdd[T][location];
    }


    // for (int i = T-1; i >=1; i--) {
    //     for (int location = 1; location <= i; location++) {
    //         Triangle[i][location] = MAX(Triangle[i + 1][location], Triangle[i + 1][location + 1]) + Triangle[i][location];
    //     }
    // }



// return Triangle[1][1];
    return result;

}

int main_1932() {
    int T;
    std::cin >> T;

    //다른 방법으로 Triangle 를 2차원 배열로 받아오는 방법
    int** Triangle = new int* [T + 1];
    for (int i = 0; i < T + 1; i++) {
        Triangle[i] = new int[i];
    }

    for (int i = 1; i < T + 1; i++) {
        for (int j = 1; j <= i; j++) {
            std::cin >> Triangle[i][j];
        }
    }


    std::cout << getMaxAdding(Triangle, T) << std::endl;

    return 0;

}