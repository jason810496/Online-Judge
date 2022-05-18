#include<iostream>
#include<fstream>
using namespace std;
int main(){
    srand(time(NULL));
    ofstream File("Input01.in");
    int n=1000000000;
    for(int i=0;i<n;i++){
        File<<(rand()%10000)+1<<'\n';
    }
    File.close();
    return 0;
}
