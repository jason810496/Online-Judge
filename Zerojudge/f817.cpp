#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include<stdio.h>
#include<vector>
#define min(a,b) (a<b? a:b)
#define max(a,b) (a<b? b:a)


long long T[1005]={};
std::vector<std::vector<long long> > dp;

long long DFS(int L,int R){
    if(R<L ) return 0;
    if(dp[L][R]>=0 ) return dp[L][R];

    register long long ret=9223372036854775807,lt,rt,i;
    for( i=L;i<=R;i++){
        lt=DFS(L+1,i);
        rt=DFS(i+1,R);
        ret=min(ret,max(lt,rt));
    }
    return dp[L][R]=ret+T[L];
}
signed main(){
    int n;
    scanf("%d",&n);
    dp.resize(n+5,std::vector<long long>(n+5,-1));
    register long long Mx=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&T[i]);
        dp[i][i]=T[i];
        Mx+=T[i];
    }

    printf("%lld %lld",DFS(1,n),Mx);
    return 0;
}