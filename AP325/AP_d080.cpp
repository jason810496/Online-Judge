#include<bits/stdc++.h>
#define ll long long 
using namespace std;

// reference: https://www.youtube.com/watch?v=zP36UzcS2R8
/*
DP ladder number
(hard!!!! )
*/

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    ll dp[20][10],ans=0;
    int is_ladder=1;
    memset(dp,0,sizeof(dp));
    string S;cin>>S;
    int len=S.size();
    for(auto &i:S) i-='0';
    // check num is ladder number
    for(int i=1;i<len;i++){
        if(S[i]<S[i-1]){
            is_ladder=0;
            break;
        }
    }
    ans+=is_ladder;
    // dp table
    for(int i=1;i<=len ;i++){
        for(int j=9;j>=1 ;j--){
            if(i==1 || j==9) dp[i][j]=1;
            else dp[i][j]=dp[i-1][j]+dp[i][j+1];
        }
    }

    // for all length
    for(int i=1;i<=len-1 ;i++){
        for(int j=1;j<=9;j++){
            ans+=dp[i][j];
        }
    }
    // for [ 1 , Str[0] ]
    for(int j=0;j<S[0] ; j++){
        ans+=dp[len][j];
    }
    // for each
    for(int i=1;i<len;i++){
        if(S[i]>=S[i-1]){
            for(int j=S[i-1]; j<S[i] ;j++){
                ans+=dp[len-i][j];
            }
        }
        else break;
    }
    cout<<ans;
    return 0;
}