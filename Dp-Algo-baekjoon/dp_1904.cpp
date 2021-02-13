#include<iostream>

__int64 fibonacci[1000001] = { 0, };
__int64 found[1000001] = { 0, };

__int64 countingNumber(__int64 T, __int64 I) {
    if (found[T]==1) {
        return fibonacci[T];
    }
    else {
        if (T <= 2) {
            fibonacci[T] = T;
            found[T] = 1;
            return T;
        }
        else {
            __int64 result = 0;
            __int64 result1 = 0, result2 = 0;

            result1 = countingNumber(T - 1, I); result2 = countingNumber(T - 2, I);

            result = (result1+ result2) % 15746;
            fibonacci[T] = result;
            found[T] = 1;

            return result;

        }
    }

}
int main_1904() {
    __int64 T;
    std::cin >> T;

    __int64 result;
    result = countingNumber(T,T);
    std::cout << result << std::endl;
    return 0;
}