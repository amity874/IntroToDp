#include<bits/stdc++.h>
int lis(std::vector<char>&arr){
    int n=arr.size();
    std::vector<int>dp(n,1);
    for(int i=1;i<n;i++){
        for (int  j = 0; j<i;j++){
            if(arr[j]<arr[i]){
                dp[i]=std::max(dp[i],1+dp[j]);
            }
        }
        
    }
    return *(std::max_element(dp.begin(),dp.end()));
}
int lisOptimize(std::vector<char>&arr){
   int n=arr.size();
   std::vector<int>dp(n,1);
   std::map<int,int>mp;
   mp[arr[0]]=1;
   int ans=dp[0];
   for(int i=1;i<n;i++){
       auto it=mp.lower_bound(arr[i]+1);
       if(it!=mp.begin()){
           it--;
           dp[i]+=it->second;
       }
       mp[arr[i]]=dp[i];
       it=mp.upper_bound(arr[i]);//element to be deleted
       while (it!=mp.end() and it->second<=dp[i]){
           auto t=it;
           t++;
           mp.erase(it);
           it=t;
       }
       ans=std::max(ans,dp[i]);
   }
   return ans;
}
int main(int argc, char const *argv[])
{
    std::vector<char>arr={'B','A','C','B'};
    // std::vector<char>arr1={'B','A','C','B','B','B'};
    std::cout<<lis(arr)<<"\n";
    std::cout<<lisOptimize(arr);
return 0;
}