#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define ll long long 
#define Lf first 
#define Rt second 
#define all(x) x.begin(),x.end()
#define PB push_back 

typedef pair<int,int> pii;
typedef vector< vector<int> > vvi;
typedef vector<int> vi;

const int INF = 1e9;
const int N = 1e5;

int n , m;
vector< pii > G;
vi Total_Wt , Wt ,items ,ans ;

inline bool is_box(int x){
    return (x>= n && x<2*n );
}

int Build(int rt){
    if( is_box( rt ) ){
        Total_Wt [ rt ] = Wt[ rt ];
        return Wt[ rt ];
    }

    int lc = G[rt].Lf;
    int rc = G[rt].Rt;
    Build( lc );
    Build( rc );

    Total_Wt[ rt ]= Total_Wt[ lc ]+ Total_Wt[ rc ];
}

void Insert(int rt,int val){
    if( is_box( rt ) ){
        Total_Wt [ rt ] += val;
        ans.PB( rt );
        return ;
    }
    int lc = G[rt].Lf;
    int rc = G[rt].Rt;

    if( Total_Wt[lc]<= Total_Wt[rc] ){
        Insert( lc , val);
    }
    else{
        Insert( rc , val);
    }
    // update
    Total_Wt[ rt ]= Total_Wt[ lc ] + Total_Wt[ rc ];
}
signed main(){
    OAO 
    cin>>n>>m;
    G.resize(n);
    items.resize( m );
    Total_Wt.resize( 2*n );
    Wt.resize( 2*n );

    for(int i=n ,x ;i<2*n;i++){
        cin>>x;
        Wt[ i ] = x;
    }
    for(auto &i:items) cin>>i;

    for(int i=1 , p , l, r;i<n;i++){
        cin>>p>>l>>r;
        G[ p ].Lf = l;
        G[ p ].Rt = r;
    }

    // build 
    Build( 1 );

    for(auto &v:items){
        Insert( 1, v);
    }

    for(auto &i:ans){
        cout<<i<<' ';
    }
    
    return 0;
}