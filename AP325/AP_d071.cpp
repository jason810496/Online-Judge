#include<iostream>
using namespace std;
#define ll long long 
#define MAX_W 100005
#define MAX_N 105
/*
0/1 knapsack

*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,Weight,MAX_w=0,w[MAX_N],val[MAX_N]; 
    ll dp[MAX_W] = {};
    cin>>n>>Weight;
    
    for(int i=0;i<n;i++)cin>>w[i];
    for(int i=0;i<n;i++) cin>>val[i];

    for(int i=0;i<n;i++){
        for(int cur_w=Weight ; cur_w-w[i]>=0 ;cur_w--){
            dp[cur_w]=max(dp[cur_w],dp[cur_w- w[i]]+val[i]);
        }
    }
    cout<<dp[Weight];
    return 0;
}