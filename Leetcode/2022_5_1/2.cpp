#include<bits/stdc++.h>
using namespace std;


#define F first
#define S second
#define ll long long 
#define all(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB push_back
typedef pair<int,int> pii;
const int MAX_N = 100005;
const int INF = 1e9;


class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> M;

        int ans= INF;
        int n =cards.size();
        for(int i=1;i<=n;i++){
            int Last = M[ cards[i-1] ];
            if( Last!=0 ){
                ans=min(ans,i-M[cards[i-1]]+1);
            }
            M[ cards[i-1] ] = i;
        }

        return (ans==INF ? -1:ans);
    }
};
