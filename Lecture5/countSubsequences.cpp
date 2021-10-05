#include<bits/stdc++.h>
int main(int argc, char const *argv[]){
    std::string s;
    std::cin>>s;
    std::vector<std::vector<int>>dp(3,std::vector<int>(s.size(),0));
    if(s[0]=='a'){
        dp[0][0]=1;
    }
    else if(s[0]=='b'){
        dp[1][0]=1;
    }
    else{
        dp[2][0]=1;
    }
    for(int i=1;i<s.size();i++){
           if(s[i]=='a'){
               dp[0][i]=1+2*dp[0][i-1];
           }
           else{
               dp[0][i]=dp[0][i-1];
           }
           if(s[i]=='b'){
               dp[1][i]=dp[0][i-1]+2*dp[1][i-1];
           }
           else{
               dp[1][i]=dp[1][i-1];
           }
           if(s[i]=='c'){
               dp[2][i]=dp[1][i-1]+2*dp[2][i-1];
           }
           else{
               dp[2][i]=dp[2][i-1];
           }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<s.size();j++){
            std::cout<<dp[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    // std::cout<<dp[2][s.size()-1];
    // int a=0;
    // int ab=0;
    // int abc=0;
    // for(int i=0;i<s.size();i++){
    //     if(s[i]=='a'){
    //         a=2*a+1;
    //     }
    //     else if(s[i]=='b'){
    //         ab=2*ab+a;
    //     }
    //     else if(s[i]=='c'){
    //         abc=2*abc+ab;
    //     }
    // }
    // std::cout<<abc;
return 0;
}