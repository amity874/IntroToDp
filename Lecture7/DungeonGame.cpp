// https://leetcode.com/problems/dungeon-game
#include<bits/stdc++.h>
#define ll long long int
int getMinHealth(std::vector<std::vector<ll>>&grid,int currentCell,int i,int j,int n,int m,std::vector<std::vector<ll>>&dp){
   if(i>=n ||j>=m)return INT_MAX;
   int nextcell=dp[i][j];
   return std::max(1,nextcell-currentCell);
}
int main(int argc, char const *argv[]){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<ll>>grid(n,std::vector<ll>(m,0));
    std::vector<std::vector<ll>>dp(n,std::vector<ll>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>grid[i][j];
        }
    }
    for(int row=n-1;row>=0;row--){
        for(int col=m-1;col>=0;col--){
            int current=grid[row][col];
           int right=getMinHealth(grid,current,row,col+1,n,m,dp);
           int down=getMinHealth(grid,current,row+1,col,n,m,dp);
           int retval=std::min(right,down);
           if(retval!=INT_MAX){
               dp[row][col]=retval;
           }
           else{
               dp[row][col]=current>=0?1:1-current;
           }
        }
    }
    std::cout<<dp[0][0];
return 0;
}