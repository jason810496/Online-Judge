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
#define max(a,b) (a>=b ? a:b)
#define min(a,b) (a<=b ? a:b)
#define DBG cout<<"------------";
typedef pair<long,long> pii;
const int MAX_N = 1e6+5;
const int INF = 1e9;
int n,Dis;
long long Dis_2;


/*
	WA ... 
*/
inline bool match(const pii &a,const pii &b){
	int dx=a.F-b.F , dy=a.S-b.S;
	return (dx*dx+dy*dy) <= Dis_2;
	//return (abs(a.F-b.F)+abs(a.S-b.S) )<=Dis;
}

int main(){
    OAO
	cin>>Dis>>n;
	Dis_2 = Dis*Dis*2;
	vector<pii > vec(n);
	for(auto &i:vec) cin>>i.F>>i.S;
	// sort(range(vec),[&](pii a,pii b){
	// 	return (a.F < b.F ? 1:( a.F==b.F ? (a.S < b.S):0));
	// });
	sort(range(vec));

	// DBG
	// for(auto i:vec){
	// 	cout<<i.F<<' '<<i.S<<'\n';
	// }
	// DBG

	int ans=0;
	for(int i =0;i<n;i++){
		int L=max(i-15,0),R=min(i+15,n-1);

		for(int j=L;j<=R;j++){
			if(i==j) continue;
			if(match(vec[i],vec[j])) ans++;
		}
	}

	cout<<ans/2;
    return 0;
}