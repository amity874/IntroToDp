#include<bits/stdc++.h>
int main(int argc, char const *argv[]){
    std::string s;
    std::cin>>s;
    int n=s.size();
    std::vector<int>dp(n+1,0);
    std::unordered_map<char,int>Last;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=2*dp[i-1];
        if(Last[s[i-1]]>0){
            dp[i]=dp[i]-(dp[Last[s[i-1]]-1]);
        }
        Last[s[i-1]]=i;
    }
    std::cout<<dp[n]-1;
return 0;
}