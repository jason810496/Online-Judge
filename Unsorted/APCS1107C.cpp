#include<bits/stdc++.h>
using namespace std;

bool stick[N][N]={};
int G[N][N]={};

inline in(int x,int y)
void upd(){
	int ret=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) if(G[i][j]) ret++;
	}

	cur=ret;
	Mx=max(Mx,cur);
}


void Add(int x,int y){

	for(int k=0;k<4;k++){
		if(check(x,y)){
			mark(x,y);
		}
	}
}
