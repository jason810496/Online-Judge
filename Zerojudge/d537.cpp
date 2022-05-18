/*
 ██████╗ ██████╗ ██████╗ ███████╗     ██████╗ ██╗   ██╗████████╗
██╔════╝██╔═══██╗██╔══██╗██╔════╝    ██╔═══██╗██║   ██║╚══██╔══╝
██║     ██║   ██║██║  ██║█████╗      ██║   ██║██║   ██║   ██║   
██║     ██║   ██║██║  ██║██╔══╝      ██║   ██║██║   ██║   ██║   
╚██████╗╚██████╔╝██████╔╝███████╗    ╚██████╔╝╚██████╔╝   ██║   
 ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝     ╚═════╝  ╚═════╝    ╚═╝   
                                                                
 █████╗  ██████╗    ██╗███╗   ██╗                               
██╔══██╗██╔════╝    ██║████╗  ██║                               
███████║██║         ██║██╔██╗ ██║                               
██╔══██║██║         ██║██║╚██╗██║                               
██║  ██║╚██████╗    ██║██║ ╚████║                               
╚═╝  ╚═╝ ╚═════╝    ╚═╝╚═╝  ╚═══╝                                                                                                                                                                            
*/
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 1e6+5;
const int INF = 1e9;

/*
    Flood Fill + binary 
    AC

*/
int n,Color[256],cur_size=0,ans=0,total_size=0;
char target;
struct Box{
    char col;
    int ii,jj,II,JJ;
    bool vis[105][105]={};
};
vector<Box> vec(3);

int G_int[105][105]={};
int main(){
    OAO
    // init color
    Color['R']=1;
    Color[1]='R';
    Color['B']=2;
    Color[2]='B';
    Color['Y']=4;
    Color[4]='Y';
    Color['P']=3;
    Color[3]='P';
    Color['G']=6;
    Color[6]='G';
    Color['O']=5;
    Color[5]='O';
    Color['D']=7;
    Color[7]='D';

    cin>>n;
    for(auto &ele : vec){
        cin>>ele.col>>ele.ii>>ele.jj;
        ele.ii++;
        ele.jj++;
        ele.II=ele.ii;
        ele.JJ=ele.jj;
        G_int[ele.ii][ele.jj]|=Color[ele.col];
        ele.vis[ele.ii][ele.jj]=1;
    }

    cin>>target;

    total_size=3;
    int NN=n*n , N3=NN*3,cnt;

    cur_size=0;
    cnt=0;

    // update max size
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(G_int[i][j]==Color[target]) cur_size++;
        }
    }
    ans=max(ans,cur_size);
    while(total_size < N3){
        cnt=0;

        for(auto &x:vec){
            x.II=min(n,x.II+1);
            x.JJ=min(n,x.JJ+1);
            x.ii=max(1,x.ii-1);
            x.jj=max(1,x.jj-1);

            cnt+=(x.II-x.ii+1)*(x.JJ-x.jj+1);
            for(int i=x.ii;i<=x.II;i++){
                for(int j=x.jj;j<=x.JJ;j++){
                    if(x.vis[i][j]) continue;
                    x.vis[i][j]=1;
                    G_int[i][j]|=Color[x.col];
                }
            }
        }
        
        total_size = cnt;
        cur_size=0;
        // update max size
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(G_int[i][j]==Color[target]){
                    
                    cur_size++;
                }
            }
        }
        
        ans=max(ans,cur_size);
       
    }

    cout<<ans;
    return 0;
}