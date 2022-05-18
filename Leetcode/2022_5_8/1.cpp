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
    string largestGoodInteger(string num) {
        int n = num.size();

        vector<string> vec;
        for(int i=0;i<=n-3;i++){
            vec.PB( num.substr(i,3) );

            char c = vec.back()[0];
            if( vec.back()[1]!=c || vec.back()[2]!=c ){
                vec.pop_back();
            }
        }

        sort(all(vec),greater<string>() ) ;

        return (vec.empty() ? "":vec[0]);
    }
};
