
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);


int main(){
    OAO
    int n ; 
   
   vector<int> base = {1000 , 500 , 100 , 50 , 10 ,5 , 1};
    while( cin>>n ){
        cout<<n<<" = ";
        vector<int> ans(7) ,cur(7);

        for(int i=0;i<7 && n ;i++){
            ans[i] = n/base[i];
            n-= ans[i]*base[i];
            cur[i] = n ;
        }

        for(int i=0;i<7;i++){
            if( ans[i]==0 ) continue;
            cout<<base[i]<<"*"<<ans[i]<<( cur[i] ? " + ":"");
        }
        cout<<'\n';
    }
   
    return 0;
}