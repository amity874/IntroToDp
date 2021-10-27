#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::vector<int>dp1(n,1);
    std::vector<int>dp2(n,1);
    for(int i=0;i<n;i++){
     int max=0;
        for(int j=0;j<i;j++){
            if(arr[i]>=arr[j]){
                dp1[i]=std::max(dp1[i],1+dp1[j]);
            }
        }
        
    }
    for(int i=n-1;i>=0;i--){
    int max2=0;
        for(int j=n-1;j>i;j--){
            if(arr[j]<=arr[i]){
                dp2[i]=std::max(dp2[i],dp2[j]+1);
            }
        }
    }
    int overallmax=0;
    for(int i=0;i<n;i++){
        if(dp1[i]+dp2[i]-1>overallmax){
            overallmax=dp1[i]+dp2[i]-1;
        }
    }
    std::cout<<overallmax;
return 0;
}