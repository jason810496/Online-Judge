/*
 ██████╗ ██████╗ ██████╗ ███████╗     ██████╗ ██╗   ██╗████████╗
██╔════╝██╔═══██╗██╔══██╗██╔════╝    ██╔═══██╗██║   ██║╚══██╔══╝
██║     ██║   ██║██║  ██║█████╗      ██║   ██║██║   ██║   ██║   
██║     ██║   ██║██║  ██║██╔══╝      ██║   ██║██║   ██║   ██║   
╚██████╗╚██████╔╝██████╔╝███████╗    ╚██████╔╝╚██████╔╝   ██║   
 ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝     ╚═════╝  ╚═════╝    ╚═╝   
                                                                
 █████╗  ██████╗    ██╗███╗   ██╗                               
██╔══██╗██╔════╝    ██║████╗  ██║                               
███████║██║         ██║██╔██╗ ██║                               
██╔══██║██║         ██║██║╚██╗██║                               
██║  ██║╚██████╗    ██║██║ ╚████║                               
╚═╝  ╚═╝ ╚═════╝    ╚═╝╚═╝  ╚═══╝                                                                                                                                                                            
*/
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
const int MAX_N = 100005;
const int INF = 1e9;
/*
    1 WA 95%
*/
int n , c , m ,a, b;
signed main(){
    OAO
    cin>>n>>c>>m;
    ll ans=0,MOD=1;
    rep(i,m) MOD*=10;
    vector<pair<long long ,long long > > vec;
    
    for(int i=0;i<n;i++){
        // ax^b;
        cin>>a>>b;
        vec.push_back({b,a});
    }
    for(auto i:vec){
        ll base=1;
        for(int k=0;k<i.F;k++){
            base*=c;
            base%=MOD;
        }
        ans=(ans+base*i.S)%MOD;
        ans%=MOD;
    }
    ans=abs(ans);

    int Size=0,temp=ans;
    while(temp){
        Size++;
        temp/=10;
    }
    int t=m-Size;
    while(t--) cout<<0;
    if(ans) cout<<ans;
    return 0;
}