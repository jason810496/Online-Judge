#include<iostream>
#include<functional>
#include<queue>
#define ll long long
using namespace std;

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    int n,cur;cin>>n;
    ll people=0;
    for(int i=0;i<n;i++){
        cin>>cur;
        people+=cur;
        pq.push(cur);
    }
    ll total=0,cur_top;
    for(int i=0;i<n-1 ;i++){
        cur_top=pq.top();pq.pop();
        cur_top+=pq.top();pq.pop();
        total+=cur_top;
        pq.push(cur_top);
    }
    cout<<people<<'\n'<<total;
    return 0;
}