#include<bits/stdc++.h>
using namespace std;

/*
MST AC
*/
vector<int > P,Size;
inline int Find(int x){
    return x==P[x] ? x: P[x]=Find(P[x]);
}
void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    if(a==b) return ;
    if(Size[a] > Size[b] ){
        Size[a]+=Size[b];
        Size[b]=0;
        P[b]=a;
    }  
    else{
        swap(a,b);
        Size[a]+=Size[b];
        Size[b]=0;
        P[b]=a;
    }
}

struct Edge{
    int From,To,W;
    Edge(int f=0,int t=0, int w=0){
        From=f;
        To=t;
        W=w;
    }
};

inline bool comp(Edge a,Edge b){
    return a.W < b.W;
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    vector<Edge> vec(m);
    P.resize(n); // init
    for(int i=0;i<n;i++) P[i]=i;
    Size.resize(n,1);

    for(auto &i:vec){
        cin>>i.From>>i.To>>i.W;
    }

    sort(vec.begin(),vec.end(),comp);

    int cnt=0,MST=0;
    for(int i=0,a,b;i<m;i++){
        a=vec[i].From , b=vec[i].To;
        a=Find(a), b=Find(b);
        if(a==b) continue;
        else{
            Union(a,b);
            MST+=vec[i].W;
            cnt++;
        }
    }
    
    cout<<(cnt<n-1 ? -1:MST);
    return 0;
}