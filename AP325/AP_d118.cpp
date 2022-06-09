#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define all(x) x.begin(),x.end()
#define ll long long 
#define PB push_back

typedef pair<int,int> pii;

const int INF = 1e9;
const int N = 1e5+5;

struct line{
    int st ,ed ,val;
    line(int s=0, int e=0, int v=0){
        st =s , ed = e , val =v; 
    }
};

line arr[N];
int dp[N] = { };

signed main(){
    int n ; cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i].st>>arr[i].ed>>arr[i].val;
    }

    sort(arr,arr+n,[&](const line &a,const line &b){
        // return a.st < b.st ;
        return (a.st==b.st ? a.ed< b.ed : a.st<b.st );
    });

    for(int i=0;i<n;i++){
        cout<<arr[i].st<<' '<<arr[i].ed<<' '<<arr[i].val<<'\n';
    }
    cout<<"=======\n\n";

    dp[0] = arr[0].val;

    for(int i=1;i<n;i++){
        int L=0 , R=i , contain = arr[i].val;
        int idx=-1;

        while( L<=R ){
            int mid = (L+R)/2;
            if( arr[L].ed < arr[mid].st ){
                idx = mid;
                L = mid+1;
            }
            else R = mid-1;
        }

        if( idx>0 ) contain+=dp[idx];
        cout<<" case :"<<i<<" "<<idx<<"\n";


        dp[i] = max( dp[i-1] , contain );
    }

    cout<<dp[n-1];

    return 0;
}