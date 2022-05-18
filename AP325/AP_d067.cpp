#include<iostream>
#define N 100005
#define ll long long 
using namespace std;
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,arr[N];
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    ll dp[N];
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
    }
    cout<<dp[n-1];
    return 0;  
}