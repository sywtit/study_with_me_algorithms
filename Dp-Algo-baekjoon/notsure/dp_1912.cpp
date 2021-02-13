#include<iostream>
#include<algorithm>

int main(){
    int n =0;
    int result = -1001;
    std::cin>>n;
    int array[100001] = {0,};
    int dp[100001] = {0,};

    for(int i =0; i<n; i++){
        int max =0;

        std::cin>>array[i];
        dp[i] += array[i];

        if(i>0) dp[i] = std::max({dp[i], dp[i-1]+array[i]});
        result = std::max({result, dp[i]});
    }

    std::cout<<result<<std::endl;
    return 0;

}