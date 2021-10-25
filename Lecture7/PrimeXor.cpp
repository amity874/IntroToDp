#include<bits/stdc++.h>
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
int main(int argc, char const *argv[])
{
    ll max_xor=(1<<13)-1;
    std::vector<bool>isPrime(max_xor,true);
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i<=max_xor;i++){
        if(isPrime[i]){
            int j=i*2;
            while(j<=max_xor){
                isPrime[j]=false;
                j+=i;
            }
        }
    }
    ll q;
    std::cin>>q;
    while (q--){
        int n;
        std::cin>>n;
        std::vector<ll>Freq(4505,0);
        for(int i=0;i<n;i++){
            int x;
            std::cin>>x;
            Freq[x]++;
        }
        std::vector<std::vector<ll>> dp(2,std::vector<ll>(max_xor+5,0));
        dp[0][0]=1;
        int flag=1;
        for(int i=3500;i<=4500;i++){
            for(int j=0;j<=max_xor;j++){
                if(Freq[i]==0){
                    dp[flag][j]=dp[1-flag][j];
                }
                else{
                    dp[flag][j]=(dp[1-flag][j]*(Freq[i]/2+1)%mod+dp[1-flag][j^i]*((Freq[i]+1)/2)%mod)%mod;
                }
            }
            flag=1-flag;
        }
        ll res=0;
        for(int i=0;i<=max_xor;i++){
            if(isPrime[i]){
                res=(res+dp[1-flag][i])%mod;
            }
        }
        std::cout<<res<<"\n";
    }    
return 0;
}