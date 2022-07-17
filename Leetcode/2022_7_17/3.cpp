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
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector< vector<pair<string,int> > > vec;
        int n = nums.size() , digit = nums[0].size() ;
        vec.resize( digit+1 );
        for(int d=0 ; d<digit;d++){
            vec[ d+1 ].resize( n);

            for(int i=0;i<n;i++){
                vec[ d+1 ][i] = { nums[i].substr(digit-d-1,d+1) , i };
            }
            sort( all( vec[d+1] ) );
        }

        // for(int d=0;d<digit;d++){
        //     for(int i=0;i<n;i++){
        //         cout<<" ( "<<vec[d+1][i].first<<","<<vec[d+1][i].second<<" ) ";
        //     }
        //     cout<<"\n";
        // }
        vector<int> ans;
        for(auto &q:queries){
            ans.push_back( vec[ q[1] ][ q[0]-1 ].second );
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

    // vi t1 = {1,3,5,2,4,8,2,2};
    // cout<<solve.minMaxGame(t1);

    cout<<int('a')<<" "<<int('A');
    return 0;
}