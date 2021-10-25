#include<bits/stdc++.h>
struct Pair{
    int i;
    int j;
    std::string osf;
    Pair(int i,int j,std::string osf){
        this->i=i;
        this->j=j;
        this->osf=osf;
    }
};
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<int>wt(n,0);
    std::vector<int>val(n,0);
    for(int i=0;i<n;i++){
        std::cin>>val[i];
    }
    for(int i=0;i<n;i++){
        std::cin>>wt[i];
    }
    int w;
    std::cin>>w;
   std::vector<std::vector<int>>dp(n+1,std::vector<int>(w+1,0));
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            if(j<wt[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=std::max({dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]});
            }
        }
    }
    std::cout<<dp[n][w]<<"\n";
    std::queue<Pair>qu;
    qu.push(Pair(n,w,""));
    while(not qu.empty()){
        Pair p=qu.front();
        qu.pop();
        if(p.i==0 || p.j==0){
            std::cout<<p.osf<<"\n";
        }else{
            int excl=dp[p.i-1][p.j];
            if(p.j>=wt[p.i-1]){
            int incl=dp[p.i-1][p.j-wt[p.i-1]]+val[p.i-1];
            if(incl==dp[p.i][p.j]){
                qu.push(Pair(p.i-1,p.j-wt[p.i-1],std::to_string(p.i-1)+" "+p.osf));
            }
            }
            if(excl==dp[p.i][p.j]){
                qu.push(Pair(p.i-1,p.j,p.osf));
            }
        }
    }
return 0;
}