#define F first 
#define S second 
#define ll long long 

class Solution {
public:
    int minimumLines(vector<vector<int>>& stock) {
        int n = stock.size() , ans=1 ;
        if( n==1 ) return 0;

        sort( stock.begin() , stock.end() );

        pair<ll,ll> dxdy1 , dxdy2;

        dxdy1 = { (ll)(stock[1][0]-stock[0][0]) , (ll)(stock[1][1]-stock[0][1]) };

        for(int i=2;i<n;i++){
            dxdy2 = { (ll)(stock[i][0] - stock[i-1][0]) , (ll)(stock[i][1] - stock[i-1][1]) };

            if( dxdy1.F * dxdy2.S != dxdy1.S * dxdy2.F ){
                ans++;
            }
            dxdy1 = dxdy2;
        }

        return ans;
    }
};