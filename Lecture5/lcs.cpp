#include<bits/stdc++.h>
#define ll long long int
int lcs(std::string s1,std::string &s2){
int n=s1.size();
int m=s2.size();
std::vector<std::vector<int>>dp(n+1,std::vector<int>(m+1));
for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
        if(i==0){
            dp[0][j]=0;
        }
        else if(j==0){
            dp[i][0]=1;
        }
        else{
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+(dp[i-1][j-1]);
            }
            else{
                dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
}
return dp[n][m];
}
int main(int argc, char const *argv[]){
    std::string s1,s2;
    std::cin>>s1>>s2;
   std::cout<<lcs(s1,s2);
return 0;
}