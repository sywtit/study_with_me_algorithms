#include<iostream>
#include<algorithm>
int A[1001] = {0,};
int dpLeft[1001] = {0,};
int dpRight[1001] = {0,};

int main(){
    int N =0, result = 0;
    std::cin>>N;

    for(int i = 0; i<N; i++){
        std::cin>>A[i]; 
    }
    for(int i =0; i<N; i++){
        int max =0;
        for(int j = 0; j<i; j++){
            if(A[j]<A[i]) max = std::max({max, dpLeft[j]});
        }  
        dpLeft[i] = max+1;
    }
    for(int i = N-1; i>=0; i--){
        int max = 0;
        for(int j = N-1; j>i; j--){
            if(A[j]<A[i]) max = std::max({max,dpRight[j]});
        }
        dpRight[i] = max+1;
    }

    for(int i = 0; i<N; i++){
        result = std::max({result,dpLeft[i]+dpRight[i]-1});
    }

    std::cout<<result<<std::endl;
    return 0;
}