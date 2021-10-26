#include<bits/stdc++.h>
#define ll long long int
ll MaxCalories(std::vector<std::vector<ll>>&arr,int n,int m){
    std::vector<std::vector<ll>>dp1(1005,std::vector<ll>(1005,0));
    std::vector<std::vector<ll>>dp2(1005,std::vector<ll>(1005,0));
    std::vector<std::vector<ll>>dp3(1005,std::vector<ll>(1005,0));
    std::vector<std::vector<ll>>dp4(1005,std::vector<ll>(1005,0));
    //Precomputation
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp1[i][j]=arr[i][j]+std::max(dp1[i-1][j],dp1[i][j-1]);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            dp2[i][j]=arr[i][j]+std::max(dp2[i][j+1],dp2[i+1][j]);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            dp3[i][j]=arr[i][j]+std::max(dp3[i-1][j],dp3[i+1][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            dp4[i][j]=arr[i][j]+std::max(dp4[i-1][j],dp4[i][j+1]);
        }
    }
    //find all the ways to get maximum;
    ll ans=0;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            ll case1=dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1];
            ll case2=dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j];
            ans=std::max({ans,case1,case2});
        }
    }
    return ans;
}
int main(int argc, char const *argv[]){
ll n,m;
std::cin>>n>>m;
std::vector<std::vector<ll>>arr(n+1,std::vector<ll>(m+1,0));
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        std::cin>>arr[i][j];
    }
}
std::cout<<MaxCalories(arr,n,m);
return 0;
}