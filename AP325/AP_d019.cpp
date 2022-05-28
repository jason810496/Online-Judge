#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define ll long long
#define all(x) x.begin(),x.end()

typedef pair<int,int> pii;

const int INF = 1e9;

int n ,mid ; 
ll target , arr[40];

set<ll> S1 , S2;

void DFS1(int idx,ll val){
    if( idx >= mid ){
        S1.insert( val );
        return ;
    }
    DFS1(idx+1,val+arr[idx]);
    DFS1(idx+1,val);
}

void DFS2(int idx,ll val){
    if( idx > n ){
        S2.insert( val );
        return ;
    }
    DFS2(idx+1,val+arr[idx]);
    DFS2(idx+1,val);
}

signed main(){
    OAO
    
    cin>>n>>target  ;

    for(int i=0;i<n;i++) cin>>arr[i];
    mid = n/2;

    DFS1(0,0);
    DFS2(mid,0);

    ll ans = 0 , cur = 0;
    bool flag = false;

    // for(auto i :S1){
    //     cout<<i<<' ';
    // }
    // cout<<'\n';

    // for(auto i:S2){
    //     cout<<i<<' ';
    // }
    // cout<<'\n';

    for(int ai : S1){
        if( ai > target || flag ) break;
        auto it = S2.lower_bound(target-ai);

        
        if( it!=S2.end() ){
            while( it!=S2.begin() && (*it+ai) > target){
                it--;
                // cout<<" b ";
            }
            cur = *it+ai;
            
            if( cur <=target ){
                ans = max( ans , cur);
            }
            if( ans == target ){
                flag = true;
                break;
            }
        }
    }

    cout<<(flag ? target:ans);
    return 0 ;
}