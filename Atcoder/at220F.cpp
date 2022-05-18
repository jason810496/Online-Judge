#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,0,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
typedef pair<int,int> pii;
const int MAX_N = 2e5+5;
const int INF = 1e9;

vector<int> T[MAX_N];
int dis[MAX_N]={},ans[MAX_N]={},Child[MAX_N]={};
void DFS(int cur,int par){
    dis[cur]=1;
    for(int v:T[cur]){
        if( v==par ) continue;
        Child[cur]++;
        DFS(v,cur);
        dis[cur]+= dis[v];

        ans[v]=dis[cur]-dis[v]+Child[par]-1;
    }

    //ans[cur]=dis[par]-dis[cur];
}
int main(){
    OAO
    int n,u,v;
    cin>>n;
    rep(i,n-1){
        cin>>u>>v;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    DFS(1,0);


    for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
    cout<<'\n';
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}