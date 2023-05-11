#include <stdio.h>
 
int main (){

int count=0;
int state=0 ;
int next_state;
int enable=0;
while(!enable){ //a.k.a.for(int i=0;i<10,enable==0;i++)
	if(count<6){
		next_state = 1 ;
	}
	else if(count==6) next_state = 2;
	else next_state =3 ;
	switch(state){
		case 0:
			printf("state =%d\n",state);
			printf("next_state =%d\n",next_state);
			printf("count=%d\n",count);
			count++;
			state = next_state ;

		case 1:
			printf("state =%d\n",state);
			printf("next_state =%d\n",next_state);
			printf("miaomiaomiao\n");
			count++;
			state = next_state ;
			continue;

		case 2:
			printf("state =%d\n",state);
			printf("next_state =%d\n",next_state);
			state = next_state ;
			count++;
			continue;
		case 3:
			printf("state =%d\n",state);
			printf("next_state =%d\n",next_state);
			enable=1;
		  break;//will not process the statement behind "break".and jump out switth
		//to process "hello\n"
		default:
			printf("bye");
		  break;
	} //switch end
	printf("hello\n");
}//for end
	printf("\n");
	printf("final count=%d",count);
		return 0;
}
