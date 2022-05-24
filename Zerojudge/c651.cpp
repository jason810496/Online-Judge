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
#define PB push_back
typedef pair<int,int> pii;
const int MAX_N =1e6+5;
const int N = 2e6+5;
const int INF = 1e9;

/*
    
    https://zerojudge.tw/ShowProblem?problemid=c651
*/

#define lowbit(x) x&-x

int BIT[MAX_N] , arr[MAX_N];

int n;
void Update(int i ,int val ){
    for(; i<=n ;i+=lowbit(i) ){
        BIT[i]^=val;
    }
}

int Query(int i ){
    int res = 0;
    for( ; i ; i-=lowbit(i) ){
        res^=BIT[i];
    }
    
    return res;
}

signed main(){
    OAO
    int q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        Update(i,arr[i]);
    }

    int L, R ,idx, v ;
    bool oper;
    while(q--){
        cin>>oper;
        if( oper ){
            cin>>idx>>v;
            Update( idx , arr[idx] ); // A xor A =0
            Update( idx , v ); // V xor 0 = V 
            arr[ idx ] = v;
        }
        else{
            cin>>L>>R;
            cout<< (Query(R)^Query(L-1)) <<'\n';
        }
    }
   

    return 0;
}