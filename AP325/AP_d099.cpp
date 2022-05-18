#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
const int MX_N = 1e4+5;
vector<int> G[MX_N];
int indeg[MX_N]={},wt[MX_N],From[MX_N],outdeg[MX_N]={};
int main(){
	int n ; cin>>n;

	for(int i=1;i<=n;i++) cin>>wt[i];

	int u, v ,m ;
	cin>>m;
	while(m--){
		cin>>u>>v>>w;
		G[u].push_back(v);
		indeg[v]++;
		outdeg[u]++;
	}

	queue<int> q;
	
	for(int i=1;i<=n;i++){
		if(!indeg[i]){
			q.push(i);
			From[i]=-1;
		}
	}

	while(!q.empty()){
		u=q.front();
		q.pop();

		for(int v:G[u]){
			if(Dis[v]<Dis[u]+wt[v]){
				From[v]=u;
				Dis[v]=Dis[u]+wt[v];
			}

			if(--indeg[v]==0){
				q.push(v);
			}
		}
	}

	int Mx=0 , node;

	for(int i=0;i<n;i++){
		if(Dis[i]>Mx){
			Mx=Dis[i];
			node=i;
		}
	}
	
	vector<int> ans;
	do{
		ans.push_back(node);
		node=From[node];
	}while(node!=-1);

	cout<<Mx<<'\n';
	for(auto it=ans.rbegin();it!=ans.rend();it++){
		cout<<*it<<' ';
	}
	return 0;

}
