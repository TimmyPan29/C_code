/*set20.c*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MAXLINE 400
 
/*ran1.c from Numerical Recipes - This outputs random numbers to gasdev.c*/
#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)
float ran1(long*);
// void normal(float*,float*,float);
int main(){
    float *result_n1,*result_n2 ;
    float sd1_pow2,sd1;
    int i,j,k ;
    int count=0 ;
    float s;
    float x1,x2;
    long a = -2023;
    long *idum;
    idum = &a;
     
    
    result_n1 = malloc(sizeof(float));
    result_n2 = malloc(sizeof(float));
    sd1_pow2 = pow(pow(10,0.1),-1);
    sd1 = sqrt(sd1_pow2);
    for (i=0;i<10000;i++){
        do{
          x1=ran1(idum);
          x2=ran1(idum);
          x1 = 2*x1-1;
          x2 = 2*x2-1;
          s = pow(x1,2)+pow(x2,2);
      } while(s>=1.0);
    *result_n1 = sd1*x1*sqrt(-2*log(s)/s);
    *result_n2 = sd1*x2*sqrt(-2*log(s)/s);
    if(*result_n1>3){
        count=count+1;
    }
    // printf("result_n1= %.6f\n",*result_n1);
    // printf("result_n2= %.6f\n",*result_n2);
    }
    printf("count=%d\n",count);
}
float ran1(long *idum) //return a float value not *float
{
    int j;
    long k;
    static long iy=0; //the static declaration will remain the value when the process ran out of the function.
    static long iv[NTAB];
    float temp;
 
    if (*idum <= 0 || !iy) {
        if (-(*idum) < 1) *idum=1;
        else *idum = -(*idum);
        for (j=NTAB+7;j>=0;j--) {
            k=(*idum)/IQ;
            *idum=IA*(*idum-k*IQ)-IR*k;
            if (*idum < 0) *idum += IM;
            if (j < NTAB) iv[j] = *idum;
        }
        iy=iv[0];
    }
    k=(*idum)/IQ;
    *idum=IA*(*idum-k*IQ)-IR*k;
    if (*idum < 0) *idum += IM;
    j=iy/NDIV;
    iy=iv[j];
    iv[j] = *idum;
    if ((temp=AM*iy) > RNMX) return RNMX;
    else return temp;
}
// void normal(float *n1, float *n2,float sd1){
    // float s;
    // float x1,x2;
    // long a = -2023;
    // long *idum;
    // idum = &a;
      // do{
          // x1=ran1(idum);
          // x2=ran1(idum);
          // x1 = 2*x1-1;
          // x2 = 2*x2-1;
          // s = pow(x1,2)+pow(x2,2);
      // } while(s>=1.0);
      // *n1 = sd1*x1*sqrt(-2*log(s)/s);
      // *n2 = sd1*x2*sqrt(-2*log(s)/s);
// }