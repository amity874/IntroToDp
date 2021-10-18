#include<bits/stdc++.h>
#define ll long long int
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    int x;
    std::cin>>x;
    std::vector<int>coin(n,0);
    for(int i=0;i<n;i++){
        std::cin>>coin[i];
    }
    std::vector<int>dp(x+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            if(coin[i]>j){
                continue;
            }
            else{
               dp[j]+=dp[j-coin[i]];
            }
        }
    }
    std::cout<<dp[x];
return 0;
}