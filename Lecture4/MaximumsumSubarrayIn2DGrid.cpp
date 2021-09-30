#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

ll kadane(std::vector<ll>&dp,int &start,int &end){
    ll sum=0;
    end=-1;
    ll tempstart=0;
    int n=dp.size();
    ll max_sum=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=dp[i];
        if(sum<0){
            sum=0;
            tempstart=i+1;
        }
        else if(sum>max_sum){
            max_sum=sum;
            start=tempstart;
            end=i;
        }
    }
    if(end!=-1){
        return max_sum;
    }
    start,end=0;
    max_sum=dp[0];
    for(int i=1;i<n;i++){
        if(max_sum<dp[i]){
            max_sum=dp[i];
            start,end=i;
        }
    }
    return max_sum;
}
std::vector<ll> Helper(std::vector<std::vector<ll>>&arr){
    int n=arr.size();//no of rows
    int m=arr[0].size();//no of column
    ll result=INT_MIN;
    int start,end,tlc,trr,blc,brr=0;
    std::vector<ll>dp(n,0);
    for(int leftCol=0;leftCol<m;leftCol++){
        dp.assign(n,0);
        for(int rightCol=leftCol;rightCol<m;rightCol++){
            for(int i=0;i<n;i++){
                dp[i]+=arr[i][rightCol];
            }
            ll sum=kadane(dp,start,end);
            if(sum>result){
                result=sum;
                tlc=leftCol;
                trr=rightCol;
                blc=start;
                brr=end;
            }
        }
    }
    return {result,tlc,blc,trr,brr};
}
int main(int argc, char const *argv[])
{
    ll n,m;
    cin>>n>>m;
    std::vector<std::vector<ll>>arr (n,std::vector<ll>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    std::vector<ll> ans=Helper(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}