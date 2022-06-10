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
const int N = 1e5;

int main (){

    int n  , d ; 
    cin>>n>>d; 
    vi arr(n);
    for(auto &i:arr) cin>>i;
    int ans =0 ;

    int cost = arr[0] , sell;
    bool had=true;
    for(int i=1;i<n;i++){
        if( had && arr[i]>= cost + d ){
            ans+= arr[i] - cost;
            sell  = arr[i];
            had = false;
        }
        else if ( !had && arr[i] <= sell -d ){
            cost = arr[i];
            had = true;
        }
    }

    cout<<ans;
    return 0;
}