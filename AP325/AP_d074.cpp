#include<iostream>
#include<string>
using namespace std;
/*
DP LCS III
*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    string A,B; cin>>A>>B;
    int len1=A.size(),len2=B.size();
    int dp[505][505],MAX=0;

    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]=dp[i-1][j-1]+8;
            }
            else{
                dp[i][j]=max( dp[i-1][j-1]-5,
                         max(dp[i-1][j]-3,dp[i][j-1]-3) );

                dp[i][j]=(dp[i][j]>0 ? dp[i][j]:0);
            }
            MAX=max(MAX,dp[i][j]);
        }
    }
    cout<<MAX;
    return 0;
}