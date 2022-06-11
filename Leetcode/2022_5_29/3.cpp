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

const int MAX_N = 100005;
const int INF = 1e9;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack< pii > stk;
        stk.push( { nums[0] , 0 } );

        int n  =nums.size() , ans=0 ;

        for(int i=1;i<n;i++){
            int cnt=0;

            while( stk.size() && stk.top().F <= nums[i] ){
                cnt = max( cnt , stk.top().S );
                stk.pop();
            }

            if( stk.size() ) cnt+=1;
            else cnt=0;
            
            ans = max( ans , cnt );
            stk.push( { nums[i] , cnt } );
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

    vector<int> t1 = {10,1,2,3,4,5,6,1,2,3}; 
    vector<int> t2 = {5,3,4,4,7,3,6,11,8,5,11};
    cout<<"ans "<<solve.totalSteps(t1);
    cout<<"ans "<<solve.totalSteps(t2);
    Change();
    return 0;
}