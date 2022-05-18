#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB push_back
typedef pair<int,int> pii;
const int MAX_N = 100005;
const int INF = 1e9;

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pii> Set;

        for(auto &i:circles){
            int X=i[0] , Y=i[1], R=i[2];

            for(int x=X-R;x<=X+R;x++){
                for(int y=Y-R;y<=Y+R;y++){
                    int dx = x-X;
                    int dy = y-Y;

                    if(dx*dx+dy*dy <= R*R ){
                        Set.insert({x,y});
                    }
                }
            }
        }

        return Set.size();
    }
};