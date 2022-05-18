#include<bits/stdc++.h>
#define ll long long 
#define MAX_N 205
using namespace std;
/*
DP top down 
(hard)

*/
int pos[MAX_N],dp[MAX_N][MAX_N];

int cost(int i,int j ){
    if(dp[i][j]>=0 ) return dp[i][j];
    int Min_cost=INT32_MAX;

    for(int k=i+1 ; k<j ;k++){
        Min_cost=min( Min_cost, cost(i,k)+cost(k,j) ) ;
    } 

    Min_cost+=pos[j]-pos[i];
    return dp[i][j]=Min_cost;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,L; cin>>n>>L;
    for(int i=1;i<=n;i++) cin>>pos[i];
    pos[0]=0;
    pos[n+1]=L;
    
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n+1;i++){
        dp[i][i+1]=0;
    }
    cout<<cost(0,n+1);
    return 0;
}