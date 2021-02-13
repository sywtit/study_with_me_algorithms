#include<iostream>
#include<string.h>
#define min(a,b) ((a)>(b)?(b):(a))


int getSmallCost(int** cost, int** found, int N) {

    found[0][0] = cost[0][0];
    found[0][1] = cost[0][1];
    found[0][2] = cost[0][2];


    for (int i = 1; i < N; i++)
    {
        found[i][0] = min(found[i - 1][1], found[i - 1][2]) + cost[i][0];
        found[i][1] = min(found[i - 1][0], found[i - 1][2]) + cost[i][1];
        found[i][2] = min(found[i - 1][0], found[i - 1][1]) + cost[i][2];
    }
    return  min(min(found[N-1][0], found[N-1][1]),found[N-1][2]);
   
}

int main_1149() {
    int N;
    std::cin >> N;
    int** cost = new int* [N];
    int** found = new int* [N];

    for (int i = 0; i < N; ++i) {
        cost[i] = new int[3];
        // memcmp(cost[i], 0, sizeof(int) * N);
    }//나중에 메모리 해제하는 거 알아야됨

    for (int i = 0; i < N; ++i) {
        found[i] = new int[3];
        memset(found[i], 0, sizeof(int) * 3);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> cost[i][j];
        }
    }

    std::cout << getSmallCost(cost, found, N) << std::endl;
    return 0;
}