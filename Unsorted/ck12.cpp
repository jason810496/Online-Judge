
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// #include<utility>
// #include<vector>
// #include<set>
// #include<map>
// #include<vector>
// #include<queue>
// #include<stack>
// #include<string>
// #include<sstream>
// #include<limits>
// #include<math.h>
// #include<unordered_map>
// #include <iomanip>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
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

signed main(){
    OAO

    string str ; cin>>str;
    int cnt[150]={};

    vector<pii> vec;
    for(const char i:str){
        cnt[int(i)]++;
    }

    for(int i=0;i<150;i++){
        if(cnt[i]){
            // cnt , char
            vec.push_back({-cnt[i],i});
        }
    }

    sort(range(vec));

    for(auto i:vec){
        int j=-i.F;
        while(j--){
            cout<<char(i.S);
        }
    }
    
    return 0;
}
