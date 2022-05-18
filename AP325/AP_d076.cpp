#include<iostream>
#include<string.h>
using namespace std;
#define ll long long 
#define mod 1000000009
/*
DP new
catalan number
*/
ll dp[105];

ll catalan(int n){
    if(dp[n]>=0 ) return dp[n];
    ll ret=0;
    for(int i=0;i<n;i++){
        ll cur=catalan(i)*catalan(n-i-1)%mod;
        ret=(ret+cur)%mod;
    }

    dp[n]=ret;
    return dp[n];
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    memset(dp,-1,sizeof(dp));
    dp[0]=1;
    int n;cin>>n;
    cout<<catalan(n);
    return 0;
}