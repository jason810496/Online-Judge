#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define M 50005
typedef pair<int,int > pii;
int cur_line=0,X_pos[M];
long long N,m,cur_x,cur_val,next_val,ans=0;
inline bool cmp(pii a,pii b){
    return a.F<b.F ? 1 : (a.F==b.F ? a.S>b.S:0);
}
inline bool cmp2(int a,int b){
    return a<b;
}
template<class T>
bool Fast_read(T &num){
    int temp=0,ch = getchar() ;
    while(('0' > ch || ch > '9') && ch!='-' && ch!=EOF) ch = getchar();
    if(ch==EOF) return false;
    bool pos = (ch=='-' ? 0:1);
    for(;'0'<=ch&&ch<='9';ch = getchar()){
        temp= temp*10 + ch - '0';
    }
    num= (pos ? temp:-temp);
    return true;
}

int main(){
    //cin.tie(0);ios_base::sync_with_stdio(0);
    ifstream Input;
    Input.open("/home/jason/Desktop/ap325_release/ch3/Q_3_14_1.in");
    ofstream Output;
    Output.open("/home/jason/Desktop/Cpp text/output02.txt");
    Fast_read(N);
    Fast_read(m);
    cout<<N<<m;
    vector<pii> Line(N);
    for(auto &i:Line) Input>>i.F>>i.S;
    for(int i=0;i<m;i++) Input>>X_pos[i];
    sort(Line.begin(),Line.end(),cmp);
    sort(X_pos,X_pos+m,cmp2);
    
    for(int i=0;i<m;i++){
        cur_x=X_pos[i];

        cur_val=Line[cur_line].F*cur_x +Line[cur_line].S;
        
        if(cur_line+1!=N){
            next_val=Line[cur_line+1].F*cur_x +Line[cur_line+1].S;
        }
        else next_val=INT_MIN;

        while(next_val>=cur_val&&cur_line+1!=N){
            cur_val=next_val;
            next_val=Line[cur_line+1].F*cur_x +Line[cur_line+1].S;
            cur_line++;
        }
        ans+=cur_val;
        Output<<ans; 
    }
    
    //Output<<ans;
    return 0;
}