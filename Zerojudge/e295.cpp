#include<fstream>
inline int Fast_IO2(){
    int temp=0,ch = getchar() ;
    while(('0' > ch || ch > '9') && ch!='-' && ch!=EOF) ch = getchar();
    bool pos = (ch=='-' ? 0:1);
    for(;'0'<=ch&&ch<='9';ch = getchar()){
        temp= temp*10 + ch - '0';
    }
    return (pos ? temp:-temp);
}


inline char Fast_getchar(){
    int S = 1<<20; // buffer size
    char buf[S], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
}

inline int Fast_IO3(){
    int temp=0,ch = Fast_getchar() ;
    while(('0' > ch || ch > '9') && ch!='-' && ch!=EOF) ch =Fast_getchar();
    bool pos = (ch=='-' ? 0:1);
    for(;'0'<=ch&&ch<='9';ch = Fast_getchar()){
        temp= temp*10 + ch - '0';
    }
    return (pos ? temp:-temp);
}
int main(){
    int a,b,c;
    while(!feof(stdin)){
		a=Fast_IO3(),b=Fast_IO3();
        c=a+b;
        printf("%d\n",c);
    }
    return 0;
}

