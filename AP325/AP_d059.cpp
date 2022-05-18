#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100005
#define ll long long
/*
PQ + B-search (hard)
d053: Q-4-8 + d049: P-4-9

bad absorb ??
*/
int n,T[MAX_N],Limit;
bool InTime(int N){
    
    priority_queue<int ,greater<int> > pq;
    for(int i=0;i<N;i++) pq.push(0);
    int cur;
    for(int i=0;i<n;i++){
        cur=T[i]+pq.top();
        pq.pop();
        pq.push(cur);

        if( cur>Limit){
            return false;
        }
    }
    return true;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    
    cin>>n>>Limit;
    for(int i=0;i<n;i++){
        cin>>T[i];
    }
    int len=0;
    for(int jump=n/2 ;jump ;jump/=2){
        while(len+jump < n && !InTime(len+jump)){
            len+=jump;
        }
    }
    cout<<len+1;
    return 0;
}