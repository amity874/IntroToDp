#include<bits/stdc++.h>
int calc(std::vector<int>&arr){
    int n=arr.size();
     std::vector<int>dp(n,0);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                dp[i]=std::max(dp[i],dp[j]+1);
            }
        }
    }
    return *(std::max_element(dp.begin(),dp.end()));
}
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::cout<<calc(arr);
return 0;
}