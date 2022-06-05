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
    
    string discountPrices(string raw, int dis) {
        vector<int> token;
        vector<double> dis_token;
        
        int t=0;
        bool is_tk = false;
        for(char c : raw){
            if( c=='$' ){
                is_tk = true;
                t=0;
                continue;
            }
            else if( is_tk && !isdigit(c) )is_tk = false;

            if( is_tk ){
                t*=10;
                t+=(c-'0');
                continue;
            }
            else if( t>0 ){
                token.push_back( t );
                t=0;
            }
        }

        // cout<<"token\n";
        // for(auto i: token){
        //     cout<<i<<' ';
        // }
        // cout<<'\n';

        // clear

        is_tk= false;
        string ans;
        for(char c : raw){
            if( c=='$' ){
                is_tk = true;
                ans.push_back(c);
            }
            else if( is_tk && !isdigit(c) )is_tk = false;

            if( is_tk ){
                continue;
            }
            else ans.push_back(c);
            
        }

        // cout<<ans;

        for(auto i:token){
            dis_token.push_back( double(i/dis) );
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
    solve.discountPrices( t1 ,50 );

    string t2 = "1 2 $3 4 $5 $6 7 8$ $9 $10$";
    solve.discountPrices( t2 ,100 );
    return 0;
}