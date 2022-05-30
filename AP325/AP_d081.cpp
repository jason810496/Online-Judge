#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define N (1<<20)


/*
    ref:
        https://github.com/nevikw39/oj/blob/master/ap325/d081.cpp
        https://github.com/lbwei1016/Codes/blob/master/Online_judge/Finished/TCIRC_Judge/tcirc_d081_top_down.cpp

*/
int DP[N] , Wt[N] , n ;

int dp(int cur){
    if( DP[ cur ] >=0 ) return DP[cur];

    int MX_From=0;

    for(int i=0;i<n;i++){
        // one bit diff 
        if( cur&(1<<i) ){
            // back to last state
            MX_From = max( MX_From , dp( cur^(1<<i) ) );
        }
    }

    return DP[ cur ] = MX_From + Wt[ cur ];
}

signed main(){
    OAO 
    memset(DP , -1 , sizeof(DP) );

    cin>>n;
    for(int i=0;i<(1<<n) ; i++){
        cin>>Wt[i];
    }

    DP[0]=Wt[0];

    cout<<dp( (1<<n)-1 );
    return 0;
}