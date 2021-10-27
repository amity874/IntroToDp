#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    int lsf=INT_MAX;
    int op=0;
    int pist=0;
    for(int i=0;i<n;i++){
        if(arr[i]<lsf){
            lsf=arr[i];
        }
        pist=arr[i]-lsf;
        if(pist>op){
            op=pist;
        }
    }
    std::cout<<op;
return 0;
}