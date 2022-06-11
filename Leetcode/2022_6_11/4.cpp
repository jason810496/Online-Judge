#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);



#define F first
#define S second
#define ll long long 
#define all(x) x.begin(),x.end()
#define PB push_back
typedef pair<int,int> pii;
typedef pair<long long,int> pli;
typedef pair<int,long long> pil;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
const int MAX_N = 100005;
const int INF = 1e9;


#define ll long long 


class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        vector<ll> prefix(n);
        prefix[0] =nums[0];

        for(int i=1;i<n;i++){
            prefix[i] = nums[i]+prefix[i-1];
        }

        ll ans=0;
        for(int i=0;i<n;i++){
            ll cur = nums[i];
            ll last =0;
            if( i!=0 ) last = prefix[i-1];
            int L=i , R=n-1;

            while( L<=R){
                int mid = (L+R)/2;
                ll len = mid-i+1;
                ll t = len*(prefix[mid]-last);

                if( t<k ){
                    L = mid+1;
                }
                else R = mid-1;
            }

            ans+= (L - i);
        }

        return ans;
    }
};


int main(){
    //OAO

    Solution solve;

    vi t1 = {2,1,4,3,5} , t2 = {1,1,1};
    cout<<solve.countSubarrays(t1,10);
    cout<<solve.countSubarrays(t2,5);
    return 0;
}