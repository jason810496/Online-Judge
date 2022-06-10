#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define ll long long 
#define F first 
#define S second 
#define all(x) x.begin(),x.end()
#define PB push_back 

typedef pair<int,int> pii;
const int INF = 1e9;
const int N = 1e5;

vector<int> ans;

inline int Win(int bro,int sis){
    if( bro==sis ) return 0;
    else if( (bro==0&&sis==2)||(bro==2&&sis==5)|| (bro==5&&sis==0) ) return 1;
    return -1;
}
inline void Out(int op,int k){
    for(const int &i: ans){
        cout<<i<<' ';
    }
    if(op==0){
        cout<<": Drew at round "<<k<<"\n";
    }
    else if(op==1){
        cout<<": Won at round "<<k<<"\n";
    }
    else{
        cout<<": Lost at round "<<k<<"\n";
    }
}
inline int Rev(int x){
    if( x==0) return 5;
    else if( x==2) return 0;
    return 2;
}
signed main(){
    OAO 

    int fst , n;
    cin>>fst>>n;
    vector<int> arr(n);
    for(int &i:arr) cin>>i;

    bool flag = true;
    
    ans.PB( fst );
    if( Win( fst , arr[0] )!=0 ){
        Out( Win( fst , arr[0] ) , 1 );
        flag = false;
    }

    fst=arr[0];
    ans.PB( fst );
    if( Win( fst , arr[1] )!=0 && flag ){
        
        Out( Win( fst , arr[1] ) , 2 );
        flag = false;
    }

    int lst_1 , lst_2;
    for(int i=2;i<n && flag;i++){
        lst_1 = arr[i-1];
        lst_2 = arr[i-2];

        int cur = (lst_1==lst_2 ? Rev(lst_1):lst_1);
        ans.PB( cur );

        if( Win( cur , arr[i] ) !=0 ){
            Out( Win( cur , arr[i] ) ,i+1 );
            flag = false;
        }
    }

    if( flag ){
        Out( 0  , n);
    }

    return 0;
}