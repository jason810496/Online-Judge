#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define ll long long 
#define all(x) x.begin(),x.end()

typedef pair<int,int> pii;

const int INF = 1e9;

signed main(){
	OAO;
	int n , m ;
	cin>>n>>m;

	vector<  vector<int> > G(n+1) , GT(n+1); //GT : reverse Graph	
	vector<int> Wt(n+1) , In(n+1) , Out(n+1) , Dis(n+1 , -INF ); // In: In degree , Out: Out degree 

	for(int i=1;i<=n;i++) cin>>Wt[i];

	while(m--){
		int a,b;
		cin>>a>>b;

		G[a].push_back(b);
		GT[b].push_back(a);
		In[b]++;
		Out[a]++;
	}

	queue<int> q;

	for(int i=1;i<=n;i++){
		if( !In[i] ){
			q.push(i);
			Dis[i] = Wt[i];
		}
	}

	while(q.size() ){
		int cur = q.front();
		q.pop();

		for(int nxt : G[cur] ){
			if( !--In[nxt] ){
				q.push( nxt );
			}
			Dis[nxt] = max( Dis[nxt] , Dis[cur]+Wt[nxt] );
		}
	}

	int MX_Time=0;
	for(int i=1;i<=n;i++){
		if( !Out[i] && MX_Time < Dis[i] ){
			MX_Time = Dis[i];
		}
	}

	for(int i=1;i<=n;i++){
		if( Dis[i]==MX_Time && !Out[i] ){
			q.push(i);
		}
	}

	set<int> key;

	// backtrade 
	while( q.size() ){
		int cur = q.front();
		q.pop();

		key.insert( cur );

		for(int last : GT[ cur ] ){
			if( Dis[cur]==Dis[last]+Wt[cur] && key.find( last )==key.end() ){
				q.push( last );
			}
		}
	}
	cout<<MX_Time<<'\n';
	for(int i:key){
		cout<<i<<' ';
	}
	return 0;
}