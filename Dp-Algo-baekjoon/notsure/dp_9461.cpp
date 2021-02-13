#include<iostream>

__int64 found[101] = {0,};

__int64 pado(int input){
    if(found[input]!=0){
        return found[input];
    }
    else{
    if(input<=3){ found[input] = 1; return 1;}
    else if(input >3 && input <=5) { found[input] = 2; return 2;}
    else {

        __int64 result = pado(input-1) + pado(input-5);
        found[input] = result;

        return result;
    }
    }
}

int main(){
    int T;
    std::cin>>T;
    for(int i=0; i<T; i++){
        int input = 0;
        std::cin>>input;
        std::cout<<pado(input)<<std::endl;
    }
}