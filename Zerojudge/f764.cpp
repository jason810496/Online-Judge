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
#define X first
#define Y second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 100005;
const int INX = 1e9;

int n;
/*
    TOI Exe
    conven Hull
*/
inline pii get_M(pii a,pii b){
    int dx=b.X-a.X, dy=b.Y-a.Y,t;
    if(dx==0 || dx*dy<0) return make_pair(0,0);
    t=__gcd(dx,dy);
    return make_pair(dx/t,dy/t);
}

inline bool cmp(pii Ma,pii Mb){
    
    int dYa=Ma.Y*Mb.X , dYb=Mb.Y*Ma.X;
    return dYb<dYa;
}
signed main(){
    OAO
    cin>>n;
    vector<pii> vec(n);
    for(auto &i:vec) cin>>i.X>>i.Y;
    sort(range(vec));

    deque<pii> Last_M;
    deque<pii> deq;
    deq.push_back(vec[0]);

    for(int i=1;i<n;i++){
        if(vec[i].Y<vec[0].Y || vec[i].Y>vec[n-1].Y ) continue;
        pii cur_M = get_M(vec[0],vec[i]);
        if(cur_M.X==0 ) continue; // M that don't fit
        
        while( !Last_M.empty() && cmp(Last_M.back(),cur_M) ){
            deq.pop_back();
            Last_M.pop_back();
        }
        deq.push_back(vec[i]);
        Last_M.push_back(cur_M);
    }

    //deq.push_back(vec[n-1]);

    while(!deq.empty() ){
        cout<<deq.front().X<<' '<<deq.front().Y<<'\n';
        deq.pop_front();
    }
    return 0;
}