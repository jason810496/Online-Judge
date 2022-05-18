#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	int n,q,x;
	cin>>n>>q;
	unordered_set<int> Set;
	while(n--){
		cin>>x;
		Set.insert(x);
	}
	while(q--){
		cin>>x;
		for(const int &i:Set){
			
			if(Set.find(i+x)!=Set.end()){
				goto End;
			}
			else if(Set.find(i-x)!=Set.end()){
				goto End;
			}
		}
		cout<<"NO\n";
		continue;
		End:
		cout<<"YES\n";
	}
	return 0;

}
