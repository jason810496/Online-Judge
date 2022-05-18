#include<iostream>
using namespace std;
#define ll long long 
/*
DP III
*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n ,k,cost[100005][2];
    ll dp[100005][2];
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>cost[i][0]>>cost[i][1];
    // init
    dp[1][0]=abs(k-cost[1][0]);
    dp[1][1]=abs(k-cost[1][1]);

    for(int i=2;i<=n;i++){
        // choose cost 1
        dp[i][0]=min( dp[i-1][0]+abs(cost[i][0]-cost[i-1][0]) ,
                      dp[i-1][1]+abs(cost[i][0]-cost[i-1][1]) );
        // choose cost 2
        dp[i][1]=min( dp[i-1][0]+abs(cost[i][1]-cost[i-1][0]) ,
                      dp[i-1][1]+abs(cost[i][1]-cost[i-1][1]) );
    }
    cout<<min(dp[n][0],dp[n][1]);
    return 0;  
}