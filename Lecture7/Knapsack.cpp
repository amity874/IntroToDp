#include<bits/stdc++.h>
int main(int argc, char const *argv[]){
    int n,w;
    std::cin>>n>>w;
    std::vector<int>wt(n,0);
    std::vector<int>val(n,0);
    for(int i=0;i<n;i++){
        std::cin>>wt[i]>>val[i];
    }
    std::vector<int>dp1(w+1,0);
    std::vector<int>dp2(w+1,0);
    for(int i=0;i<n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i]>j){
                dp2[j]=dp1[j];
            }
            else{
                dp2[j]=std::max({dp2[j],dp1[j],val[i]+dp1[j-wt[i]]});
            }
        }
        dp2.swap(dp1);
        dp2.clear();
    }
    std::cout<<dp1[w];
return 0;
}