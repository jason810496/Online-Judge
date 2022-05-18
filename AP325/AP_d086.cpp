#include<iostream>
#include<string.h>
#define ll long long
using namespace std;
/*
DP: Matrix Chain Multiplication
hard 

*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,Size[205];
    ll ans=0,dp[205][205];

    cin>>n;
    for(int i=0;i<=n;i++) cin>>Size[i];

    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) dp[i][i]=0;

    for(int len=1;len<n;len++){
        for(int i=0;i+len <n;i++){
            int k=i+len;
            ll Min=INT32_MAX;
            for(int j=i;j<k;j++){
                Min=min( Min ,
                             dp[i][j] + dp[j+1][k] 
                           + Size[i]*Size[j+1]*Size[k+1] );
            }

            dp[i][k]=Min;
        }
    }

    cout<<dp[0][n-1];
    return 0;
}