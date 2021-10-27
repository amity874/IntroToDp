#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    int ans=INT_MIN;
    int temp=0;
    for(auto i:arr){
        temp+=i;
        if(ans<temp){
            ans=temp;
        }
        if(temp<0){
            temp=0;
        }
    }
    std::cout<<ans;
return 0;
}