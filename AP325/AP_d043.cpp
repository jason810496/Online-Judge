#include<iostream>
#include<algorithm>
using namespace std;
#define N 100005
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,cnt=0,en[N],our[N];
    cin>>n;
    for(int i=0;i<n;i++) cin>>en[i];
    for(int i=0;i<n;i++) cin>>our[i];
    sort(en,en+n);
    sort(our,our+n);

    for(int i=0,j=0 ;i<n && j<n ;i++){ // for each ourlie
        if(our[i]>en[j]){
            j++;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;   
}