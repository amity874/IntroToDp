#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    std::string s1;
    std::string s2;
    std::cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    std::vector<std::vector<int>>dp(n+1,std::vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int ans=dp[n][m];
    std::string res(ans,' ');
    int i=n,j=m;
    while (i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            res[ans-1]=s1[i-1];
            i--;
            j--;
            ans--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    std::cout<<res;
return 0;
}