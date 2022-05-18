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
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        vector<int> prefix(n+1);

        prefix[1] = (nums[0]%p==0 ? 1:0);
        for(int i=2;i<=n;i++){
            prefix[i] = (nums[i-1]%p==0 ? 1:0);
            prefix[i] +=prefix[i-1];
        }

        unordered_set<string> Set;
        string str;
        for(int i=0;i<n;i++){
            str.push_back( char('0'+nums[i]) );
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if( prefix[j]-prefix[i-1]<=k){
                    string cur = str.substr(i-1,j-i+1);
                    if(Set.find( cur )==Set.end()){
                        // cout<<i<<' '<<j<<' '<<cur<<'\n';
                        Set.insert(cur);
                    }
                }
            }
        }

        return Set.size();
    }
};

