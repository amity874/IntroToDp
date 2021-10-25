#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    int n;
    int count=0;
    std::cin>>n;
    if(n<=1){
        return n;
    }
    else{   
        for(int i=2;i<=n;i++){
            while (n%i==0){
                count+=i;
                n/=i;
            }
        }
    }
    std::cout<<count;
return 0;
}