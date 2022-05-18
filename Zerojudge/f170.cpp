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
const int MAX_N = 1e3+5;
const int INF = 1e9;
/*
    TOI Exe
    AC
    BFS (can't find BUG first time ??)
*/
int G[MAX_N][MAX_N]={},n;
bool vis[MAX_N][MAX_N]={};
signed main(){
    OAO
    cin>>n;
    int XX,YY;
    cin>>XX>>YY;
    XX++,YY++;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>G[i][j];
    }

    queue<pii> q;
    q.push({XX,YY});
    vis[XX][YY]=1;

    int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}},ans=0;
    while(!q.empty() ){
        ans++;
        pii P=q.front();
        q.pop();
        XX=P.F;
        YY=P.S;
        for(int k=0,I,J;k<4;k++){
            I=XX+dir[k][0];
            J=YY+dir[k][1];
            if(I<=0 || J<=0 || I>n || J>n) continue;
            if(vis[I][J]) continue;
            if(abs(G[XX][YY]-G[I][J])>=3) continue;
            vis[I][J]=1;
            q.push({I,J});
        }

        
    }

    cout<<ans;

    return 0;
}