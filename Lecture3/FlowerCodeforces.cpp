#include<bits/stdc++.h>
// https://codeforces.com/problemset/problem/474/D
#define mod       1000000007
#define ll long long int
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
using namespace std;
int *CountWays(int k){
   int *dp=new int[100005]{0};
    dp[0]=1;
    for(int i=1;i<=100005;i++){
        if(i<k)dp[i]=dp[i-1];
        else{
            dp[i]=(dp[i-1]%mod+dp[i-k])%mod;
        }
    }
    for(int i=1;i<100005;i++){
        dp[i]=(dp[i]%mod+dp[i-1]%mod)%mod;
    }
    return dp;
}
int main(int argc,char const *argv[]){
    int t,k;
    cin>>t>>k;
    int *dp=CountWays(k);
// logarr(dp,0,20);
    while (t--){
        int a,b;
        cin>>a>>b;
        cout<<(dp[b]%mod-dp[a-1]%mod+mod)%mod<<"\n";
    }
return 0;
}