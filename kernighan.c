#include <stdio.h>
#define IN 1
#define OUT 0

int main() {

    ////// превращение нескольких пробелов в 1
   /*  int ch, sp = 0;
    while ((ch = getchar()) != EOF) {
        if(ch != ' ')
            sp = 0;
        if(ch == ' ')
            ++sp;
        if(sp <= 1)
            putchar(ch);
    } */

    ////// замена символоы на строковые значения
    /* int c;
     while((c = getchar()) != EOF) {
        if(c == '\t') {
            
            printf("\\t");
        }
        else if(c == '\b') {
            printf("\\b");
        }
        else if(c == '\\') {
             printf("\\");
             printf("\\");
        }
        else{
            putchar(c);
        }
    } */

    /* int c, w, nl, nc, state;
    c = w = nl = nc = 0;
    state = OUT;

    while((c = getchar()) != EOF){
        nc++;
        if(c == '\n') {
            ++nl;
        }
        if(c == ' '||c == '\t'|| c == '\n') {
            state = OUT;
        }
        else if(state == OUT) {
            state = IN;
            w++;
        }
    }

    printf("nc: %d\n nl: %d\n w: %d\n", nc, nl, w); */

    int c, state;
    c = 0;

    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\t'){
            state = OUT;
            putchar('\n');
        }
        else {
            state = IN;
            putchar(c);
        }
    }
   printf("%c",c);
}

