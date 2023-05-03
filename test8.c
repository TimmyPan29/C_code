#include<stdio.h>
#include<stdlib.h>
void length(int intArray[]);

int main(void) {
	int g[1][10];
	int k;
	k=length(g);
	printf("length g= %d",k);
	int i;
    char ch[100];
	fgets(ch, sizeof(ch), stdin); //input
	puts(ch); //output
	fflush(stdout);
	for(i=0; i<100; i++){
		if(ch[i]=='\n'){
        ch[i]='\0'; //´«¦¨¦r¦êµ²§ô¼Ð»x²Å
        break;
		}
	}
	puts(ch); //output
    return 0;
}
void length(int intArray[])
{
   length=sizeof(intArray) / sizeof(intArray[0]) ;
}