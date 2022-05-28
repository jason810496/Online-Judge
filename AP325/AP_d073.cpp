#include<iostream>
using namespace std;

/*
    Ac DP 2D max Matrix sum 

*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,m;
    long long dp[205][205] = {};
    long long sum,MAX=0;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>dp[i][j];
            dp[i][j]+=dp[i-1][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            sum=0;
            for(int k=1;k<=m;k++){
                sum = max( sum + dp[j][k]-dp[i][k] , 0LL );
                MAX=max( MAX, sum );
            }
        }
    }
    cout<<MAX;
    return 0;
}