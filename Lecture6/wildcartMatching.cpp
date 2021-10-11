#include<bits/stdc++.h>
// https://leetcode.com/problems/wildcard-matching/
int main(int argc, char const *argv[]){
    std::string text;
    std::string patt;
    std::cin>>text>>patt;
    std::vector<std::vector<bool>> dp(patt.size()+1,std::vector<bool>(text.size()+1,false));
    for(int i=dp.size()-1;i>=0;i--){
        for(int j=dp[0].size()-1;j>=0;j--){
            if(i==dp.size()-1 && j==dp[0].size()-1){
                dp[i][j]=true;
            }
            else if(j==dp[0].size()-1){
                if(patt[i]=='*'){
                    dp[i][j]=dp[i+1][j];
                }
                else{
                dp[i][j]=false;
                }
            }
            else if(i==dp.size()-1){
                dp[i][j]=false;
            }
            else{
                if(text[j]==patt[i]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else if(patt[i]=='?'){
                    dp[i][j]=dp[i+1][j+1];
                }
                else if(patt[i]=='*'){
                    dp[i][j]=dp[i][j+1] || dp[i+1][j];
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
    }
   if(dp[0][0]==1){
       std::cout<<true;
   }
   else{
       std::cout<<false;
   }
return 0;
}