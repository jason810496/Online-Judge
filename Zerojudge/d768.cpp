#include<bits/stdc++.h>
using namespace std;
// AC
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,m;
    vector<int> G[205];
    while(cin>>n&&n){
        cin>>m;
        for(int i=0;i<n;i++) G[i].clear();
        int u,v;
        while(m--){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vector<int> mark(n,-1);
        bool flag=true;
        for(int i=0;i<n && flag;i++){
            if(mark[i]==-1){
                mark[i]=0;
                queue<int> q;
                q.push(i);

                while(q.size() && flag ){
                    int u=q.front();
                    q.pop();

                    for(const int &v: G[u]){
                        if(mark[v]==mark[u]){
                            flag=false;
                            break;
                        }
                        else if(mark[v]==-1){
                            mark[v]=!mark[u];
                            q.push(v);
                        }
                    }
                }
            }
        }

        cout<<(flag ? "BICOLORABLE.\n":"NOT BICOLORABLE.\n");
    }
    return 0;
}