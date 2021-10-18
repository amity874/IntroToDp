#include<bits/stdc++.h>
// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/maximum-sum-non-adjacent-elements-official/ojquestion
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    int incl=arr[0];
    int excl=0;
    for(int i=1;i<n;i++){
        int nincl=excl+arr[i];
        int nexcl=std::max(incl,excl);
        incl=nincl;
        excl=nexcl;
    }
    std::cout<<std::max(incl,excl);
return 0;
}