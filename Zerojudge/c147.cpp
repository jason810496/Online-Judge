#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
typedef pair<int,int> pii;
const int MAX_N = 1005;
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

    dp 0/1 knapsack


*/
int main(){
    OAO
    string str;
    getline(cin,str);
    stringstream ss(str);
    
    int cost[MAX_N],wt[MAX_N],Max_wt,n=0,temp;
    while(ss>>temp){
        wt[n++]=temp;
    }

    for(int i=0;i<n;i++){
        cin>>cost[i];
    }

    cin>>Max_wt;

    int dp[1000005];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++){ // for all items
        for(int w=Max_wt;w-wt[i]>=0 ;w--){
            dp[w]=max(dp[w],dp[w-wt[i]]+cost[i]);
        }
    }

    cout<<dp[Max_wt];
    return 0;
}