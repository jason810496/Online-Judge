#include<bits/stdc++.h>
using namespace std;
const int MAX_N=1e4+5;
// AC bipartite graph
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int T ; cin>>T;
    while(T--){
        
        bool flag =true;
        int u, v, n , m;
        cin>>n>>m;

        vector<vector<int> > G(n);

        while(m--){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        vector<int> mark(n,-1);

        for(int i=0;i<n && flag ;i++){
            if(mark[i]==-1 ){

                queue<int> q;
                q.push(i);
                mark[i]=0;

                while(q.size() && flag){
                    u=q.front();
                    q.pop();

                    for(auto v:G[u]){
                        if(mark[v]==mark[u]){
                            flag =false;
                            break;
                        }
                        else if(mark[v]==-1){
                            q.push(v);
                            mark[v]=!mark[u];
                        }
                    }
                }
            }

        }
        cout<<(flag ? "yes\n" : "no\n");
    }
    return 0;
}