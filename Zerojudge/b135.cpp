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
const int MAX_N = 1e6+5;
const int INF = 1e9;
/*
    0/1 Knapsack
    WA

*/
int Limit,n,dp[32005]={},wt[65]={},val[65]={};
signed main(){
    OAO
    cin>>Limit>>n;
    vector<pii> item[n];
    int cnt=0;
    for(int i=1,w,v,id;i<=n;i++){
        cin>>w>>v>>id;
        if(!id){
            cnt++;
            wt[cnt]=w;
            val[cnt]=v*w;
        }
        else{
            item[id].push_back({w,w*v});
        }
    }

    for(int k=1;k<=cnt;k++){
        for(int w=Limit;w-wt[k]>=0;w--){
            dp[w]=max(dp[w],dp[w-wt[k]]+val[k]);
        }
        for(auto it:item[k]){
            for(int w=Limit;w-it.F-wt[k]>=0;w--){
                dp[w]=max(dp[w],dp[w-it.F]+it.S);
            }
        }
    }

    cout<<dp[Limit];
    return 0;
}