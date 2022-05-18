#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,0,sizeof(x))
typedef pair<int,int> pii;
const int MAX_N = 1e9+5;
const int INF = 1e9;
/*
inline bool comp(int a,int b){
    return a>b;
}

struct comparator{
    bool operator() (const int &a,const int &b){
        return a>b;
    }
};

*/
/*
    AC

    dp + b search

*/
int main(){
    OAO

    ll dp[100];
    ll L,R;
    cin>>L>>R;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;

    int i=3;
    for(i=3;dp[i-1]<R;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }

    auto itR=upper_bound(dp,dp+i,R);
    auto itL=lower_bound(dp,dp+i,L);
    cout<<itR-itL;
    return 0;
}