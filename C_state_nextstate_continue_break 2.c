#include <stdio.h>
 
int main (){

int count=0;
int state=0 ;
int next_state;
for(int i=0;i<9;i++){
	if(i<6){
		next_state = 1 ;
	}
	else if(i==6) next_state = 2;
	else next_state =3 ;
switch (state){
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
		printf("i=%d\n",i);
		state = next_state ;
		count++;
		continue;
    case 3:
		printf("state =%d\n",state);
		printf("next_state =%d\n",next_state);
		printf("i=%d\n",i);
      break;

    default:
		printf("bye");
      break;
}
	printf("hello\n");
}
	printf("\n");
	printf("final count=%d",count);
		return 0;
}
