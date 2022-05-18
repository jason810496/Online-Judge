#include<bits/stdc++.h>
using namespace std;

struct posion{
    int x,y;
}seq[200010];

bool cmp(posion a,posion b){
    return a.x<b.x;
}


int main(){
    
    ifstream fi;
    ofstream out;
    fi.open("Q_3_13_4.in");
    out.open("output02.out");
    int n,L;
    fi>>n>>L;
    for(int i=0;i<n;i++){
        fi>>seq[i].x;
    }
    for(int i=0;i<n;i++)
        fi>>seq[i].y;
    }
    sort(seq,seq+n,cmp);
    
    int best=0;
    deque<int> Max,Min;
    for(int i=0,j=0;i<n;i++){
        while(!Max.empty() && seq[i].x-seq[Max.back()].x>L)
            Max.pop_back();
        while(!Min.empty() && seq[i].x-seq[Min.back()].x>L)
            Min.pop_back();
        while(!Max.empty() && seq[i].y>seq[Max.back()].y)
            Max.pop_front();
        while(!Min.empty() && seq[i].y<seq[Min.back()].y)
            Min.pop_front();
        Max.push_front(i);
        Min.push_front(i);
        
        if(!Max.empty() && !Min.empty() && 
            abs(seq[Max.back()].y-seq[Min.back()].y)>best){
                best=abs(seq[Max.back()].y-seq[Min.back()].y);
            }
        out<<Max.back()<<' '<<Min.back()<<abs(seq[Max.back()].y-seq[Min.back()].y)<<'\n';
    }
    out<<best;
    return 0;
}