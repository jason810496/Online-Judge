#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#define ll long long
/*
AC hard
*/
using namespace std;
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,m;cin>>n>>m;
    ll x,ans=INT32_MIN;
    priority_queue<int,vector<int> ,greater<int> > pq;
    while(m--) pq.push(0);
    for(int i=0;i<n;i++){
        cin>>x;
        x+=pq.top();
        pq.pop();
        pq.push(x);
        ans=max(x,ans);
    }
    cout<<ans;
    return 0;
}