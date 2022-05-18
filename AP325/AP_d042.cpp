#include<iostream>
using namespace std;
/*
AC
*/
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int t,n,cnt;cin>>t;
    while(t--){
        cnt=0;
        cin>>n;
        if(n>=50){
            cnt+=n/50;
            n%=50;
        }
        if(n>=10){
            cnt+=n/10;
            n%=10;
        }
        if(n>=5){
            cnt+=n/5;
            n%=5;
        }
        if(n>=1) cnt+=n;
        cout<<cnt<<'\n';
    }
    return 0;
}