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

int n , m ;

struct P{
    ll Atk , Tran;
    int  lose;
    P( ll a=0,ll t=0,int l=0){
        Atk =a ;
        Tran = t;
        lose = l;
    }
}Input[N];

int main (){
    OAO 
    cin>>n>>m;
    // arr only store Input array index 
    vector<int> arr(n);

    for(int i=1;i<=n;i++){
        cin>>Input[i].Atk;
    }
    for(int i=1;i<=n;i++){
        cin>>Input[i].Tran;
    }
    // index 
    for(auto &i:arr) cin>>i ; 

    while( arr.size() > 1 ){
        int cur_size = arr.size() , rd = arr.size()/2;
        int odd_idx = -1;
        
        vi Win , Lost;
        // odd 
        if( cur_size&1 ){
            odd_idx = arr.back();
            arr.pop_back();
        }
        
        for(int k=0;k<rd;k++){
            int L = arr[k*2];
            int R = arr[k*2+1];

            ll L_val = Input[L].Atk*Input[L].Tran;
            ll R_val = Input[R].Atk*Input[R].Tran;

            if( L_val>= R_val ){ // L win ( assert L win )
                // Input[ R ].lose++;
                // // Win change
                // Input[ L ].Atk += R_val/(2*Input[L].Tran);
                // Input[ L ].Tran+= R_val/(2*Input[R].Atk );
                // // Lose change
                // Input[ R ].Atk += Input[ R ].Atk/2;
                // Input[ R ].Tran+= Input[ R ].Tran/2;
            }
            else{ // R win 
                swap( L ,R );
                swap( R_val , L_val);
            }
            // lose++
            Input[ R ].lose++;
            // Win change
            Input[ L ].Atk += R_val/(2*Input[L].Tran);
            Input[ L ].Tran+= R_val/(2*Input[L].Atk );
            // Lose change
            Input[ R ].Atk += Input[ R ].Atk/2;
            Input[ R ].Tran+= Input[ R ].Tran/2;

            Win.PB( L );
            if( Input[R].lose<m ) Lost.PB( R );
        }

        if( odd_idx > 0 ){ // orig is odd
            Win.PB( odd_idx );
        }

        arr.clear();

        for(int &i:Win) arr.PB( i );
        for(int &i:Lost) arr.PB( i );
    }

    cout<<arr.back();
    return 0;
}