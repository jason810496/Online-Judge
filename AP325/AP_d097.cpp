#include<bits/stdc++.h>
using namespace std;
int n , m , k;
/*
Unfinish , complex but not hard 
*/
// row-major : i*(m+1)+j
inline int idx(int i,int j){
    return (i*m+j);
}

int G[505][505],P[505*505],Size[505*505];

int pos[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

inline int Find(int x){
    return x==P[x] ? x : P[x]=Find(P[x]);
}

void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    if(a==b) return;

    if( Size[b] > Size[b] ) swap(a,b);
    Size[a]+=Size[b];
    P[b]=a;
}

int DFS(int id){
    int ret=0;
    for(int k=0;k<4;k++){
        int i=I+pos[k][0], j=J+pos[k][1],id2;
        if(i<1||i>=n||j<1||j>=m) continue;
        id2=Index(i,j);
        if(visited[ id2 ] || G[i][j]) continue;

        ret+=DFS()
        Union(id,id2);
    }
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    int Total=0;
    for(int i=1;i<=n;i++){
        for(int j=1,id;j<=m;j++){
            cin>>G[i][j];
            // 2D to 1D
            id=Index(i,j);
            // init DSU
            P[id]=id;
            Size[id]=G[i][j];
        }
    }
    int cur=0,cur_max=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!G[i][j] ) DFS( Index(i,j) );
        }
    }

    int I,J;
    while(k--){
        cin>>I>>J;

    }

    return 0;
}