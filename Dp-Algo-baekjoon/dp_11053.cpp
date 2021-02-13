#include<iostream>
// #include<algorithm>

// int A[1001] = {0,};
// int dp[1001] = {0,};

// int main(){
//     int N = 0,result =0;
//     std::cin>>N;

//     for(int i = 0; i<N; i++){
//         int max = 0;
//         std::cin>>A[i];

//         for(int j =0; j<i; j++){
//             if(A[i]>A[j]) max = std::max({max, dp[j]});
//         }
//         dp[i] = max+1;

//         result = std::max({result, dp[i]});
//     }

//     std::cout<<result<<std::endl;
//     return 0;
// }