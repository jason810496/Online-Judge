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

    bool check(string &s){
        if( s.size()==1 ) return false;

        for(int i=1;i<s.size() ; i++){
            if( isdigit(s[i] ) ) continue;
            return false;
        }
        return true;
    }


    string discountPrices(string sentence, int discount) {
        stringstream input(sentence) , output;
        output.precision(2);
        string str;
        long double rate = double(100-discount)/100.0;

        while( input >>str ){
            if( str[0]=='$' &&check(str) ){
                long double val = stold( str.substr(1) );
                val*=rate;
                output<<'$'<<fixed<<val<<' ';
            }
            else{
                output<<str<<' ';
            }
        }

        str = output.str();
        str.pop_back();
        return str;
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