#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    std::string s;
    std::cin>>s;
    std::vector<std::vector<int>>dp(2,std::vector<int>(s.size(),0));
    dp[0][1]=1;
    dp[1][1]=1;
    for(int i=2;i<s.size();i++){
        if(s[i-1]=='0'){
        dp[0][i]=dp[0][i-1];
        }
        else if(s[i-1]='1'){
        dp[1][i]=dp[1][i-1];
        }
    }
    std::cout<<dp[0][s.size()-1]+dp[1][s.size()-1];
return 0;
}