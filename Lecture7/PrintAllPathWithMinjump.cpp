#include<bits/stdc++.h>
#define inf            1e18
#define ll long long int
struct Pair{
    int i;
    int size;
    int jump;
    std::string osf;
    Pair(int i,int s,int j,std::string osf){
        this->i=i;
        this->size=s;
        this->jump=j;
        this->osf=osf;
    }
};
int main(int argc, char const *argv[]){
    ll n;
    std::cin>>n;
    std::vector<ll>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::vector<ll>dp(n,inf);
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--){
        ll min=inf;
        for(int j=1;j<=arr[i]&&i+j<n;j++){
            if(dp[i+j]!=inf && dp[i+j]<min){
                min=dp[i+j];
            }
        }
        if(min!=inf){
            dp[i]=min+1;
        }
    }
    std::cout<<dp[0]<<"\n";
    std::queue<Pair>qu;
    qu.push(Pair(0,arr[0],dp[0],std::to_string(0)+""));
    while (!qu.empty()){
        Pair p=qu.front();
        qu.pop();
        if(p.jump==0){
            std::cout<<p.osf+" . "<<"\n";
        }
        for(int j=1;j<=p.size&& j+p.i<n;j++){
            int ci=p.i+j;
            if(dp[ci]!=inf && dp[ci]==p.jump-1){
                qu.push(Pair(ci,arr[ci],dp[ci],p.osf+" -> "+std::to_string(ci)));
            }
        }
    }
    
return 0;
}