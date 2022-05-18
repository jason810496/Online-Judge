#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end(
#define MEM(x,i) memset(x,0,sizeof(x))
#define rep(i,n) for(int i=0;i<n++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
typedef pair<int,int> pii;
const int MAX_N = 1e9+5;
const int INF = 1e9;
/*
inline bool comp(int a,int b){
    return a>b;
}

struct comparator{
    bool operator() (const int &a,const int &b){
        return a>b;
    }
};

*/
int MOD=1000000007,MAX=0;

ll **base;
vector<int> vec;

ll **mult(ll **a,ll **b){
    //ll ret[2][2]={{0,0},{0,0}};
    ll **ret=new ll*[2];
    ret[0]=new ll[2];
    ret[1]=new ll[2];
    ret[0][0]=0;
    ret[0][1]=0;
    ret[1][0]=0;
    ret[1][1]=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                ret[i][j]=(ret[i][j]+a[i][k]*b[k][j])%MOD;
            }
        }
    }

    return ret;
}

ll **fast_pow(int n){
    if(n==0) return base;
    if(n%2==0){
        ll **temp=fast_pow(n/2);
        return mult(temp,temp);
    }

    return mult(base,fast_pow(n-1));
}

int main(){
    OAO
    base = new ll*[2];
    base[0]=new ll[2];
    base[1]=new ll[2];
    base[0][0]=1;
    base[0][1]=1;
    base[1][0]=1;
    base[1][1]=0;
    int n;
    while(cin>>n ){
        if(n==-1) break;
        ll **ans=fast_pow(n-3);
        vec.push_back(ans[0][0]);
    }

    for(const auto i:vec) cout<<i<<'\n';

    return 0;
}