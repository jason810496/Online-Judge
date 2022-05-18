#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ll long long 
#define F first
#define S second

const int N = 3e5+5;
const int INF =  1e9;

ll prefix[N];
vector<pii> T;
int n;

inline int RMQ_idx(int L,int R){
    R++;
    int Min=1e9,idx=0;

    for(L+=n,R+=n; L <R ;L>>=1 , R>>=1){
        if(L&1){
            if(T[L].F < Min ){
                Min=T[L].F;
                idx=T[L].S;
            }
            L++;
        }

        if(R&1){
            --R;
            if(T[R].F < Min){
                Min=T[R].F;
                idx=T[R].S;
            }
        }
    }

    return idx;
}


int DC(int L,int R){
    cout<<L<<' '<<R<<'\n';
    if(L==R){
        return (L==0 ? prefix[L]:prefix[L]-prefix[L-1]);
    }

    if(R-L==1){
        ll RR,LL;
        RR=prefix[R]-prefix[R-1];
        LL=( L==0 ? prefix[L]:prefix[L]-prefix[L-1]);

        return max(RR,LL);
    }

    int min_idx=RMQ_idx(L-1,R-1);
    cout<<"Min_idx: "<<min_idx<<'\n';
    ll RR,LL;
    RR=prefix[R]-prefix[min_idx];
    LL=( L==0 ? prefix[min_idx]:prefix[min_idx-1]-prefix[L-1]);

    if(RR >= LL){
        return  DC(min_idx+1,R);
    }

    return DC(L,min_idx-1);
}
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n;
    T.resize(n*2);

    for(int i=1;i<=n;i++){
        cin>>T[n+i-1].F;
        T[n+i-1].S=i;

        prefix[i]=T[n+i-1].F;
        prefix[i]+=prefix[i-1];
    }

    // build segment tree 

    for(int i=n-1; i ; --i ){
        if(T[i<<1].F < T[i<<1|1].F){
            T[i].F = T[i<<1].F;
            T[i].S = (i<<1);
        }
        else{
            T[i].F = T[i<<1|1].F;
            T[i].S = (i<<1|1);
        }
    }


    cout<<RMQ_idx(1-1,6-1)<<"\n";
    cout<<RMQ_idx(1-1,2-1)<<"\n";
    //cout<<DC(1,n);

    return 0;
}