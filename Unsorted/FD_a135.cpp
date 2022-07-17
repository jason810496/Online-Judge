#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define all(x) x.begin(),x.end()
#define PB push_back
typedef pair<int,int> pii;
typedef pair<long long,int> pli;
typedef pair<int,long long> pil;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
const int MAX_N = 100005;
const int N = 505;
const int INF = 1e9;

int n , k ;

int pos[N] ,Par[N] , Sz[N] ,Wt[N], Group;

typedef pair<int,pair<int,int> > P;

void init(){
    Group = n;
    for(int i=0;i<n;i++){
        Par[i] = i;
        Sz[i]=1;
        Wt[i]=0;
    }
}

inline int Find(int x){
    return (Par[x]==x ? x: Par[x] = Find( Par[x] ) );
}

bool Union(int a,int b,int w){
    a=Find(a);
    b=Find(b);

    if( a==b ) return false;
    if( Sz[b]>Sz[a] ) swap(a,b);

    Sz[a]+=Sz[b];
    Wt[a]+=Wt[b]+w;
    Par[b]=a;

    return true;   
}

void solve(){
    for(int i=0;i<n;i++){
        cin>>pos[i];
    }

    sort(pos,pos+n);

    init();

    // vector< P > edges;
    priority_queue< P , vector<P> , greater<P> > pq;

    for(int i=1;i<n;i++){
        // edges.push_back( { pos[i]-pos[i-1] , { i-1, i } } );
        pq.push({ pos[i]-pos[i-1] , { i-1, i } } );
    }

    while( Group>k ){
        P e = pq.top();
        pq.pop();

        // cout<<"edge : "<<e.F<<" "<<e.S.F<<" "<<e.S.S<<"\n";

        if( Union(e.S.F , e.S.S , e.F) ){
            Group--;
        }
    }

    bitset<N> vis;

    ll ans=0;
    for(int i=0 , idx ;i<n;i++){
        idx = Find( i );
        if(!vis[ idx ] ){
            ans+= (ll)(Wt[idx])*(ll)(Wt[idx]);
            vis[idx]=1;
        }
    }

    cout<<ans<<"\n";
}
int main(){
    OAO

    while( cin>>n>>k ){
        solve();
    }
    return 0;
}