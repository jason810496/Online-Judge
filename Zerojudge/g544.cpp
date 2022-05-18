#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
typedef pair<int,int> pii;

ll ans=0;

int n , k ;

int main(){

	cin>>n>>k;
	vector<pii > vec(n);

	for(pii &i:vec) cin>>i.F;
	for(pii &i:vec) cin>>i.S;

	stack<int > q;

	q.push(0);

	for(int i=1;i<n;++i ){
		if( q.empty() || vec[q.top()].S != vec[i].S  ) q.push(i);
		else{
			int temp=q.top(); q.pop();
			q.push( (vec[temp].F>vec[i].F ? temp:i));
		}
	}

	while( !q.empty()){
		ans+=vec[q.top()].F  ;
		q.pop();
	}

	cout<<ans;
	return  0;
}
