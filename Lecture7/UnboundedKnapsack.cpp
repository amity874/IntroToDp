#include<bits/stdc++.h>
int main(int argc, char const *argv[]){
    int n,w;
    std::cin>>n>>w;
    std::vector<int>wt(n,0);
    std::vector<int>val(n,0);
    for(int i=0;i<n;i++){
        std::cin>>wt[i]>>val[i];
    }
    std::vector<int>dp(w+1,0);
    for(int i=1;i<=w;i++){
    for(int j=0;j<n;j++){
        if(wt[j]>i){
            continue;
        }
        else{
            dp[i]=std::max(dp[i],dp[i-wt[j]]+val[j]);
        }
    }
    }
    std::cout<<dp[w];
return 0;
}