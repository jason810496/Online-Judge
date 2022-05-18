/*
 ██████╗ ██████╗ ██████╗ ███████╗     ██████╗ ██╗   ██╗████████╗
██╔════╝██╔═══██╗██╔══██╗██╔════╝    ██╔═══██╗██║   ██║╚══██╔══╝
██║     ██║   ██║██║  ██║█████╗      ██║   ██║██║   ██║   ██║   
██║     ██║   ██║██║  ██║██╔══╝      ██║   ██║██║   ██║   ██║   
╚██████╗╚██████╔╝██████╔╝███████╗    ╚██████╔╝╚██████╔╝   ██║   
 ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝     ╚═════╝  ╚═════╝    ╚═╝   
                                                                
 █████╗  ██████╗    ██╗███╗   ██╗                               
██╔══██╗██╔════╝    ██║████╗  ██║                               
███████║██║         ██║██╔██╗ ██║                               
██╔══██║██║         ██║██║╚██╗██║                               
██║  ██║╚██████╗    ██║██║ ╚████║                               
╚═╝  ╚═╝ ╚═════╝    ╚═╝╚═╝  ╚═══╝                                                                                                                                                                            
*/
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 1005;
const int INF = 1e9;
ll MOD = 1e9+7;
ll dp[MAX_N][MAX_N]={};
bool mark[MAX_N][MAX_N]={};
signed main(){
    OAO
    int R,C;
    cin>>R>>C;
    char x;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>x;
            if(x=='#') mark[i][j]=1;
        }
    }

    dp[1][1]=1;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(mark[i][j]) continue;
            dp[i][j]+=(mark[i-1][j] ? 0:dp[i-1][j]);
            dp[i][j]%=MOD;
            dp[i][j]+=(mark[i][j-1] ? 0:dp[i][j-1]);
            dp[i][j]%=MOD;
        }
    }
    cout<<dp[R][C];
    return 0;
}