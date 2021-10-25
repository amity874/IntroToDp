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
    for(int j=m-1;j>=0;j--){
        for(int i=0;i<n;i++){
            if(j==m-1){
                dp[i][j]=grid[i][j];
            }
            else if(i==n-1){
                dp[i][j]=grid[i][j]+std::max(dp[i][j+1],dp[i-1][j+1]);
            }
            else if(i==0){
                dp[i][j]=grid[i][j]+std::max(dp[i+1][j+1],dp[i][j+1]);
            }
            else{
                dp[i][j]=std::max({dp[i-1][j+1],dp[i][j+1],dp[i+1][j+1]})+grid[i][j];
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        res=std::max(dp[i][0],res);
    }
    std::cout<<res<<"\n";
    std::queue<Pair>qu;
    for(int i=0;i<n;i++){
        if(dp[i][0]==res){
            qu.push(Pair(i,0,std::to_string(i)+" "));
        }
    }
    while (!qu.empty()){
        Pair p=qu.front();
        qu.pop();
        if(p.j==m-1){
            std::cout<<p.osf<<"\n";
        }
        else if(p.i==n-1){
            int res=std::max(dp[p.i-1][p.j+1],dp[p.i][p.j+1]);
            if(res==dp[p.i-1][p.j+1]){
                qu.push(Pair(p.i-1,p.j+1,p.osf+"d1 "));
            }
            if(res==dp[p.i][p.j+1]){
                qu.push(Pair(p.i,p.j+1,p.osf+"d2 "));
            }
        }
        else if(p.i==0){
            int res=std::max(dp[p.i][p.j+1],dp[p.i+1][p.j+1]);
            if(res==dp[p.i][p.j+1]){
                qu.push(Pair(p.i,p.j+1,p.osf+"d1 "));
            }
            if(res==dp[p.i+1][p.j+1]){
                qu.push(Pair(p.i+1,p.j+1,p.osf+"d2 "));
            }
        }
        else{
            int res=std::max({dp[p.i][p.j+1],dp[p.i+1][p.j+1],dp[p.i-1][p.j+1]});
            if(res==dp[p.i-1][p.j+1]){
                qu.push(Pair(p.i-1,p.j+1,p.osf+"d1 "));
            }
            if(res==dp[p.i][p.j+1]){
               qu.push(Pair(p.i,p.j+1,p.osf+"d2 "));
            }
            if(res==dp[p.i+1][p.j+1]){
                qu.push(Pair(p.i+1,p.j+1,p.osf+"d3 "));
            }
        }
    }
//     33
// 4 d3 d1 d2 d3 d1 
return 0;
}