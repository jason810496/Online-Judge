typedef vector<int> vi ; 
#define ll long long 
const int INF = 1e9 ;
class Solution {
    ll MOD = 1e9+7;
public:
    vector< vector<int> > dp;
    ll dc(vi &arr,int l,int r,int &mn ,int &sum){
        if( dp[l][r]!=-1 ){
            return dp[l][r];
        }
        if( l==r ){
            sum+=arr[l];
            mn= min(mn , arr[l] );
            return dp[l][r] = arr[l]*arr[l];
        }

        // int mid = (l+r)/2;
        // int mn_l=INF , mn_r=INF , sum_l=0 , sum_r=0;
        // ll ans= dc(arr, l ,mid , mn_l  ,sum_l );
        // ans = (ans+dc(arr, mid+1 ,r , mn_r , sum_r ) ) %MOD ;

        // int mn_child=INF , sum_child;

        ll ans=0;

        for(int i=l;i<=r;i++){
            ans = (ans+dc(arr,l,i,mn,sum) )%MOD;
            ans = (ans+dc(arr,i,r,mn,sum) )%MOD;
        }

        ans = ( ans + mn*sum)%MOD;

        return dp[l][r] = ans%MOD;
    }
    int totalStrength(vector<int>& strength) {
        int mn = INF , sum = 0 , n=strength.size();
        dp.resize( n , vector<int>(n,-1) );
        return dc( strength , 0 ,n-1 ,mn , sum );
    }
};