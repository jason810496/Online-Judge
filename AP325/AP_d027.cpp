#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define all(x) x.begin(),x.end()
#define ll long long 

typedef pair<int,int> pii;
typedef pair<bool,ll> P;
// 0: oper
// 1: num

const int INF = 1e9;

ll to_num(string str){
    int n = str.size();

    ll res=0;
    for(int i=0;i<n;i++){
        res*=10;
        res+=int( str[i] ) - '0';
    }
    return res;
}
signed main(){
    OAO 
    string str ,temp; cin>>str ;
    vector<P> token;

    for(char c:str){
        if( '0'<=c && c<='9' ){
            temp.push_back( c );
        }
        else{
            if( temp.size() ){
                token.push_back( {1,to_num(temp)} );
                temp.clear();
            }
            
            token.push_back( {0, (ll)int(c) } );
        }
    }
    if( temp.size() ){
        token.push_back( {1,to_num(temp)} );
        temp.clear();
    }


    vector<ll> num;
    vector<int> oper;

    int Last_oper = -1;
    for(auto i:token){
        if( i.F ){
            if( Last_oper=='*'){
                num[ num.size()-1 ]*=i.S;
            }
            else if( Last_oper=='/'){
                num[ num.size()-1 ]/=i.S;
            }
            else{
                num.push_back( i.S );
            }

        }
        else{
            
            if( i.S=='+' || i.S=='-' ) oper.push_back( i.S );

            Last_oper=i.S;
        }
    }

    ll ans=num[0];
    
    int idx=1;

    for(char op : oper){
        if( op=='+'){
            ans+=num[idx];
        }
        else{
            ans-=num[idx];
        }
        idx++;
    }

    cout<<ans;
    return 0;
}