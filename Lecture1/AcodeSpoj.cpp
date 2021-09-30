#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int main() {
 int dp[5003],i,j,k,sum;
 string s;
 cin>>s;
 while(s[0]!='0')
 {
     memset(dp,0,sizeof dp);
     dp[0]=1;
     i=1;
    int len=s.length();
     while(i<len){
         sum=(s[i-1]-'0')*10;
         k=s[i]-'0';
         sum+=k;
         if(k>0)
         {
             dp[i]+=dp[i-1];
         }
         if(sum>9&&sum<=26)
         {
         dp[i]+=dp[i-2<0?0:i-2];
         }
         i++;
     }
   cout<<dp[len-1]<<endl;
     cin>>s;
 }
 return 0;
}