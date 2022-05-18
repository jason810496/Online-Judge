#include<iostream>
#include<algorithm>
#define N 100005
#define ll long long 
using namespace std;
/*
AC
Greedy

*/
struct Item{
    int t,d;
}Arr[N];

inline bool comp(Item a,Item b){
    return a.t <b.t;
}
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>Arr[i].t;
    for(int i=0;i<n;i++) cin>>Arr[i].d;

    sort(Arr,Arr+n,comp);
    ll prefix=0,total=0;
    for(int i=0;i<n;i++){
        prefix+=Arr[i].t;
        total+=Arr[i].d-prefix;
    }
    cout<<total;
    return 0;
}