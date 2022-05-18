#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec(3);
    for(auto &i:vec) cin>>i;
    for(auto i:vec) cout<<i<<' ';
	for(auto &i:vec){
		i*=i;
	}
	for(auto i:vec)cout<<i<<'\n';
	int a=10,b=20;

    return 0;





}
