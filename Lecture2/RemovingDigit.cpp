#include<bits/stdc++.h>
using namespace std;
#define inf             1e18
std::vector<int> getDigit(int n){
    std::vector<int>digits;
    while (n){
        if(n%10!=0){
            digits.push_back(n%10);
        }
        n/=10;
    }
    return digits;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    std::vector<long long int>dp(n+1,inf);
    if(n<=9){
        cout<<1;
        return 0;
    }
    else{
        for(int i= 1;i<=9;i++){
            dp[i]=1;
        }
        for(int i=10;i<=n;i++){
            for(int digits:getDigit(i)){
                dp[i]=min(dp[i],1+dp[i-digits]);
            }
        }
        cout<<dp[n];
    }
return 0;
}