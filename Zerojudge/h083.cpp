#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define ll long long 
#define all(x) x.begin(),x.end()
#define PB push_back 

typedef pair<int,int> pii;
typedef vector< vector<int> > vvi;
typedef vector<int> vi;

const int INF = 1e9 ;
const int N = 1005;

inline bool check(string &s){
    int n = s.size()/2;
    for(int i=0;i<n;i++){
        if( s[i]!=s[n+i] ) return false;
    }
    return true;
}

int main (){
    OAO 
    int n ; cin>>n ; 

    map< int , vector<string> > bucket;
    unordered_set< string > ans; 

    string str;

    for(int i=0;i<n;i++){
        cin>>str;
        bucket[ int(str.size() ) ].PB( str );
    }

    // for(auto &i:bucket){
    //     cout<<i.F<<" : ";
    //     for(auto &j:i.S){
    //         cout<<j<<' ';
    //     }
    //     cout<<'\n';
    // }

    for(auto iter=bucket.begin() ; iter!=bucket.end() ; iter++){
        int cur_len = iter->F;
        if( cur_len&1 ){
            auto nxt=iter;
            nxt++;

            while( nxt!=bucket.end() ){
                if( nxt->F&1){
                    for(string &s1:iter->S){
                        for(string &s2:nxt->S){
                            string ST=s1+s2;
                            if( check(ST) ){
                                string TS=s2+s1;
                                if( check(TS) ){
                                    ans.insert(ST);
                                    // ans.insert(TS);
                                }
                            }

                            // cout<<s1<<" "<<s2<<'\n';
                        }
                    }
                }

                nxt++;
            }
        }
        else{
            auto nxt=iter;
            nxt++;

            while( nxt!=bucket.end() ){
                if( !(nxt->F&1) ){
                    for(string &s1:iter->S){
                        for(string &s2:nxt->S){
                            string ST=s1+s2;
                            if( check(ST) ){
                                string TS=s2+s1;
                                if( check(TS) ){
                                    ans.insert(ST);
                                    // ans.insert(TS);
                                }
                            }

                            // cout<<s1<<" "<<s2<<'\n';
                        }
                    }
                }

                nxt++;
            }
        }
    }

    // for(auto i:ans){
    //     cout<<i<<'\n';
    // }

    cout<<int(ans.size());
    return 0;
}