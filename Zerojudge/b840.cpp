#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
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
    dp : max sub matrix

*/
int main(){
    OAO
    int n; cin>> n;
    vector<vector<int> > dp(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1,x;j<=n;j++){
            cin>>x;
            dp[i][j]=x+dp[i-1][j];
        }
    }

    int MAX=0;
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){

            int cur=0;
            for(int j=1;j<=n;j++){
                cur=max(0,cur+dp[i][j]-dp[k-1][j]);
                MAX=max(cur,MAX);
            }
        }
    }

    cout<<MAX;
    return 0;
}