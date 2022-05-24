#pragma GCC optimize("O2")
#include<stdio.h>

/*
    AC : BIT + XOR + I/O optimize 
    https://zerojudge.tw/ShowProblem?problemid=c651
*/

#define lowbit(x) x&-x

int BIT[1000005] , arr[1000005];


inline int GetInt() {
	int x = 0, c = getchar(), neg = 0;
	while(('0' > c || c > '9') && c!='-' && c!=EOF) c = getchar();
	if(c == '-') neg = 1, c = getchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = getchar();
	if(neg) x = -x;
	return x; // returns 0 if EOF
}



int n;
void Update(int i ,int val ){
    for(; i<=n ;i+=lowbit(i) ){
        BIT[i]^=val;
    }
}

int Query(int i ){
    int res = 0;
    for( ; i ; i-=lowbit(i) ){
        res^=BIT[i];
    }
    
    return res;
}

signed main(){
    // OAO
    int q;
    // cin>>n>>q;
    // scanf("%d%d" , &n, &q);
    n = GetInt();
    q = GetInt();

    for(int i=1;i<=n;i++){
        // cin>>arr[i];
        // scanf( "%d" , &arr[i] );

        arr[i] = GetInt();
        Update(i,arr[i]);
    }

    int L, R ,idx, v ;
    int oper;
    while(q--){
        // cin>>oper;
        // scanf( "%d" , &oper );
        oper = GetInt();
        if( oper ){
            // cin>>idx>>v;
            // scanf("%d%d" , &idx, &v );

            idx = GetInt(); v = GetInt();

            Update( idx , arr[idx] ); // A xor A =0
            Update( idx , v ); // V xor 0 = V 
            arr[ idx ] = v;
        }
        else{
            // cin>>L>>R;
            // scanf("%d%d"  , &L, &R );

            L = GetInt() ; R = GetInt();

            // cout<< (Query(R)^Query(L-1)) <<'\n';
            printf( "%d\n"  , ( Query(R)^Query(L-1) ) );
        }
    }
   

    return 0;
}