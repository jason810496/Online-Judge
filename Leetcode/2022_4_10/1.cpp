#include<bits/stdc++.h>
using namespace std;
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
    int to_int(string s){
        int ret=0;
        for(int i=0;i<s.size();i++){
            ret*=10;
            ret+=s[i]-'0';
        }
        return ret;
    }

    string digitSum(string s, int k) {
        
        while( s.size() > k ){
            int last=0,next=k, n = s.size();

            vector<string> Sub;
            while(next < n){
                Sub.push_back(s.substr(last,next) );
            }

            for(auto i:Sub){
                cout<<i<<'\n';
            }

            break;
        }

        return "";
    }
};