#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define ll long long 
#define POS first 
#define HT second 
#define all(x) x.begin(),x.end()
#define PB push_back 

typedef pair<int,int> pii;
typedef vector< vector<int> > vvi;
typedef vector<int> vi;

const int INF = 1e9;
const int N = 1e5;

signed main(){
    OAO 
    int n , Lim;
    cin>>n>>Lim;

    list<pii> arr;
    vector<pii> vec(n);
    // F: pos , S: ht
    for(auto &i:vec){
        cin>>i.POS;
    }
    for(auto &i:vec){
        cin>>i.HT;
    }
    arr.PB( { 0 , INT_MAX } );

    for(auto &i:vec){
        arr.PB( { i.POS , i.HT } );
    }
    arr.PB( { Lim , INT_MAX } );

    int MX = 0;
    while( true ){
        bool flag = true;
        auto it=arr.begin();
        it++; // first 
        while( it->POS!=Lim ){
            auto Left=it , Right=it;
            Left-- , Right++;
            if( it->POS-it->HT >= Left->POS ){
                MX =  max( MX , it->HT );
                it = arr.erase( it );
                flag = false;
                continue;
            }
            if( it->POS+it->HT <= Right->POS ){
                MX =  max( MX , it->HT );
                it = arr.erase( it );
                flag = false;
                continue;
            }
            it++;
        }
        if( flag ) break;
    }
    // for(auto i:arr){
    //     cout<<i.POS<<" "<<i.HT<<'\n';
    // }
    cout<<( n - int(arr.size()-2) )<<'\n'<<MX;

    return 0;
}