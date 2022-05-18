#include<bits/stdc++.h>
using namespace std;
#define MAX_N 200005
/*
AC
DP + dq optimize
(monotonic queue)
*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n , k ,cost[MAX_N], dp[MAX_N];
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>cost[i];
    deque<int> dq;
    for(int i=0;i<=k;i++){
        dp[i]=cost[i];
        while(dq.size() && dp[i] <= dp[dq.back()]){ // min dq
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i=k+1;i<n;i++){
        // out of currrent range 
        while(dq.size() && i-dq.front()> k*2+1) dq.pop_front();

        dp[i]=cost[i]+dp[dq.front()];

        while(dq.size() && dp[i] <= dp[dq.back()]){ // min dq
            dq.pop_back();
        }
        dq.push_back(i);
    }
    // range < right limit
    while(dq.front()+k < n-1 ) dq.pop_front();
  
    cout<<dp[dq.front()];
    return 0;
}