#include<bits/stdc++.h>

#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 100005;
const int INF = 1e9;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> M;
        for(int i:tasks){
            M[i]++;
        }

        int ans=0;
        for(auto i:M){
            int cur = i.second;
            if( cur <2) return -1;

            int last = cur%3;

            if(last==1 || last==2 ){
                ans+=cur/3+1;
            }
            else {
                ans+=cur/3;
            }
        }

        return ans;
    }
};