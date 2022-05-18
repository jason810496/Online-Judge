#include<bits/stdc++.h>
using namespace std;
#define N 1005
int main(){
    vector<int> G[N];
    int in_degree[N];
    int n,m ; cin>>n>>m;
    for(int from,to,i=0;i<m;i++){
        cin>>from>>to;
        G[from].push_back(to);
        in_degree[to]++;
    }

    int Que[N],Head=0,Tail=0;

    for(int i=0;i<n;i++){
        if(in_degree[i]==0) Que[Tail++ ]=i;
    }

    while( Head<Tail ){
        int v=Que[Head++];

        for(int u:G[v]){
            if( --in_degree[u]==0){
                Que[Tail++]= u;
            }
        }
    }

    if(Tail < n) cout<<"Not DAG";
    else{
        for(int i=0;i<n;i++){
            cout<<Que[i];
        }
    }

    cout<<'\n';
    
    return 0;
}

// E.G.
/*
5 6

0 2
0 3
2 1 
3 4
1 4
2 4

        0
       / \
      2  3
     / \ \
    1   \ \
     \___\_4
*/