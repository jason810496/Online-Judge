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
    int partitionArray(vector<int>& arr, int k) {
        
        sort( all(arr) );

        int mx=arr[0] , mn = arr[0] , n = arr.size();
        int ans = 1 ;
        for(int i=1;i<n;i++){
            mn = min( mn ,arr[i] );
            mx = max( mx , arr[i] );

            if( mx - mn > k ){
                ans++;
                mx = mn = arr[i];
            }
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

    // Change();

    string t1 = "there are $1 $2 and 5$ candies in the shop";
    // solve.discountPrices( t1 ,50 );

    string t2 = "1 2 $3 4 $5 $6 7 8$ $9 $10$";
    // solve.discountPrices( t2 ,100 );
    return 0;
}