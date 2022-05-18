#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define F first
#define S second
#define PB push_back
#define OuO cin.tie(0);ios_base::sync_with_stdio(0);
const int N = 1e6+5;
int main(){
	OuO
	int n ,k , mx=0;
	priority_queue<int,vector<int>,greater<int> > pq;
	cin>>n>>k;
	for(int i=0;i<k;i++) pq.push(0);

	for(int i=0;i<n;i++){
		int x,temp=pq.top();
		pq.pop();
		cin>>x;
		temp+=x;
		mx=max(mx,temp);
		pq.push(temp);
	}


	cout<<mx;
	return 0;
}
