#include<iostream>
#include<algorithm>
using namespace std;
#define lowbit(x) x&-x
#define ll long long 
#define N 100005
/*
AC
by Binary Index Tree
*/
ll Inv=0;
int n,BIT[N],D[N],arr[N];
inline void Update(int i){
    for(;i<=n;i+=lowbit(i)){
        BIT[i]++;
    }
}
inline ll Query(int i){
    ll ret=0;
    for(;i;i-=lowbit(i)) ret+=BIT[i];
    return ret;
}
inline bool comp(int a,int b){
    return arr[a]==arr[b] ? (a>b):(arr[a]>arr[b]);
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        D[i]=i;
    }
    sort(D+1,D+n+1,comp);
    for(int i=1;i<=n;i++){
        Update(D[i]);
        Inv+=Query(D[i]-1);
    }
    cout<<Inv;
    return 0;
}