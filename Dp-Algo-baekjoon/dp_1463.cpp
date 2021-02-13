#include<iostream>
#define MIN(a,b) ((a)<(b)?(a):(b))
#include<cmath>

int N = 0, count = 0;

int main_1463() {
    std::cin >> N;
    int arr[1000001] = { 0, };
    // arr[1] = 0;

    for (int i = 2; i <= N; i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0 && arr[i] >= arr[i / 2] + 1) arr[i] = arr[i / 2] + 1;
        if (i % 3 == 0 && arr[i] >= arr[i / 3] + 1) arr[i] = arr[i / 3] + 1;

    }

    std::cout << arr[N] << std::endl;
    return 0;
}