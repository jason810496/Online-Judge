#include<bits/stdc++.h>
using namespace std;


#define F first
#define S second
#define ll unsigned long long 
#define all(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB push_back
typedef pair<int,int> pii;
const int MAX_N = 100005;
const int INF = 1e9;

class Solution {
public:
    ll MOD = 1e9+7;
    int countTexts(string key) {
        ll ans=1; 
        int n=key.size();
        vector<int> dp(n+1);

        dp[0]=1;

        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1]%MOD;

            if( i-2>=0 && key[i-1]==key[i-2] ){
                dp[i] = ( dp[i] + dp[i-2] )%MOD;
                if( i-3>=0 && key[i-1]==key[i-3] ){
                    dp[i] = ( dp[i] + dp[i-3] )%MOD;
                    if( i-4>=0 && (key[i-1]=='7' || key[i-1]=='9') && key[i-4]==key[i-1] ){
                        dp[i] = ( dp[i] + dp[i-4] )%MOD;
                    }
                }
            }
        }

        return dp.back();
    }
};
