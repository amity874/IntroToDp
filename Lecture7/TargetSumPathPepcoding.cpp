#include<bits/stdc++.h>
    #define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;

struct Pair{
    int i;
    int j;
    std::string osf;
    Pair(int i,int j,std::string osf){
        this->i=i;
        this->j=j;
        this->osf=osf;
    }
}; main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    int target;
    std::cin>>target;
    std::vector<std::vector<bool>>dp(n+1,std::vector<bool>(target+1,false));
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            if(j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }
            else{
                if(dp[i-1][j]){
                    dp[i][j]=true;
                }
                else if(j>=arr[i-1]){
                    if(dp[i-1][j-arr[i-1]]){
                        dp[i][j]=true;
                    }
                }
            }
        }
    }
    bool b=dp[n][target];
    if(b){
        std::cout<<"true"<<"\n";
    }else{
        std::cout<<"false"<<"\n";
    }
    std::queue<Pair>qu;
    qu.push(Pair(n,target,""));
    while (!qu.empty()){
        Pair p=qu.front();
        qu.pop();
        if(p.i==0 || p.j==0){
            std::cout<<p.osf<<"\n";
        }
        else{
            if(p.j>=arr[p.i-1]){
                bool b=dp[p.i-1][p.j-arr[p.i-1]];
                if(b){
                    qu.push(Pair(p.i-1,p.j-arr[p.i-1],std::to_string(p.i-1)+" "+p.osf));
                }
            }
                bool b=dp[p.i-1][p.j];
                if(b){
                    qu.push(Pair(p.i-1,p.j,p.osf));
                }
        }
    }
    
return 0;
}