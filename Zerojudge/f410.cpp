
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 1e4+5;
const int INF = 1e9;

signed main(){
    OAO
    
    int n ;  cin>>n;

    vector<int> vec(n);
    for(auto &i:vec) cin>>i;

    sort(range(vec),  [&](const int &a,const int &b){
        return (a&1 ? (b&1 ? a>b:0):(b&1 ? 1:a<b) );
    });

    for(auto &i:vec){
        cout<<i<<' ';
    }
    return 0;
}