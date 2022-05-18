#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
const int MAX_N = 1e5+5;

bitset<MAX_N> vis;
vector<int> G[MAX_N];
int n;
int DFS(int cur){
	
	vis[cur]=1;
	int ret=1;
	for(int u:G[cur]){
		if(vis[u]) continue;
		ret+=DFS(u);
	}

	return ret;
}
int main(){
	OAO
	int t; cin>>t;
	while(t--){
		int m ,a , b;
		vis=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) G[i].clear();
		while(m--){
			cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		vector<int> ans;

		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				ans.push_back(DFS(i));
			}
		}
		
		cout<<ans.size()<<'\n';
		sort(ans.begin(),ans.end());
		for(int &i:ans) cout<<i<<' ';
		cout<<'\n';
	}
	return 0;
}
