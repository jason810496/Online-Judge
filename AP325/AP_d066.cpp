#include<iostream>
#define ll long long 
using namespace std;
#define N 100005
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n;cin>>n;
    ll DP1=0,DP2=0,DP3;
    for(int i=1;i<=n;i++){
        cin>>DP3;
        DP3+=min(DP1,DP2);
        DP1=DP2;
        DP2=DP3;
    }
    cout<<DP3;
    return 0;
}