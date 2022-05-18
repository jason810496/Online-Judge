#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 2e5+5;
int H[N],P[N];
// montonic stack + binary search
struct node{
    int ht,idx;
    node(int h=0,int i=0){
        ht=h;
        idx=i;
    }
};

struct comparator{
    bool operator() (const node &a,const node &b){
        return a.ht<b.ht;
    }
};

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>H[i];
    for(int i=1;i<=n;i++) cin>>P[i];

    set<node,comparator> s;
    ll ans=0;
    s.insert(node(H[1],1));
    for(int i=2;i<=n;i++){
        int cur=H[i]+P[i];
        auto it=s.upper_bound(cur);
        if(it==s.end()){
            ans+=i-1;
            // cout<<i-1<<'\n';
        }
        else{
            ans+=(i-it->idx-1);
            // cout<<it->ht<<" "<<it->idx<<":  ";
            // cout<<(i-it->idx-1)<<'\n';
        }

        // **  maintain the heigth sequence**

        while( s.size() && H[i]>= s.begin()->ht){
            s.erase(s.begin());
        }
        s.insert(node(H[i],i));
    }
    cout<<ans;

    return 0; 
}