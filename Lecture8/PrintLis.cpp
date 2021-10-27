#include<bits/stdc++.h>
struct Pair{
    int i;
    int len;
    int val;
    std::string osf;
    Pair(int i,int len,int val,std::string osf){
        this->i=i;
        this->len=len;
        this->val=val;
        this->osf=osf;
    }
};
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    int overallmax=0;
    int maxidx=0;
    std::vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<=arr[i]){
                dp[i]=std::max(dp[i],1+dp[j]);
            }
        }
        if(overallmax<dp[i]){
            overallmax=dp[i];
            maxidx=i;
        }
    }
    std::cout<<overallmax<<"\n";
    std::queue<Pair>qu;
   for(int i=0;i<n;i++){
       if(dp[i]==overallmax){
           qu.push(Pair(i,overallmax,arr[i],std::to_string(arr[i])+""));
       }
   }
   while (!qu.empty()){
       Pair p=qu.front();
       qu.pop();
       if(p.len==1){
           std::cout<<p.osf<<"\n";
       }
       for(int j=p.i;j>=0;j--){
           if(dp[j]==p.len-1&& arr[j]<=p.val){
               qu.push(Pair(j,dp[j],arr[j],std::to_string(arr[j])+" -> "+p.osf));
           }
       }
   }
return 0;
}