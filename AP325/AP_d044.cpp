#include<iostream>
#include<algorithm>
using namespace std;
#define N 100005
#define ll long long
/*AC*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    ll prefix=0,total=0;
    int arr[N],n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++) prefix+=arr[i],total+=prefix;
    cout<<total;
    return 0;   
}