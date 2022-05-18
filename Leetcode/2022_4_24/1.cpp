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
    vector<int> intersection(vector<vector<int>>& nums) {

        int n = nums.size();

        map<int,int> M;
        for(auto &i:nums){
            for(int &j:i){
                M[j]++;
            }
        }

        vector<int> ans;

        for(auto &i:M){
            if(i.S==n) ans.PB(i.F);
        }

        return ans;
    }
};

