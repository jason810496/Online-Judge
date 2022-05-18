
#include<stdio.h>
inline int fast_io(){
	int temp=0,ch=getchar();
	bool pos = (ch=='-'? 0:1);
	for(;'0'<=ch&&ch<='9';ch=getchar()){
		temp = temp*10 +ch -'0';
	}
	return (pos ? temp:-temp);
}


inline int nextint() {
	int x = 0, c = getchar(), neg = false;
	while(('0' > c || c > '9') && c!='-' && c!=EOF) c = getchar();
	if(c == '-') neg = true, c = getchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = getchar();
	if(neg) x = -x;
	return x; // returns 0 if EOF
}

int main(){
	int n;
	while(!feof(stdin)){
		n=nextint();
		if((n&&!(n&(n-1)))){
			putchar('Y');
			putchar('e');
			putchar('s');
			putchar('\n');
		}else{
			
			putchar('N');
			putchar('o');
			putchar('\n');
		}
	}
	return 0;
}
