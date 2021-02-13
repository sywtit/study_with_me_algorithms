// #include<iostream>

// int main(){
//     int N;
//     std::cin>>N;
//     __int64 arr[100] = {0,};

//     arr[0] = 9;

//     for(int i =1; i<N; i++){
//         arr[i] = (arr[i-1]*2-1)%1000000000;
//     }
//     std::cout<<arr[N-1]<<std::endl;
//     return 0;
// }

#include<iostream>

int main_10844() {
    int N = 0;
    std::cin >> N;

    __int64** arr = new __int64* [N];

    for (int i = 0; i < N; i++) {
        arr[i] = new __int64[10];
        memcpy(arr[i], 0, sizeof(__int64) * 10);
    }

    for (int j = 1; j < 10; j++) {
        arr[0][j] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) arr[i][j] += arr[i - 1][j + 1] % 1000000000;
            else if (j == 9) arr[i][j] += arr[i - 1][j - 1] % 1000000000;
            else {
                arr[i][j] += (arr[i - 1][j + 1] + arr[i - 1][j - 1]) % 1000000000;
            }
        }
    }

    __int64 result = 0;
    for (int i = 0; i < 10; i++) {
        result += arr[N - 1][i];
    }

    std::cout << result % 1000000000 << std::endl;
    return 0;

}
