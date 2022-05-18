#include<iostream>
#include<algorithm>
using namespace std;
#define N 100005
#define ll long long
/*
AC 
greedy hard ?
*/
struct obj{
    ll w,t;
}Item[N];
//w[i]*t[i+1] - w[i+1]*t[i] < 0 -> better
inline bool comp(obj a,obj b){ 
    return a.t *b.w < a.w*b.t ;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    ll total=0,prefix=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>Item[i].t;
    }
    for(int i=0;i<n;i++){
        cin>>Item[i].w;
    }

    sort(Item,Item+n,comp);
    for(int i=0;i<n;i++){
        prefix+=Item[i].t;
        total+=prefix*Item[i].w;
    }
    cout<<total;
    return 0;   
}