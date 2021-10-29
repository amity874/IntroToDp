// https://leetcode.com/problems/russian-doll-envelopes/
#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<std::vector<int>>arr(n,std::vector<int>(2,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            std::cin>>arr[i][j];
        }
    }
    std::vector<int> dp(n,1);
    std::sort(arr.begin(),arr.end());
    int omax=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j][0]<arr[i][0]&&arr[j][1]<arr[i][1]){
                dp[i]=std::max(dp[i],1+dp[j]);
            }
        }
        if(omax<dp[i]){
                omax=dp[i];
            }
    }
    std::cout<<omax;
return 0;
}