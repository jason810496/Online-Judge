#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long 
#define pii pair<int,int> 
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
const int MAX_N = 1e5+5;


int n,k,a,b,c, Mx1 ,Mx2 , root ;

vector<pii> G[MAX_N];
void DFS1(int cur,int pa,int sum){
	
	for(auto v:G[cur]){
		if(v.F ==pa) continue;
		DFS1(v.F,cur,sum+v.S);
	}

	if(sum>Mx1){
		root=cur;
		Mx1=sum;
	}
}

void DFS2(int cur,int pa,int sum){
	
	for(auto v:G[cur]){
		if(v.F ==pa) continue;
		DFS2(v.F,cur,sum+v.S);
	}

	Mx2=max( Mx2 , sum);
}

void solve(){

	Mx1= Mx2 = -1 ;
	cin>>n;

	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<n;i++){
		cin>>a>>b>>c;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}

	DFS1(1,1,0);
	DFS2(root,root,0);
	cout<<Mx2<<'\n';
}

int main(){
	OAO
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
