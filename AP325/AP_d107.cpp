#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,P[N],out[N],cnt=0;
bitset<N> mark;
/*
Maximum Independent Set

tree bottom-up using que
*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>P[i];
        out[ P[i]]++;
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(out[i]==0){
            q.push(i);
        }
    }

    while(q.size() ){
        int u=q.front();
        q.pop();

        if(u==0) break; // to root
        if( !mark[u]){
            cnt++;
            mark[P[u]]=1;
        }
        if( --out[P[u]]==0){
            q.push(P[u]);
        }
    }

    if( !mark[0]) cnt++;
    cout<<cnt;

    return 0;
}