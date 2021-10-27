#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    std::string s1;
    std::cin>>s1;
    int n=s1.size();
    int l1=0;
    std::string str="";
    std::vector<std::vector<int>>dp(n,std::vector<int>(n,0));
    for(int len=0;len<n;len++){
        for(int i=0,j=len;j<n;i++,j++){
            if(i==j){
                dp[i][j]=1;
            }
            else{
                if(s1[i]==s1[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else{
                    dp[i][j]=std::max(dp[i+1][j],dp[i][j-1]);
              }
            }
              if(dp[i][j] && (len + 1) > l1){
                    l1 = len + 1;
                    str =s1.substr(i,j+1);
                }
        }
    }
     std::cout<<str;
return 0;
}