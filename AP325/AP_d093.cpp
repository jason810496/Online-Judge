#include<bits/stdc++.h>
using namespace std;
#define F first 
#define S second

// AC BFS

int n,m,Graph[505][505],oper[505][505];
int pos[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

inline int in(int x,int y){
    return !(x<=0 || y<=0 || x>n || y>m);
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);

    char c;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>c;
            Graph[i][j]=(c=='0'? 0:-1);
        }
        // cout<<'\n';
    }

    queue<pair<int,int> > q;

    if( Graph[1][1]!= -1 ){
        q.push({1,1});
        Graph[1][1]=1;
        oper[1][1]=4;
    }
    

    while( q.size() ){
        int x=q.front().F ; 
        int y=q.front().S ;
        q.pop();

        for(int k=0;k<4;k++){
            int i=x+pos[k][0] , j=y+pos[k][1];

            while( in(i,j) && Graph[i][j]!=-1 ){
                if( Graph[i][j]==0){
                    Graph[i][j]= Graph[x][y]+( oper[x][y]==4 ? 0:(oper[x][y]==k ? 0:1));
                    oper[i][j]=k;
                    q.push( {i,j} );
                }

                i+=pos[k][0] , j+=pos[k][1];
            }
        }
    }

    cout<<(Graph[n][m]>0 ? Graph[n][m]-1:-1);
    return 0;   
}