#include<bits/stdc++.h>
#define MAX_N 100005
#define ll long long 
using namespace std;
/*
greedy + pq
cool 
*/
struct G{
    int Size,S,F;
    // S: start , F:finish
    G(int s=0,int st=0,int fi=0){
        Size=s;
        S=st;
        F=fi;
    }
};

struct Comparator{
    bool operator()(G a,G b){
        return a.F > b.F;
    }
};
inline bool comp(G a,G b){
    return a.S < b.S;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n;cin>>n;
    vector<G> vec(n);
    for(auto &i:vec){
        cin>>i.Size>>i.S>>i.F;
    }
  
    sort(vec.begin(),vec.end(),comp);

    priority_queue<G,vector<G>,Comparator > pq;
    ll people=0,MAX=0;

    for(auto seg:vec){
        // if(pq.size()) cout<<pq.top().F<<"f ";
        while(pq.size() && seg.S > pq.top().F ){
            people-=pq.top().Size;
            pq.pop();
        }
        pq.push(seg);
        people+=seg.Size;
        // cout<<seg.S<<' '<<seg.F<<' '<<people<<' '<<pq.size()<<'\n';
        MAX=max(MAX,people);
    }
    cout<<MAX;
    return 0;
}