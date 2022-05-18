/*
 ██████╗ ██████╗ ██████╗ ███████╗     ██████╗ ██╗   ██╗████████╗
██╔════╝██╔═══██╗██╔══██╗██╔════╝    ██╔═══██╗██║   ██║╚══██╔══╝
██║     ██║   ██║██║  ██║█████╗      ██║   ██║██║   ██║   ██║   
██║     ██║   ██║██║  ██║██╔══╝      ██║   ██║██║   ██║   ██║   
╚██████╗╚██████╔╝██████╔╝███████╗    ╚██████╔╝╚██████╔╝   ██║   
 ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝     ╚═════╝  ╚═════╝    ╚═╝   
                                                                
 █████╗  ██████╗    ██╗███╗   ██╗                               
██╔══██╗██╔════╝    ██║████╗  ██║                               
███████║██║         ██║██╔██╗ ██║                               
██╔══██║██║         ██║██║╚██╗██║                               
██║  ██║╚██████╗    ██║██║ ╚████║                               
╚═╝  ╚═╝ ╚═════╝    ╚═╝╚═╝  ╚═══╝                                                                                                                                                                            
*/
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define ll long long 

signed main(){
    OAO
    string str;
    cin>>str;
    stack<char> oper;
    stack<ll> NUM;
    ll num=0;
    for(char ch : str){
        if(isdigit(ch)){
            num=(num*10+ch-'0')%100000;
        }
        else{
            if(ch=='+'){
                NUM.push(num);
                num=0;
                if(oper.top()=='*'){
                    ll a=NUM.top() ; NUM.pop();
                    ll b=NUM.top() ; NUM.pop();
                    NUM.push((a*b)%100000);
                }
                
                oper.push(ch);
            }
            else{// '*'
                NUM.push(num);
                num=0;
                if(oper.top()=='*'){
                    ll a=NUM.top() ; NUM.pop();
                    ll b=NUM.top() ; NUM.pop();
                    NUM.push((a*b)%100000);
                }
                
                oper.push(ch);
            }
        }
    }
    NUM.push(num);
    if(oper.top()=='*'){
        ll a=NUM.top() ; NUM.pop();
        ll b=NUM.top() ; NUM.pop();
        NUM.push(a*b);
    }
    ll ans=0;
    while(!NUM.empty()){
        //cout<<NUM.top()<<'\n';
        ans=(ans+NUM.top())%100000;
        NUM.pop();
    }
    cout<<ans%100000<<'\n';
    return 0;
}