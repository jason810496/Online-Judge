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
    
    int rearrangeCharacters(string s, string target) {
        map<char ,int > M , M2;
        for(char c : s){
            M[ c ]++;
        }

        for(char c:target){
            M2[ c ]++;
        }

        int Mn = INT_MAX ;

        // for(auto c:target){
        //     Mn = min( Mn  , M[ c ] );
        // }

        for(auto i:M2){
            Mn = min( Mn , M[i.F] / i.S );
        }

        return Mn;

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

    Change();
    return 0;
}