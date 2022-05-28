#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100005
#define ll long long
/*
    PQ + B-search (hard)
    d053: Q-4-8 + d049: P-4-9

    AC
*/
int n,Limit , arr[MAX_N] = {};

bool InTime(int cnt){
    
    priority_queue<int , vector<int> ,greater<int> > pq;
    while( cnt--) pq.push(0);

    int cur ;

    for(int i=0;i<n;i++){
        cur=arr[i]+pq.top();
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
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int L=1 , R=n;

    while(L<=R){
        int mid=(R+L)/2 ;
        if( InTime(mid) ) R=mid-1;
        else L= mid+1;
    }

    cout<<L;
    return 0;
}