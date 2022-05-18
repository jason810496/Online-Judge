#include<stdio.h>
#include<ctype.h>
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
inline int getc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
inline int redi() {
    int ret = 0,f = 0;char ch = getc();
    while (!isdigit (ch)) {
        if (ch == '-') f = 1;
        ch = getc();
    }
    while (isdigit (ch)) {
        ret = ret * 10 + ch - 48;
        ch = getc();
    }
    return f?-ret:ret;
}
int main(){
	int a,b;
	for(int i=0;i<5;i++){
		a=redi();
		printf("%d\n",a);
	}
	// while(!feof(stdin)){
	// 	a=redi(),b=redi();
	// 	printf("%d\n",a+b);
	// }
	return 0;
}
