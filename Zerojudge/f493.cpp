
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);

int n , m ;
int pos[4][2] = { {1,0} , {0,1} ,{-1,0} ,{0,-1} };

int DFS(int x,int y,vector<vector<int> > &G){
    int sum =0 ;
    G[x][y]=1;
    
    for(int k=0;k<4;k++){
        int i=x+pos[k][0] , j=y+pos[k][1];
        if( i<0 || j<0 || i>=n || j>=m ) continue;
        if( G[i][j] ) continue; 

        sum+=DFS(i,j,G);
    }

    return sum + 1;
}
int main(){
    OAO
    
    cin>>n>>m;
    vector< vector<int> > G(n , vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c ;
            cin>>c;
            if( c=='W' ){
                G[i][j]=0;
            }
            else G[i][j]=1;
        }
    }

    int MX = 0 , MN = 1e9 ,cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( !G[i][j] ){
                int cur = DFS(i,j,G);
                cnt++;
                MX=max(MX,cur);
                MN=min(MN,cur);
            }
        }
    }
    if(!cnt){
        cout<<"0 0 0\n";
    }
    else{
        cout<<MX<<' '<<MN<<' '<<cnt;
    }
    return 0;
}