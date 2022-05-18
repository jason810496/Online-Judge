#include<bits/stdc++.h>
using namespace std;
#define N 200005
/*
sliding windows AC

*/
int n,L,MAX_D=0,cur,arr[N];
deque<int > dq_min,dq_max;
void add_min(int i){
    while(dq_min.size()&&arr[dq_min.back()]>=arr[i]){
        dq_min.pop_back();
    }
    dq_min.push_back(i);
}
void add_max(int i){
    while(dq_max.size()&&arr[dq_max.back()]<=arr[i]){
        dq_max.pop_back();
    }
    dq_max.push_back(i);
}
void upd(int i){
    if (i-dq_min.front()>=L) dq_min.pop_front();
    if(i-dq_max.front()>=L ) dq_max.pop_front();
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n>>L;
    for(int i=1;i<=n;i++) cin>>arr[i];
    
    for(int i=1;i<=n;i++){
        upd(i);
        add_min(i),add_max(i);
        cur = arr[dq_max.front()]-arr[dq_min.front()];
        MAX_D =max(MAX_D ,cur);
        //cout<<cur<<'\n';
    }
    cout<<MAX_D;
    return 0;
}