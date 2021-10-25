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
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>>grid(n,std::vector<int>(m,0));
    std::vector<std::vector<int>>dp(n,std::vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>grid[i][j];
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 && j==m-1){
                dp[i][j]=grid[i][j];
            }
            else if(i==n-1){
                dp[i][j]=grid[i][j]+dp[i][j+1];
            }else if(j==m-1){
                dp[i][j]=grid[i][j]+dp[i+1][j];
            }
            else{
                dp[i][j]=std::min(dp[i+1][j],dp[i][j+1])+grid[i][j];
            }
        }
    }
    std::cout<<dp[0][0]<<"\n";
    std::queue<Pair>qu;
    qu.push(Pair(0,0,""));
    while (!qu.empty()){
        Pair p=qu.front();
        qu.pop();
        if(p.i==n-1 && p.j==m-1){
            std::cout<<p.osf<<"\n";
        }
        else if(p.j==m-1){
         qu.push(Pair(p.i+1,p.j,p.osf+"V"));
        }
        else if(p.i==n-1){
         qu.push(Pair(p.i,p.j+1,p.osf+"H"));
        }
        else{
            if(dp[p.i][p.j+1]<dp[p.i+1][p.j]){
                qu.push(Pair(p.i,p.j+1,p.osf+"H"));
            }
            else if(dp[p.i][p.j+1]>dp[p.i+1][p.j]){
                qu.push(Pair(p.i+1,p.j,p.osf+"V"));
            }
            else{
                qu.push(Pair(p.i,p.j+1,p.osf+"H"));
                qu.push(Pair(p.i+1,p.j,p.osf+"V"));
            }
        }
    }
return 0;
}