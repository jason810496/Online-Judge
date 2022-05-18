#include<bits/stdc++.h>
#define Node first
#define W second
using namespace std;
/*
BUG ??
*/

/*
AC ?? but I cant find BUG
*/
const int INF =2e9;

int n, m ,Start ,End;
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n>>m>>Start>>End;
    vector<vector<pair<int,int> > > G(n);
    vector<int> indeg(n,0),Min(n,INF),Max(n,-INF);

    for(int u,v,w,i=0;i<m;i++){
        cin>>u>>v>>w;
        G[u].push_back({v,w});
        indeg[v]++;
    }

    queue<int > q;
    for(int i=0;i<n;i++){
        if( indeg[i]==0) q.push(i);
    }

    Min[Start]=0;
    Max[Start]=0;

    while(q.size() ){
        int v=q.front();
        q.pop(); 

        for(auto u:G[v]){

            Max[u.Node]=max(Max[u.Node] ,Max[v]+ u.W );
            Min[u.Node]=min(Min[u.Node] ,Min[v]+ u.W );
            
            if( (--indeg[u.Node])==0 ){
                q.push(u.Node);
            }
        }
    }

    // cout<<cnt;

    if( Max[End]==-INF || Min[End]==INF ) cout<<"No path\nNo path\n";
    else{
        cout<<Min[End]<<'\n'<<Max[End];
    }
    return 0;
}