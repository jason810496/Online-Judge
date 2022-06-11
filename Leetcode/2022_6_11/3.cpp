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
    int n , m;
    bool check( string &s , string &sub  ,unordered_set< int > &Mp , int idx ){
        for(int i=0;i<m;i++){
            if( s[ idx+i]==sub[i] ) continue;
            else {
                if ( Mp.find(int(sub[i])*10000+int(s[idx+i]) )==Mp.end() ) return false;
            }
        }

        return true;
    }
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_set< int > Mp;

        n=s.size();
        m=sub.size();

        for(auto &v:mappings){
            Mp.insert( int(v[0])*10000+int(v[1]) );
        }

        for(int i=0;i+m<=n;i++){
            if( check(s,sub,Mp,i) ) return true;
        }
        return false;
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

    vi t1 = {2,1,4,3,5} , t2 = {1,1,1};
    cout<<solve.countSubarrays(t1,10);
    cout<<solve.countSubarrays(t2,5);
    return 0;
}