#include<bits/stdc++.h>
int editDistance(std::string &s1,std::string &s2){
    int n=s1.size();
    int m=s2.size();
    std::vector<std::vector<int>> dp(n+1,std::vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+std::min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }
    }
    return dp[n][m];
}
int main(int argc, char const *argv[]){
    std::string s1="horse";
    std::string s2="ros";
    std::cout<<editDistance(s1,s2);
return 0;
}