#include <stdio.h>
int main(){
    char c = 0;
    while(c!='\n'){  //回车键结束循环
        c=getchar();
        if(c=='4' || c=='5'){  //按下的是数字键4或5
            continue;  //跳过当次循环，进入下次循环
        }
        putchar(c);
		fflush(stdout);
    }
    return 0;
}