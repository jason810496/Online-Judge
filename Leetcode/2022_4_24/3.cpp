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
    vector<int> countRectangles(vector<vector<int>>& rect, vector<vector<int>>& points) {
        vector<vector<int> > Y_arr(101);
        for(auto &P : rect) {
            Y_arr[ P[1] ].push_back( P[0] );
        }
        for(auto &v : Y_arr) sort(v.begin(), v.end());

        vector<int> ans(points.size());

        int i = 0;
        for(auto &P : points) {
            int posX = P[0], posY = P[1];
            int sum = 0;
            for(int k = posY; k <= 100; k++) {
                sum += Y_arr[k].end() - lower_bound(Y_arr[k].begin(), Y_arr[k].end(), x);
            }
            ans[i++] = sum;
        }
        return ans;
    }
};