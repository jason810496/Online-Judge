#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define PB push_back
typedef pair<int,int> pii;

const int N = 20005;
pii record[N];
int n, m , p ,k ;
vector<int> G[N];
int mark[N];

bool bipart(){

	fill(mark,mark+n,-1);
	for(int i=0;i<n;i++){
		if(mark[i]<0){
			
			mark[i]=0;
			queue<int> q;
			
			q.push(i);

			while( !q.empty()){

				int u=q.front();
				q.pop();

				for(int v:G[u]){
					if(mark[v]<0){
						mark[v]=!mark[u];
						q.push(v);
					}
					else if(mark[v]==mark[u]) return false;
				}
			}
		}
	}

	return true;
}
int main(){
	OAO

	int x,y;

	cin>>n>>m;
	while(m--){
		cin>>x>>y;
		G[x].PB(y);
		G[y].PB(x);
	}

	cin>>p>>k;

	for(int i=1;i<=p;i++){
		
		for(int j=0;j<k;j++){
			cin>>x>>y;
			record[j]={x,y};
			G[x].PB(y);
			G[y].PB(x);
		}

		if(!bipart()) cout<<i<<'\n';

		for(int j=0;j<k;j++){
			G[ record[j].F ].pop_back();
			G[ record[j].S ].pop_back();
		}
	}
	return 0;
}
