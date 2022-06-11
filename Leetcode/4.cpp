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




class TextEditor {
public:
    int idx;
    string left ;
    deque<char> right;
    TextEditor() {

    }
    
    void addText(string text) {
        left+=text;
    }
    
    int deleteText(int k) {
        if( left.size()>k){
            for(int i=0;i<k;i++){
                left.pop_back();
            }
            return k;
        }
        else{
            int sz = left.size();
            left.clear();
            return sz;
        }
    }
    
    string cursorLeft(int k) {
        int t = k;
        while( left.size() && t ){
            right.push_front( left.back() );
            left.pop_back();
            t--;
        }

        int ret_size = min( int(left.size() ) , 10 );
        int st = int(left.size())-ret_size;

        return left.substr(st , ret_size );
    }
    
    string cursorRight(int k) {
        int t = k;
        while( right.size() && t ){
            left.push_back( right.front() );
            right.pop_front();
            t--;
        }

        int ret_size = min( int(left.size() ) , 10 );
        int st = int(left.size())-ret_size;

        return left.substr(st , ret_size );
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
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
    
    Solution solve1,solve2;

    // Change();

    vector< vector<int> > T1 = {{0,1,1},{1,1,0},{1,1,0}};
    vector< vector<int> > T2 = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    cout<<solve1.minimumObstacles(T1)<<'\n';
    cout<<solve2.minimumObstacles(T2)<<'\n';
    return 0;
}