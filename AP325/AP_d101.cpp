#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int P[N],Size[N];
// unfinished DSU
multiset<int> Set;
inline int Find( int x){
    return x==P[x] ? x: P[x]=Find(P[x]);
}
void Union(int a,int b){
    a=Find(a) , b=Find(b);
    Set.erase(Set.find(Size[a]));
    Set.erase(Set.find(Size[b]));

    if(a==b) return ;
    if(Size[a] > Size[b]){
        Size[a] +=Size[b];
        Size[b]=0;
        P[b]=a;
        Set.insert(P[a]);
    }
    else{
        swap(a,b);
        Size[a] +=Size[b];
        Size[b]=0;
        P[b]=a;
        Set.insert(P[a]);
    }
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,k;
    vector<int> G(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>G[i];
        P[i]=i;
        Size[i]=G[i];
    }
    int MAX=1,MIN=1e5,s_Mx=0,s_Mn=0;
    int id=1;
    list<int > Mx_i,Mn_i;

    // init
    while(id<=n){
        int j=id+1;
        while(j<=n && G[j]){
            Union(id,j);
            j++;
        }

        id=j;
    }
    s_Mx+=*(--Set.end());
    s_Mn+=*(Set.begin());

    for(auto i:Set){
        cout<<i<<' ';
    }
    // while(k--){
        
    //     int t;
    //     cin>>t;
    //     // mark red
    //     G[t]=1;
    //     Size[t]=1;

    //     if(t+1 <=n && G[t+1]) Union(t,t+1);
    //     if(t-1 >0  && G[t-1]) Union(t,t-1);

    //     t=Find(t);
    //     for(auto it=Mn_i.begin();it++;it!=Mn_i.end()){
    //         if(Size[Find(*it)] <= MIN){
    //             MIN=Size[Find(*it)];
    //         }
    //     }
    // }
    return 0;
}