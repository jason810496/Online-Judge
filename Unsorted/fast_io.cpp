#include<iostream>
#include<fstream>
int arr[10000000];
inline int Fast_IO2(int &num){
    int temp=0,ch = getchar() ;
    bool pos = (ch=='-' ? 0:1);
    for(;'0'<=ch&&ch<='9';ch = getchar()){
        temp= temp*10 + ch - '0';
    }
    num= (pos ? temp:-temp);
}


inline char Fast_getchar(){
    int cnt=1<<21,len=1<<16;
    char buffer[len],*ptr=buffer ,*end=buffer;
    if(ptr==end){
        if(cnt<len) return EOF;
        cnt = fread(buffer,1,len,stdin);
        end = buffer + cnt;
        ptr = buffer;
    }
    return *(ptr++);
}
/*
通过 fread 或者 mmap 可以实现更快的读入。其本质为一次性将输入文件
读入一个巨大的缓存区，如此比逐个字符读入要快的多 
(getchar,putchar）。因为硬盘的多次读写速度是要慢于内存的，
所以先一次性读到缓存区里再从缓存区读入要快的多。
*/

template<class T>
bool Fast_read(T &num){
    int temp=0,ch = getchar() ;
    while(('0' > ch || ch > '9') && ch!='-' && ch!=EOF) ch = getchar();
    if(ch==EOF) return false;
    bool pos = (ch=='-' ? 0:1);
    for(;'0'<=ch&&ch<='9';ch = getchar()){
        temp= temp*10 + ch - '0';
    }
    num= (pos ? temp:-temp);
    return true;
}
int main(){
    std::cin.tie(0);std::ios_base::sync_with_stdio(0);
    int Start_time = clock(),N=10000000,x;
    freopen("input01.in","r",stdin);
    for(int i=0;i<N;i++){
		//Fast_read(arr[i]); 0.152 sec
        //Fast_IO2(arr[i]); 0.148
        //std::cin>>arr[i]; 0.70
        std::cin>>arr[i];// with IO

    }
    printf("%.3f sec",double(clock()-Start_time)/CLOCKS_PER_SEC);
    return 0;
}
