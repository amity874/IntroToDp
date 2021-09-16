std::vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=max(v[0],v[1]);
    for(int i=2;i<=n;i++){
        dp[i]=max(dp[i-1],v[i]+dp[i-2]);
    }
    return dp[n];