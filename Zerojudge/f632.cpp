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
const int MAX_N = 3005;
const int INF = 1e9+5;


signed main(){
    OAO
    
    int st , ed , K , P ;
    cin>>st>>ed>>K>>P;

    

    map<int,int> M;
    vector< priority_queue<int,vector<int> , greater<int> > > People;
    for(int cur = st ,i=0; cur<=ed ; cur += K,i++){
        M[cur]=i;
    }

    People.resize( M.size() );

    int t,m;
    while( cin>>t>>m){
        auto it = M.lower_bound(t);
        if( it==M.end() ) continue;
        
        int idx = it->second ;

        while( idx<People.size() ){
            People[idx].push(m);
            if( People[idx].size() <= P ) break;
            m = People[idx].top();
            People[idx].pop();
            idx++;
        }

    }

    int cnt=0 , sum =0;

    for(auto &PQ:People){
        
        int last = P;
        while( PQ.size() && last--){
            cnt++;
            sum+=PQ.top();
            PQ.pop();
        }
    }

    cout<<cnt<<' '<<sum;

   
    return 0;
}