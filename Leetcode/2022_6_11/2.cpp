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

class Solution {
public:
    vector<int> successfulPairs(vector<int>& A, vector<int>& B, long long success) {
        
        int n=B.size();
        sort(all(B));

        vector<int> ans;
        for(ll cur : A){
            int L=0 , R=n-1 , cnt=0;
            ll t;

            while( L<=R){
                int mid = (L+R)/2;
                if( (ll)(B[mid]*cur)<success ){
                    L = mid+1;
                }
                else R=mid-1;
            }

            // cout<<L<<"\n";
            ans.PB( n-L );
        }
        
        return ans;
    }
};


void Change(){
    string str;
    getline(cin,str);

    for(char i:str){
        if( i=='[') cout<<'{';
        else if(i==']') cout<<'}';
        else cout<<i;
    }
    cout<<'\n';
}




int main(){
    //OAO

    Solution solve;

    vi t1 = {1,3,5,2,4,8,2,2};
    cout<<solve.minMaxGame(t1);
    return 0;
}