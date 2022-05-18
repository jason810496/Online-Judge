#include<iostream>
#include<string>
using namespace std;
/*
AC
DP LCS 3 string
*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,m,p,dp[105][105][105];
    string a,b,c;
    cin>>a>>b>>c;
    n=a.size();
    m=b.size();
    p=c.size();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=p;k++){

                if(a[i-1]==b[j-1] && b[j-1]==c[k-1]){
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                }
                else{
                    dp[i][j][k]=max( max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
                }
            }
        }
    }
    cout<<dp[n][m][p];
    return 0;
}