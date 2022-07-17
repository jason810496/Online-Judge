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

    inline int dig(int n ){
        int ans=0;
        while( n ){
            ans+=n%10;
            n/=10;
        }

        return ans ;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int , priority_queue<int> > Map;

        for(int &num : nums ){
            Map[ dig(num) ].push( num ) ;
        }

        int ans = -1 , cur =0 ;

        for(auto &i:Map){
            if( i.second.size()>=2 ){
                cur = 0;
                cur+=i.second.top();
                i.second.pop();
                cur+=i.second.top();
                i.second.pop();

                ans = max( ans , cur );
            }
        }

        return ans ;
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