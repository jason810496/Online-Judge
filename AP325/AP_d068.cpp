#include<iostream>
#define MAX_N 100005
#define ll long long 
/*
DP
need concept to slove
*/
using namespace std;
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n;cin>>n;
    ll dp[MAX_N],arr[MAX_N];
    for(int i=0;i<n;i++) cin>>arr[i];

    dp[0]=arr[0];
    dp[1]=arr[1];
    dp[2]=arr[2]+min(arr[0],arr[1]);

    for(int i=3;i<n;i++){
        dp[i]=arr[i]+ min(dp[i-3] , min(dp[i-1],dp[i-2]) ) ;
    }
    cout<<min(dp[n-1], dp[n-2]);
    return 0;
}