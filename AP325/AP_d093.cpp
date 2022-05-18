#include<bits/stdc++.h>
using namespace std;
#define F first 
#define S second
// BUG ??
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,m,Graph[505][505];
    int oper[505][505];
    bool visited[505][505];
    int pos[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    char c;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c;
            Graph[i][j]=(c=='0'? 0:-1);
            // cout<<Graph[i][j]<<' ';
        }
        // cout<<'\n';
    }

    queue<pair<int,int> > q;
    q.push({1,1});
    Graph[1][1]=1;
    oper[1][1]=4;
    visited[1][1]=1;
    while(q.size() && Graph[n][m]==0){
        auto p=q.front();
        q.pop();

        int I__,J__;
        //0:R , 1:D ,2:L ,3:U
        for(int i=0;i<4;i++){
            I__=p.F+pos[i][0];
            J__=p.S+pos[i][1];
            if(I__>n||J__>m||I__<=0||J__<=0) continue;
            if(Graph[I__][J__]==-1 || visited[I__][J__]==1) continue;
            visited[I__][J__]=1;
            int next=Graph[p.F][p.S]+(oper[p.F][p.S]==i ? 0:(oper[p.F][p.S]==4? 0:1) ) ;
            Graph[I__][J__]=Graph[I__][J__]==0? next: min(Graph[I__][J__],next);
            oper[I__][J__]=i;
            q.push({I__,J__});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<oper[i][j]<<' ';
        }
        cout<<'\n';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<Graph[i][j]<<' ';
        }
        cout<<'\n';
    }

    cout<<(Graph[n][m]>0 ? Graph[n][m]-1:-1);
    return 0;   
}
/*


5 5
00000
01110
00100
10010
00000

10 10 
0000000000
0111111110
0111000110
0011010110
1000010110
1111110110
0000000110
0111111110
0111111110
0000000000

*/