#include<bits/stdc++.h>
using namespace std;

void minMax(int a, int b, int c, int *big, int *small) {

    if( a>b && a>c ){
        *big = a;
        *small = (b<c ? b:c);
    }
    else if( b>a && b>c ){
        *big = b;
        *small = (a<c ? a:c);
    }
    else if( c>a && c>b ){
        *big = c;
        *small = (a<b ? a:b);
    }
    
}

int main(){
    srand(time(NULL));

    int a = rand()%50;
    int b = rand()%50;
    int c = rand()%50;

    cout<<a<<' '<<b<<' '<<c<<'\n';

    int *small=&a , *big=&b ; 

    minMax(a,b,c,big,small);

    cout<<&a<<'\n';

    cout<<*big<<' '<<*small<<'\n';
    return 0 ;
}