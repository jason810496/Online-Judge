#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool prim(int num){
    if(num==1) return false;
    if(num==2) return true;
    int cnt=0;
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }

    return true;
}
signed main(){
    //cin.tie(0);ios_base::sync_with_stdio(0);
    string str;
    while(cin>>str){
        int cnt=0,cur=0;
        vector<int> vec;
        for(const char ch :str){
            cur*=10;
            cur+=ch-'0';
            if(!cur) continue;
            if( prim(cur) ){
                cnt++;
                vec.push_back(cur);
                cur=0;
            }
        }
        cout<<cnt<<'\n';
        for(const int i:vec){
            cout<<i<<'\n';
        }
        cout<<'\n';
    }
    return 0;   
}