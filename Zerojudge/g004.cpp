#include<bits/stdc++.h>
using namespace std;

// AC
int n,m,cnt,cur,pos[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int arr[11][11],ans[11][11];
inline void F(int I,int J){
	cnt=0,cur=0;
	for(int i=0;i<4;i++){
		int i_=I+pos[i][0],j_=J+pos[i][1];
		if(i_<1||i_>n||j_<1||j_>m) continue;
		if(arr[i_][j_]==0) continue;
		cnt++,cur+=arr[i_][j_];
	}
	ans[I][J]=(cnt==0 ? 0:cur/cnt);
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>arr[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j]==0) F(i,j);
			else ans[i][j]=arr[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
	}

	return 0;
}


