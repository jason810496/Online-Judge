#include<iostream>
#include<algorithm>
using namespace std;
#define N 100005
#define ll long long
struct obj{
    ll w,t;
}Item[N];

/*
AC ok
*/
// W[a]*T[b] < W[b]*T[a] 
inline bool comp(obj a,obj b){ 
    return a.w *b.t < b.w*a.t ;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    ll total=0,prefix=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>Item[i].w;
    for(int i=0;i<n;i++) cin>>Item[i].t;

    sort(Item,Item+n,comp);
    for(int i=0;i<n;i++){
        
        total+=prefix*Item[i].t;
        prefix+=Item[i].w;
    }
    cout<<total;
    return 0;   
}