#include<bits/stdc++.h>
#define ll long long int
int main(int argc, char const *argv[]){
    ll n;
    std::cin>>n;
    ll s;
    std::cin>>s;
    std::vector<ll>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum<s){
        return 0;
    }
    ll m=(sum+s)/2;
    std::vector<std::vector<ll>>dp(n+1,std::vector<ll>(sum+1));
return 0;
}