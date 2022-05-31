#include<bits/stdc++.h>
using namespace std;
int n , m , k;
/*
Unfinish , complex but not hard 
*/
// row-major : i*(m+1)+j
inline int id(int i,int j){
    return (i*m+j);
}

int G[505][505],P[505*505],Size[505*505] = {};

int pos[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

inline int Find(int x){
    return x==P[x] ? x : P[x]=Find(P[x]);
}

int Group=0;

void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    if(a==b) return;

    if( Size[b] > Size[a] ) swap(a,b);
    Size[a]+=Size[b];
    P[b]=a;

    Group--;
    // cout<<" union : "<<a<<"\n";
}


int DFS(int x,int y,int root ){
    P[ id(x,y) ] = root;
    int ret=G[x][y];

    G[x][y]=-1;

    for(int k=0;k<4;k++){
        int i=x+pos[k][0] , j=y+pos[k][1];
        if( i<=0 || j<=0 || i>n ||j>m ) continue;

        if( G[i][j]==1 ){
            Size[ id(i,j) ]=DFS( i , j ,root );
            ret+=Size[ id(i,j) ];
        }
    }

    return ret;
}


int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;

    int Total=0;

    for(int i=1;i<=n;i++){
        for(int j=1, ID ;j<=m;j++){
            cin>>G[i][j];
            // 2D to 1D
            ID =id(i,j);
            // init DSU
            P[ ID ] = ID ;
            Size[ ID ]=G[i][j];
        }
    }

    int cur=0,cur_max=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if( G[i][j]==1 ){
                cur = Size[ id(i,j) ] = DFS( i, j , id(i,j) );
                cur_max = max( cur_max, cur );

                Group++;
                // cout<<i<<' '<<j<<' '<<cur<<'\n';
            }
        }
    }

    // cout<<"=====\n";

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<G[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // cout<<"=====\n";

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<Size[ id(i,j) ]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // cout<<"=====\n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<P[ id(i,j) ]<<' ';
    //     }
    //     cout<<'\n';
    // }

    int sum=cur_max, cnt=Group;

    // cout<<cur_max<<' '<<Group<<'\n';

    while(k--){
        int x,y;
        cin>>x>>y;

        G[x][y]=-1;
        Size[ id(x,y) ]=1;

        Group++;
        for(int k=0;k<4;k++){
            int i=x+pos[k][0] , j=y+pos[k][1];
            if( i<=0 || j<=0 || i>n || j>m ) continue;

            if( G[i][j]==-1){
                Union( id(x,y) , id(i,j) );
            }
           
        }

        // -------

    // cout<<"=====\n";

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<G[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // cout<<"=====\n";

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<Size[ id(i,j) ]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // cout<<"=====\n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<P[ id(i,j) ]<<' ';
    //     }
    //     cout<<'\n';
    // }

        // ----

        cur = Size[ Find( id(x,y) ) ];
        cur_max = max( cur_max , cur );
        sum+=cur_max;
        cnt+=Group;
    }

    // cout<<cur_max<<'\n'<<Group<<'\n';

    cout<<sum<<'\n'<<cnt;

    return 0;
}