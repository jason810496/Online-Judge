#include<iostream>
using namespace std;

/*
DP
can't find bug first time ???

*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,m,dp[205][205],sum,MAX=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>dp[i][j];
            dp[i][j]+=dp[i-1][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            sum=0;
            for(int k=1;k<=m;k++){
                sum+= (dp[j][k] - dp[i][k]);
                sum=(sum<0 ? 0:sum);
                MAX=(sum > MAX ? sum: MAX);
            }
        }
    }
    cout<<MAX;
    return 0;
}