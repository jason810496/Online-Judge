#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,0,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
typedef pair<int,int> pii;
const int MAX_N = 1e6+5;
const int INF = 1e9;

int main(){
    OAO
    int n;
    ll Limit,prefix=0,sum=0;
    cin>>n;
    vector<ll> vec(n);
    for(ll &i:vec) {
        cin>>i;
        prefix+=i;
    }
    cin>>Limit;
    ll idx=(Limit/prefix);
    sum=idx*prefix;
    ll cnt=idx*n;
    int i=0;
    while(sum<=Limit){
        sum+=vec[i++];
        cnt++;
    }
    cout<<cnt;
    return 0;
}