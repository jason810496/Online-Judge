#include<bits/stdc++.h>
using namespace std;

bool check_prime(int n){
    if(n<2) return false;
    for(int i=2 ;i*i<=n ;i ++){
        if( n%i==0 ) return false;
    }
    return true;
}

bool check_Prime_6k(int n){
    // 6n±1 Method
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    if(n%2==0 || n%3==0 ) return false;
        
    for(int i=5; i*i<=n ;i+=6){
        if( !(n%i) || !(n%(i+2)) ){
            return false;
        }
    }
    return true;
}

const int Upper = sqrt(INT_MAX);
void sieve(int Upper){

    bitset<100005> flag=0;
    vector<int> Prime;
    
    for(int i=2;i<Upper;i++){
        if(!flag[i]){
            Prime.push_back(i);
            for(int j=i*i;j<Upper;j+=i){
                flag[j]=true;
            }
        }
    }
}

void sieve_linear(){
    bitset<100005> flag=0;
    vector<int> Prime;

    for(int i=2;i<Upper;i++){

        if(!flag[i]) Prime.push_back(i);
        for(int j=0;i*Prime[j]<Upper;j++){
            flag[ i*Prime[j] ]=true;
            if( !i%Prime[j] ) break;
        }
    }
}

int GCD(int a,int b){ // (a<b)
    if(a==0) return b;
    return GCD(b%a,a);
}

int LCM(int a,int b){
    return a*b/GCD(a,b);
}

int extend_GCD(int a,int b,int &x,int &y){
    if(a==0){
        x=0,y=1;
        return b;
    }

    int x2,y2,g=extend_GCD(b%a,a,x,y);
    x=y2 - (b/a)*x2;
    y=x2;

    return g;
}

int mod_inv_naive(int a,int mod){ 
    // work whem mod is prime
    for(int x=1;x<mod;x++){
        if( ( (a%mod)*(x%mod))%mod==1 ){
            return x;
        }
    }
}

int mod_inv_eucliean(int a,int mod){
    int x,y,g=extend_GCD(a,mod,*x,*y);
    if( g==1){
        int ans=(x%mod+mod)%mod;
        cout<<"Mod Inv = "<<ans;
    }
    else{
        cout<<"Mod Inv doesn't exist";
    }
}


int fast_pow(int a,int n){
    if(n==0) return 1;
    if(n&1) return a*fast_pow(a,n-1);
    else{
        int temp=fast_pow(a,n/2);
        return temp*temp;
    }
}

int mod_inv_fermet(int a,int mod){
    int g=__gcd(a,mod);
    if(g==1){
        return fast_pow(a,mod-2);
    }
}

bool is_Prime_femert(int n,int k){
    if(n<=1 || n==4 ) return false;
    if(n<=3 ) return true;

    while(k--){
        int a=rand()%(n-4)+2; // rand num : [2,n-2]

        if( gcd(a,n)>1) return false; // abs not prime (same divider with a)
        if( fast_pow(a,n-1)!=1 ) return false; // fermet's little theorem

    }

    return true; // possible prime
}


int main(){
    return 0;
}