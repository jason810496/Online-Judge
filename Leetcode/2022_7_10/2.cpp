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

class SmallestInfiniteSet {
public:
    set<int> Set;
    SmallestInfiniteSet() {
        vector<int> arr(1000);
        for(int i=0;i<1000;i++){
            Set.insert(i+1);
        }
    }
    
    int popSmallest() {
        int ans  = *Set.begin();
        Set.erase( Set.begin() );
        return ans;
    }
    
    void addBack(int num) {
        Set.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */


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

    vi t1 = {1,3,5,2,4,8,2,2};
    cout<<solve.minMaxGame(t1);
    return 0;
}