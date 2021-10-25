#include<bits/stdc++.h>
#define mod  100
#define ll long long int
ll dp[10009][10009];
int sum(int *arr,int i,int j){
    int res=0;
    for(int k=i;k<=j;k++){
        res=(res%mod+arr[k]%mod)%mod;
    }
    return res;
}

ll mixtures(int *arr,int i,int j){
    if(i==j)return 0;
    if(abs((int)(i-j))==1){
        return arr[i]*arr[j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll result=INT_MAX;
    for(int k=i+1;k<=j;k++){
        ll retval=mixtures(arr,i,k-1)+mixtures(arr,k,j)+(sum(arr,i,k-1)*sum(arr,k,j));
        if(retval<result){
            result=retval;
        }
    }
    dp[i][j]=result;
    return result;
}
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    int *arr=new int[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::cout<<mixtures(arr,0,n-1);
return 0;
}