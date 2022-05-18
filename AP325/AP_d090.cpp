#include<bits/stdc++.h>
using namespace std;
//basic BFS AC
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,m,s,dis[105],ans=0,cnt=0; 
    bool visited[105];
    memset(dis,0,sizeof(dis));
    memset(visited,0,sizeof(visited));
    vector<int> Graph[105];
    cin>>n>>m>>s;
    for(int u,v,i=0;i<m;i++){
        cin>>u>>v;
        Graph[u].push_back(v);
    }

    queue<int> q;
    q.push(s);
    visited[s]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        if(Graph[u].empty()) continue;
        for(auto v:Graph[u]){
            if(visited[v]) continue;
            visited[v]=true;
            cnt++;
            dis[v]=dis[u]+1;
            ans+=dis[v];
            q.push(v);
        }
    }
    cout<<cnt<<'\n'<<ans;
    return 0;
}