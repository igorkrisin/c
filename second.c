#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int power(int m, int n);


void convert(int lower, int upper, int step){
    float fahr, celsius;
    
    printf("convert celsius->fahrengeit\n\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (celsius * 1.8) + 32.0;
        printf("%3.0f %6.1f\n", celsius,fahr);
        celsius +=step; 
    }  
}
int main(){
    convert(0, 200, 20);
   /*  float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    printf("convert celsius->fahrengeit\n\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (celsius * 1.8) + 32.0;
        printf("%3.0f %6.1f\n", celsius,fahr);
        celsius +=step;     */
/* int i;
for ( i = 0; i < 10; i++)
{
    printf("%d %d %d\n", i, power(2, i), power(-3, i));

}
return 0; 
}*/


/* int power(int base, int n)
{
    int i, p;
    p = 1;
    for ( i = 1; i <= n; ++i)
    {
        p = p*base;
        
    }
    return p;
} */

/* float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    printf("convert celsius->fahrengeit\n\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (celsius * 1.8) + 32.0;
        printf("%3.0f %6.1f\n", celsius,fahr);
        celsius +=step;  */

}