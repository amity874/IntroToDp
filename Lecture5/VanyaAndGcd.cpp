#include<bits/stdc++.h>
// https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/vanya-and-gcd-array/
#define mod             1000000007
#define ll long long int
ll gcd__(ll a,ll b){
    if(b>a){
        return gcd__(b,a);
    }
    if(b==0){
        return a;
    }
    return gcd__(b,a%b);
}
int main(int argc, char const *argv[])
{
    ll n;
    std::cin>>n;
    std::vector<ll>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::vector<std::vector<ll>>dp(n,std::vector<ll>(101,0));
    dp[0][arr[0]]=1;
    ll res=dp[0][1];
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j]){
                for(int g=1;g<=100;g++){
                    ll newgcd=gcd__(g,arr[i]);
                    dp[i][newgcd]=(dp[i][newgcd]%mod+dp[j][g]%mod)%mod;
                }
            }
        }
        dp[i][arr[i]]+=1;
        res=(res%mod+dp[i][1]%mod)%mod;
    }
    std::cout<<res<<"\n";
return 0;
}