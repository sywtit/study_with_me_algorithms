#include<iostream>
#include<algorithm>
#include<cstring>
#include<array>

char first[1001] = { 0, };
char second[1001] = { 0, };
int dp[1001] = { 0, };

int main_9251() {


    std::cin >> first;
    std::cin >> second;
    int result = 0;

    for (int i = 0; i < strlen(first); i++) {
        int indexarr[1001] = { 0, };

        for (int j = 0; j < strlen(second); j++) {
            int max = 0;

            if (first[i] == second[j]) {

                for (int k = 0; k < j; k++) {
                    max = std::max({ dp[k],max });
                }

                indexarr[j] = max + 1;

            }
        }
        for (int ii = 0; ii < 1001; ii++) {
            if (indexarr[ii] != 0) {
                dp[ii] = indexarr[ii];
                result = std::max({ dp[ii],result });
            }
        }
    }

    std::cout << result << std::endl;
    return 0;

}