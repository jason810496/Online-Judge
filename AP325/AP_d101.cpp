#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define all(x) x.begin(),x.end()

const int N = 1e5+5;

int P[N] , Size[N] , n , k ;

inline int Find(int x){
    return (P[x]==x ? x: P[x] = Find( P[x] ) );
}

void Union(int a,int b){
    if( a<=0 || a>n || b<=0 || b>n ) return;
    a=Find(a);
    b=Find(b);
    if( a==b ) return ;
    
    if( Size[b] > Size[a] ) swap(a,b);

    Size[a]+=Size[b];
    P[b]=a;
}

int main(){
    OAO 
    cin>>n>>k;

    // init
    for(int i=1;i<=n;i++){
        cin>>Size[i];
        P[i]=i;
    }

    
    int root=0 , cnt=0 , MX=0 , MN=1e9;
    multiset<int> Set;
    for(int i=1;i<=n;i++){
        if( Size[i]){
            int root=i;
            i++;
            while( i<=n && Size[i]==1){
                P[i] = root;
                Size[root]++;
                i++;
            }

            MX = max( MX , Size[ root ] );
            MN = min( MN , Size[ root ] );
            Set.insert( Size[ root ] );
        }
    }

    int x, MX_sum=MX , MN_sum=MN ,cur;

    // cout<<MX_sum<<" : "<<MN_sum<<'\n';

    while(k--){
        cin>>x;
        Size[x]=1;
        Set.insert( Size[x] );

        if( x-1>=1 && Size[ Find(x-1) ]>0 ){
            Set.erase( Set.find( Size[ Find(x) ] ) );
            Set.erase( Set.find( Size[ Find(x-1) ] ) );
            Union(x,x-1);
            Set.insert( Size[ Find(x) ] );
        }

        if( x+1<=n && Size[ Find(x+1) ]>0 ){
            Set.erase( Set.find( Size[ Find(x) ] ) );
            Set.erase( Set.find( Size[ Find(x+1) ] ) );
            Union(x,x+1);
            Set.insert( Size[ Find(x) ] );
        }

        MX = max( MX , Size[ Find(x) ] );
        
        MX_sum+=MX;

        // cout<<(*Set.begin() )<<" mn \n";
        MN_sum+= (*Set.cbegin() );
    }

    cout<<MX_sum<<'\n'<<MN_sum;
    return 0;
}