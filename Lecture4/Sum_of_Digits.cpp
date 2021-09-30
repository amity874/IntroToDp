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
ll pow_of_10(ll a){
    ll result=1;
  for(int i=1;i<=a;i++){
      result*=10;
  }
  return result;
}
ll Sum_of_digits(ll num){
    if(num/10==0){
        return ((num)*(num+1))/2;
    }
    string s=to_string(num);
    int n=s.size();
    ll pow_1=pow_of_10(n-1);
    int first=num/(pow_1);
    ll result=0;
    ll sum=pow_of_10(n-2)*45*(n-1);
    for(int i=0;i<first;i++){
        result=result+(i)*pow_1+sum;
    }
    ll res_of_number=num%(pow_1);
    result+=first*(res_of_number+1);
    result+=Sum_of_digits(res_of_number);
    return result;
}
int main(int argc, char const *argv[]){
     ll a,b;
    while(true){
        cin>>a>>b;
        if(a==-1 and b==-1){
            break;
        }
        ll a1=Sum_of_digits(b);
        ll a2=Sum_of_digits(a-1);
        cout<<a1-a2<<"\n";
    }
    return 0;
}
