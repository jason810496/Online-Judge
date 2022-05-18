#include<iostream>
#define MAX_N 100005
/*
AP III
*/
#define ll long long
using namespace std;
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n , K; cin>>n>>K;
    ll dp[MAX_N],val;
    for(int i=1;i<=n;i++){
        cin>>val;
        if(i-K-1 < 0) dp[i]=max(dp[i-1],val);
        else{
            dp[i]=max(dp[i-K-1]+val, dp[i-1]);
        }
    }
    cout<<dp[n];
    return 0;
}