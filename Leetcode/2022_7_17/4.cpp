#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);



#define F first
#define S second
#define ll long long 

#define PB push_back
typedef pair<int,int> pii;
typedef pair<long long,int> pli;
typedef pair<int,long long> pil;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
const int MAX_N = 100005;
const int INF = 1e9;


#define all(x) x.begin(),x.end()
class Solution {
public:

    bool check(int d ,vector<int> &arr){
        for(auto &i:arr){
            if( i%d!=0 ) return false;
        }

        return true;
    }
    int minOperations(vector<int>& nums, vector<int>& arr) {

        int ans=0;

        unordered_map<int,int> Map;

        for(int i:nums ) Map[i]++;

        priority_queue<int, vector<int>,greater<int> > pq;
        for(auto &i:Map){
            pq.push( i.first );
        }

        while( pq.size() ){
            int cur = pq.top();
            if( check( cur , arr) ){
                break;
            }
            ans+= Map[ cur ];
            pq.pop();
        }

        if( ans!=nums.size() ) return ans;
        return -1;
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


    vector<int> a = {3,2,6,2,35,5,35,2,5,8,7,3,4};

    sort( all(a) );

    for(auto i : a){
        cout<<i<<' ';
    }

    // vi t1 = {1,3,5,2,4,8,2,2};
    // cout<<solve.minMaxGame(t1);

    // cout<<int('a')<<" "<<int('A');
    return 0;
}

/*
[3,2,6,2,35,5,35,2,5,8,7,3,4]
[105,70,70,175,105,105,105]
*/