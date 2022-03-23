#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
int len(char* a){
    
    int i;
    for (i = 0;a[i]!='\0';++i);
    return i;

}

char* concat(char* a, char* b){
    char* arr = malloc((len(a)+len(b))*sizeof(char)+1);
    for (int i = 0;i < len(a);++i){
	arr[i] = a[i];
    }
    for (int i = 0;i < len(b);++i){
	arr[i+len(a)] = b[i];
    }
    arr[len(a)+len(b)] = '\0';
    
    return arr;
}

char* dup_string(char* a, int b){
    int mal = len(a)*b;
    char* arr = malloc((mal+1)*sizeof(char));

    for(int y = 0; y < b; ++y){
        for(int i = 0; i<len(a); ++i){
            arr[i+len(a)*y]=a[i];
            printf("%d\n", i);
        }
        
    }
    arr[mal] = '\0';
    return arr;
    
}


char* reverse_string(char* r){
    int mal = len(r);
    char* arr = malloc((mal+1)*sizeof(char));
    for (int i = 0; i<mal; i++){
        arr[mal-i-1]=r[i];
/*         printf("%d\n\t", len(r)-i);
        printf("%d\n", i);
*/
    }
    arr[mal] = '\0';
    return arr;
}


char* appendr_char(char* a, char b){
    int mal = len(a);
    char* arr = malloc((mal+1+1)*sizeof(char));
    for(int i = 0;i<mal;i++){
        arr[i]=a[i];
    }
    
    free(a);
    //printf("%s\n", arr);
    
    arr[mal] = b;
    arr[mal+1] = '\0';
    return arr;
}


char* appendl_char(char* a, char b){
    int mal = len(a);
    char* arr = malloc((mal+1+1)*sizeof(char));
    for(int i = 0;i<mal;i++){
    /*    printf("%d\n", i);*/
        arr[i+1]=a[i];
    }
    
    /*printf("%s\n", arr);*/
    free(a);
    arr[0] = b;
    arr[mal+1] = '\0';
    return arr;
}


int is_substring(char* substr, char* str){
    int count = 0;
    for (int i = 0;i<len(substr);i++){
        for(int y = 0; y<len(str); y++){
            if (substr[i] == str[y]){
                count++;
                printf("%d\n", count); 

            }
        }
       
    }
    if(count==len(substr)){
        return 1;
    }
    else {
        return 0;
    }
}


 int is_beggining(char* begstr, char* str){
    for(int i=0;i<len(begstr);i++){
        printf("%d\n", begstr[i]);
        printf("%d\n", str[i]);
        if(begstr[i]!=str[i]){
            return 0;
        }
    
    }
    return 1;
}
 
int is_palindrome(char* str){
    int count = 0;
    for (int i=0; i<len(str);i++){
        if(str[i]!=str[len(str)-1-i]){
            count =1;
        }
    }
    if(count>=1){
        return 0;
    }
    else{
        return 1;
    }
}
/* char* is_palindrome(char* pal){
    int mal = len(pal);
    char* arr = malloc((mal+1)*sizeof(char));   
}
 */
 
char* copy_str(char* str) {
    int mal = len(str);
    char* arr = malloc((mal+1)*sizeof(char));
    for (int i = 0; i<mal; i++){
        arr[i] = str[i];
    }
    arr[mal] = '\0';
    return arr;
 }
 
char* int_to_string(int integ){
    char* n = copy_str("");
    while (integ!=0){   
        n  = appendl_char(n,integ%10+48);
        integ = integ/10;       
}
    return n;
}

char* upcase(char* str){
    //str = copy_str(str);
    int mal = len(str);
    char* arr = malloc((mal+1)*sizeof(char));
    for (int i =0; i<mal;i++){
        /* printf("%c\n", str[i]-32); */
        
        if(str[i]>=97&&str[i]<123){
           arr[i] =  str[i]-32;
           printf("%c\n", str[i]);
        }
        else {
            arr[i] = str[i];
        }
    }
    arr[mal] = '\0';
    //free(str);
    return arr;
}

char* swap_case(char* str){
    int mal = len(str);
    char* arr = malloc((mal+1)*sizeof(char));
    for (int i =0; i<mal;i++){
        /* printf("%c\n", str[i]-32); */
        
        if(str[i]>=97&&str[i]<123){
           arr[i] =  str[i]-32;
           printf("%c\n", str[i]);
        }
        else if (str[i]>=65&&str[i]<91) {
            arr[i] = str[i]+32;
        }
        else {
            arr[i] = str[i];
        }
    }

    arr[mal] = '\0';
    free(str);
    return arr;
}
char* interwine(char* a, char* b){
    int mal = len(a)+len(b);
    char* arr = malloc((mal+1)*sizeof(char));
    for (int i = 0; i<len(a); i++){
            arr[i+i]=a[i];
            printf("%d\n", i);
            arr[i+i+1]=b[i];
            }
    
    
    arr[mal]='\0';
    free(b);
    free(a);
    return arr;

}
//1->1 2->3 3->5 4->7
//1->2,2->4,3->6 4->8
int string_to_int(char* a){
   int arr = 0;
    for (int i  = 0; i<len(a);i++){
        arr += (a[i]-48)*pow(10,(len(a)-i-1)); 
    }
    return arr;
}
//'267' -> 2*10^2+6*10^1+7*10^0


int main(){
//printf("%s\n", interwine(copy_str("abrt"),copy_str("1234")));
//printf("%d\n", string_to_int("546"));
  /* char* s = "abcdefg";
   char[5] c= 'dda';
   sizeof(char)
   */
/*printf("%d\n", len("dmdmdmdmd kdsdnfjn"));*/
/* printf("%s\n", concat("dsfdfsddfs","dsfsdfsdfsd"));*/
 //printf("%s\n", dup_string("abcd",5));//
/* printf("%s\n", reverse_string("abcdefg"));
 */
//printf("%s\n", appendr_char("abcdgtfgfg", 'e'));
//printf("%s\n", appendl_char("abcfgdgdfgfdgjjjj",'d')); 
/*  printf("%d\n", is_substring("abcde","qwsuioabdcllkj"));*/
/*printf("%d\n", is_beggining("abcde","abcefdfsd43abdcellkj"));*/
//printf("%s\n", int_to_string(459));
/* printf("%d\n", is_palindrome("abcka")); */
/* printf("%s\n", copy_str("abcd")); */
//printf("%s\n", upcase("abcddsdeHJfrtAD12")); 
//printf("%s\n", swap_case(copy_str("abcddsdeHJfrtAD12")));
/*concat("abc","de") -> "abcde"*/
printf("%d\n", string_to_int("123"));

char str;
char* arr = malloc(57*sizeof(char));
int i = 0;
for ( str = 'a'; str<='z'; str++){
    arr[i]=str;
    if(i%2!=0){
        arr[i]=str-32;
    }
    //printf("%d\n", i);
    i++;
    //printf("%c\n", str);
}

arr[57]='\0';
//printf("%s\n", arr);
}

