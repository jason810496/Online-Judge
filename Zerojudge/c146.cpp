#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
typedef pair<int,int> pii;
const int MAX_N = 1e9+5;
const int INF = 1e9;
/*
inline bool comp(int a,int b){
    return a>b;
}

struct comparator{
    bool operator() (const int &a,const int &b){
        return a>b;
    }
};

*/


/*
    AC brute force 
*/
int main(){
    OAO
    int n,len,sub_size;
    string str,sub;
    vector<int> vec;
    cin>>sub>>str>>n;

    int ans=0;
    len=str.size();
    sub_size=sub.size();
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(j-i+1 < sub_size || sub[0]!=str[i]||sub[sub_size-1]!=str[j]) continue;
            int L=0;
            
            for(int idx=i;idx<=j && L<sub_size;idx++){
                if(sub[L]==str[idx]){
                    L++;
                }
            }

            if(L>=sub_size) vec.push_back(j-i+1);

        }
    }
    

    if(vec.size() < n){
        for(const int &i:vec) ans+=i;
    }
    else{
        sort(range(vec),greater<int>()) ;
        for(int i=0;i<n;i++) ans+=vec[i];
    }

    cout<<ans;
    
    return 0;
}