#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll unsigned long long 
#define all(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB push_back
typedef pair<int,int> pii;
const int MAX_N = 100005;
const int INF = 1e9;

struct BigInt{
    string digits="";

    BigInt(string  s){
        int n = s.size();
        for (int i = n - 1; i >= 0;i--){
            digits.push_back(s[i] - '0');
        }
    }
    
};
bool cmp(const BigInt&a,const BigInt&b){
    int n = a.digits.size(), m = b.digits.size();
    if(n != m)
        return n < m;
    while(n--)
        if(a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    return false;
}

string to_str(BigInt&a){
    for(int i=0;i<a.digits.size();i++){
        a.digits[i]+='0';
    }
    reverse(all(a.digits));
    return a.digits;
}

class Solution {
public:
    
    string removeDigit(string str, char dig) {
        ll mx = 0;
        int n = str.size();
        
        string cur="";
        BigInt ans("");

        for(int i=0;i<n;i++){
            char ch = str[i];
            if( ch==dig){
                string temp = cur;
                for(int j=i+1;j<n;j++){
                    temp.PB(str[j]);
                }
                BigInt now(temp);

                if( cmp(ans,now) ){
                    ans=now;
                }
            }
            cur+=ch;
        }

        
        return to_str(ans);
    }
};