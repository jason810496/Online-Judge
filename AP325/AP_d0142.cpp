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

ll MOD = 1000000007;
struct M{
    ll ele[2][2];
    M(){
        MEM(ele,0);
    }
    M operator * (const M &b){
        M ret;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    ret.ele[i][j]=( ret.ele[i][j]+ele[i][k]*b.ele[k][j]) % MOD;
                }
            }
        }
        return ret;
    }
};

int main(){
    OAO
    int n;
    while(cin>>n && n!=-1){
        if(n<2){
            cout<<n<<'\n';
            continue;
        }
        n-=1;
        M ans,base;
        ans.ele[0][0]=ans.ele[1][1]=1;
        base.ele[0][0] = base.ele[1][0] =base.ele[0][1]=1;
        while(n){
            if(n&1){
                ans= base *ans;
            }
            base= base*base;
            n>>=1;
        }
        cout<<ans.ele[0][0]<<'\n';
    }
    return 0;
}