#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* #define MAXLINE 1000;
#define IN 1
#define OUT 0 */

/* char* append_char(char* word, char simbol){
    int mal = strlen(word);
    char* arr = malloc((mal+strlen(word)+1)*sizeof(char));
    char* arr2 = [simbol];
  
    for (int i = 0;i<mal;i++){
        arr[i]=word[i];
    }
    for (int i = 0;i<mal;i++){
         arr[i+mal] = arr2[i];
    }
     arr[mal+len(arr2)] = '\0';
  return arr;
} */



//int getline(char line[], int maxline);
//void copy(char to[], char from[]);

/* int count_string(char* c){
    int c, nl;
    nl = 0;
    
    
    while ((c = getchar()) !=EOF)
        if (c =='\n')
            ++nl;
    printf("%d\n", nl);
} */



int main(){



    


    
    
    
    
return 0;

/* int c, nl;
    nl = 0;
    c ;
    while ((c = getchar()) !=EOF)
        if (c =='\n')
            ++nl;
    printf("%d\n", nl); */

 /* int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if(c == '\n')
            ++nl;
        
        if(c == " " || c =='\n' || c =='\t')
            state = OUT;
        
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
 */



    /* int len; //длина текущей строки
    int max; // максимальная текущая длина
    char line[MAXLINE]; //текущая введеная строка
    char longest[MAXLINE];// самая длинная строка из введенных

    max = 0;
    while((len = getline(line, MAXLINE)) > 0){
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max>0){ //была непустая строка
        printf("%s", longest)
        return 0;
        }
    }

    int getline(char s[], int lim){ //считывает строку в с, возвращвет ее длину
        int c, i;
        for (i = 0; i<lim -1 && (c = getchar()) != EOF && c!='\n'; i++)
            s[i] = c;
            ++i;
    }
    s[i] = '\0';
    return i;

    void copy(char to[], char from[]){
        int i;
        i = 0;
        while((to[i]) != from[i] != '\0'){
            ++i;
        }
    } */

 //printf("%s\n", append_char("abc",'d'));

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
        celsius +=step; */

    /* int fahr;
    for (fahr = 300; fahr>= 0; fahr = fahr-20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
 */
    /* int result;
    result = (getchar() != EOF);

    if(result == 0)
        printf("Равно 0\n");
    if(result == 1)
        printf("Равно 1\n");
    printf("EOF\n");
     */
    
    
     /* int c = 17;
    printf("%3d\n", c); */

    /* char c[25] = "room";
    printf("%3c%3c%3c%3c\n",c[0],c[1],c[2],c[3]);
 */

/* 
long nc;

nc = 0;
while (getchar() != EOF)
    ++nc;
printf("%ld\n", nc); */

/* long nc;
nc = 0;
while (getchar() != EOF)
    nc++;
printf("%ld\n", nc);
 */

/* double nc;

for (nc = 0; getchar() != EOF; ++nc)
    ;
printf("%.f\n", nc);
 */

/* char c [5]= "*"; */
   /*  int ns = 0;
    int i;
    int y;
    for(i=0; i<=5;++i) {
        for(y = 0;y<=ns + i;++y)
            printf("%s","*");

        printf("\n");
        }
    return 0; */


    
    
    
   /*  int c;
  
    while ((c = getchar()) !=EOF)
    {
        if (c == ' ')
            ;
        else
            c = ' ';
    }
    
    printf("\n%d", c);
 */



}

