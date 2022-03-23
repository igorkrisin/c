/*(3+1)*2
3 1 + 2 * 

2*(3+1)

(1+2)*(5-1)

1 2 + 5 1 -

378
171
549

44
|
v
234 ->  12 ->  + -> 4 -> *
1    2 3 4 5

10/2
10-2=8
8-2=6
6-2=4
4-2=2
2-2=0
5

ДЗ
функция переворачивает список
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int count_mall = 0;

void* myMalloc(size_t size, int line, const char* func)
{
    

    printf("вызван malloc из строки %d из функции %s\n", line, func);
    count_mall++;
    printf("count_ malloc %d\n",count_mall);
    return malloc(size);

}

#define malloc(x) myMalloc(x, __LINE__, __FUNCTION__)

int count_free = 0 ;

void myFree(void* point, int line, const char* func)
{
    

    printf("вызван free из строки %d из функйии %s\n", line, func);
    count_free++;
    printf("count_free %d\n",count_free);
    free(point);
}

#define free(x) myFree(x, __LINE__, __FUNCTION__)




struct list

{
char* data;
struct list* next;
};

struct list* cons(struct list* prev, char* data){
    struct list* new = malloc(sizeof(struct list));
    (*new).data = data;
    new->next = prev;
    
    return new;


}

char* subtraction(char* num1, char* num2);
int comparison(char* num1, char* num2);
char* stripl_el(char* integ);
int cmp_str(char* string1, char*string2);
char* strip_zero(char* a);
char* add_minus(char* a);
int more(char* x, char* y);





char* copy_str(char* str) {
    int mal = strlen(str);
    char* arr = malloc((mal+1)*sizeof(char));
    for (int i = 0; i<mal; i++){
        arr[i] = str[i];
    }
    arr[mal] = '\0';
    return arr;
 }

char* appendr_char(char* a, char b){
    int mal = strlen(a);
    char* arr = malloc((mal+1+1)*sizeof(char));
    for(int i = 0;i<mal;i++){
        arr[i]=a[i];
    }
    
    arr[mal] = b;
    arr[mal+1] = '\0';
    //copy_str(arr);
    //copy_str(a);
    free(a);
    
    return arr;
}

char* summ;
char* appendl_char(char* a, char b);

char* addition(char* a, char* b){
    a = strip_zero(a);
    b = strip_zero(b);
    int perenos = 0;
    int integer; 
    
    while (strlen(a) != strlen(b))
    {
        if(strlen(a) > strlen(b)){
            b = appendl_char(b , '0');
        }
         else if(strlen(a) < strlen(b)) {
            a = appendl_char(a, '0');
        }
    }
    char* summ = malloc((strlen(a)+1)*sizeof(char));
    for (int i = strlen(a)-1; i >= 0; --i){
        integer = perenos + (a[i] - 48 + b[i] - 48);

        if (integer > 9){
            perenos = 1;
            summ[i] = (integer + 48) - 10; 
	}
        else {
            perenos = 0;
            summ[i] = integer +48;  
	    }
    }
    summ[strlen(a)] = '\0';
    if (perenos == 1) {
	    summ = appendl_char(summ, '1');
    }
    
    free(a);
    free(b);
    return summ;
}

char* add_full(char* integ1, char* integ2){
    if(integ1[0] == '-' && integ2[0] == '-'){
        integ1 = stripl_el(integ1);
        integ2 = stripl_el(integ2);
	    return appendl_char(addition(integ1, integ2), '-');
    }
    else if(integ1[0] == '-'){
        integ1 = stripl_el(integ1);
        if(more(integ1, integ2)){
            return appendl_char(subtraction(integ1, integ2), '-');
            }
        else{
            return subtraction(integ2, integ1);
        }
    }
    else if(integ2[0] == '-'){
        integ2 = stripl_el(integ2);
        if(more(integ1, integ2)){
            return subtraction(integ1, integ2);
        }
        else{
            return appendl_char(subtraction(integ2, integ1), '-');
        }
    }    
    return addition(integ1, integ2);
} 


char* appendl_char(char* a, char b){
    int mal = strlen(a);
    char* arr = malloc((mal+1+1)*sizeof(char));
    for(int i = 0;i<mal;i++){
        arr[i+1]=a[i];
    }
    arr[0] = b;
    arr[mal+1] = '\0';
    free(a);
    return arr;
}

/*     int string_to_int(char* a){
    int arr = 0;
    for (int i  = 0; i<strlen(a);i++){
        arr += (a[i]-48)*pow(10,(strlen(a)-i-1)); 
    }
    return arr;
}
 */
/*int comparison(char* num1, char* num2){
    int a;
    int b;
    int count = 0;
    if(strlen(num1) == strlen(num2)){      
        for(int i = 0; i < strlen(num1); ++i){
            a = num1[i] - 48;
            b = num2[i] - 48;
            printf("a0 %d\n", a);
            printf("b0 %d\n", b);
            if(a == b){
                count++;
                printf("count %d\n", count);
                printf("strlen %lu\n", strlen(num1));
            }
            
            else if(a > b){
                printf("a> %d\n", a);
                printf("b< %d\n", b);
                return 1;
            }  
            else if(a < b){
                printf("a< %d\n", a);
                printf("b> %d\n", b);
                return 0;
           }
            
        }
    }
    if(count == strlen(num1)){
        return 1;
    }
    else if(strlen(num1) > strlen(num2)){
        return 1;
    }
    
    return 0;
}*/

 
//8958
//  45




 
 
int comparison(char* num1, char* num2){
    int len_num1 = strlen(num1);
    int len_num2 = strlen(num2);
    int max_len;
    int len_zero1;
    int len_zero2;
    int a;
    int b;
    if(len_num1 > len_num2){
	max_len = len_num1;
	len_zero1 = 0;
	len_zero2 = len_num1 - len_num2;
    }
    else{
	max_len = len_num2;
	len_zero1 = len_num2 - len_num1;
	len_zero2 = 0;
    }      
        for(int i = 0; i < max_len; ++i){
            a = i < len_zero1?0:num1[i - len_zero1] - 48;
            b = i < len_zero2?0:num2[i - len_zero2] - 48;
            //условие?рез1: рез2
            if(a == b){
            
            }
            
            else if(a > b){
                return 1;
            }  
            else if(a < b){
                return -1;
           }
        }
    return 0;
}

int more(char* x, char* y){
	return comparison(x, y) == 1;
}
int less(char* x, char* y){
    return comparison(x, y) == -1;
}
int equal(char* x, char* y){
    return comparison(x, y) == 0;
}
int more_or_equal(char* x, char* y){
    int comp = comparison(x,y);
    return comp == 1 || comp == 0;
}
int less_or_equal(char* x, char* y){
    int comp = comparison(x, y);
    return comp == -1 || comp == 0;
}




/*int comparison_equal(char* num1, char* num2){
    int len_num1 = strlen(num1);
    int len_num2 = strlen(num2);
    int max_len;
    int len_zero1;
    int len_zero2;
    int a;
    int b;
    if(len_num1 > len_num2){
	max_len = len_num1;
	len_zero1 = 0;
	len_zero2 = len_num1 - len_num2;
    }
    else{
	max_len = len_num2;
	len_zero1 = len_num2 - len_num1;
	len_zero2 = 0;
    }      
        for(int i = 0; i < max_len; ++i){
            a = i < len_zero1?0:num1[i - len_zero1] - 48;
            b = i < len_zero2?0:num2[i - len_zero2] - 48;
            //условие?рез1: рез2
            if(a == b){
            }
            
            else if(a > b){
                return 1;
            }  
            else if(a < b){
                return 0;
           }
        }
        printf("str %lu\n", strlen(num1));
    return 1;
} */

char* strip_zero(char* a){
    char* buffer = copy_str("");
    int flag = 1;
    for(int i = 0; i < strlen(a) - 1; ++i){
        if(a[i] != '0'){
            
            flag = 0;
        }
        
        if(flag == 0){
    	    buffer = appendr_char(buffer, a[i]);
        }
        
   }
   buffer = appendr_char(buffer, a[strlen(a)-1]);
   free(a); //Из-за него возникает ошибка!!!
   return buffer;
}


char* strip_zero_1(char* a){
    int count = 0;
    int len = strlen(a);
    for(int i = 0; i < len; ++i){
        if(a[i] == '0'){
            count += 1;
	    }
        else{
            break;
	    }
    }
    if(count == strlen(a))
	return copy_str("0");
    char* buffer = malloc((len-count+1)*sizeof(char));
    for(int i = count; i < len; ++i){
	    buffer[i - count] = a[i];
    }
    
    
    buffer[len - count] = '\0';
    free(a);
    return buffer;
}

char* mul_by_digit(char* arr, char simb){
    int len = strlen(arr);
    int integer;
    int remainder = 0;
    char* summ = malloc((len+1) * sizeof(char));
    for(int i = len-1; i >= 0; --i){
        integer = (arr[i] - 48) * (simb - 48) + remainder;
        if(integer > 9){
    	    
            summ[i] = integer%10 + 48;
         
            remainder = integer/10;
        }
        else{
            summ[i] = integer + 48;
            remainder = 0;
        }
        
    }
    summ[len]='\0';
    
    if(remainder != 0){
	summ = appendl_char(summ, remainder + 48);
    }
    free(arr);
    return summ;
}

char* add_zeros_right(char* integ, int summ_zero){
    int len = strlen(integ) + summ_zero;
    char* summ = malloc((len + 1) * sizeof(char));
    for( int i = 0; i < strlen(integ); ++i){
	summ[i] = integ[i];
    }
    for(int i = strlen(integ); i < len; ++i){
	summ[i] = '0';
    } 
    
    summ[len] ='\0';
    free(integ);
    return summ;
}


/* 467
  56
 xxx
yyy0*/

//int add(int x, int y){ return x + y;}

char* mult(char* integ1, char* integ2){
    integ1 = strip_zero(integ1);
    //integ1 = copy_str(integ1);
    integ2 = strip_zero(integ2);
    //printf(" mult %s\n",  integ1);
    char* summ = copy_str("0");
    int count;
    for(int i = 0; i < strlen(integ2); ++i){
        
	    summ = addition(summ, add_zeros_right(mul_by_digit(copy_str(integ1), integ2[i]),strlen(integ2)-i-1));
    }
    free(integ1);
    free(integ2);
    return summ;
}

int is_minus_zero(char* a){
    if(strlen(a) < 2){
	    return 0;
    }
    if(a[0] != '-')
	    return 0;
    else{
	for(int i = 1; i < strlen(a); i++){
	    if(a[i] != '0')
	    return 0;
        
	}
    }
    return 1;
}


char* strip_minus(char* a){
    if(is_minus_zero(a)){
	return copy_str("0");
    }
    else{
	return a;   
    }
}

char* add_minus(char* a){
    if(more(a,"0")){
	return a;
    }
    else{
	return appendl_char(a, '-');
    }
}


//-42
//mult("42","3")
char* stripl_el(char* integ);

char* mult_full(char* integ1, char* integ2){
    

    if(integ1[0] == '-' && integ2[0] == '-'){
        //printf("multint1 %s\n", mult(integ1, integ2));
        integ1 = stripl_el(integ1);
        integ2 = stripl_el(integ2);
	    return mult(integ1, integ2);
    }
    else if(integ1[0] == '-'){
        integ1 = stripl_el(integ1);
        //printf("multint2 %s\n", mult(integ1, integ2));
        return strip_minus(appendl_char(mult(integ1, integ2), '-'));
    }
    else if(integ2[0] == '-'){
        integ2 = stripl_el(integ2);
        //printf("multint3 %s\n", mult(integ1, integ2));
        return strip_minus(appendl_char(mult(integ1, integ2),'-'));
    }
        //printf("multint4 %s\n", mult(integ1, integ2));
        return mult(integ1, integ2);
} 

char* stripl_el(char* integ){
    int len = strlen(integ);
    char* strip_int = malloc(len*sizeof(char));
    for(int i = 1; i < len; i++){
	strip_int[i-1] = integ[i];
    }
    strip_int[len]= '\0';
    free(integ);
    return strip_int;
}



/*


2 3 + 5 *

25
mul_by_digit("1234",'6')
add_zeros_right("1234",3) -> "1234000"
mult("1234","56")

 1234
   56
 ----
----0

  
  
 "34 67 + 3 *"
34
67
+
3
*/


struct list* reverse_list(struct list* list);

struct list* split(char* a){
    char* buffer = copy_str("");
    struct list* new = NULL;
    for(int i = 0; i < strlen(a); ++i){
	if(a[i] != ' '){
	    buffer = appendr_char(buffer, a[i]);
	}
	else{
	    if(strlen(buffer) != 0){
		new = cons(new, buffer);
		//printf("%s\n", buffer);
		buffer = copy_str("");
	    }
	}
    }
    if(strlen(buffer) != 0){
	new = cons(new, buffer);
	//printf("%s", buffer);
    }
    free(a);
    return reverse_list(new);
}

char* subtraction_base(char* num1, char* num2){
    int integer;
    int zaim = 0;
        while (strlen(num1) != strlen(num2)){
            
            if(strlen(num1) < strlen(num2)){
                num1 = appendl_char(num1, '0');
            }
            else if(strlen(num2) < strlen(num1)){
                num2 = appendl_char(num2, '0');
            }
        }
        char* summ = malloc((strlen(num1)+1)*sizeof(char));
        //printf("compar %d\n",comparison(num1,num2));
        
            for (int i = strlen(num1)-1; i >= 0; --i){       
                integer = (num1[i] - 48) - (num2[i] - 48) - zaim;
                //printf("compar %d\n", integer);
                if(integer < 0){
                    zaim = 1;
                    summ[i] = (integer + 48) + 10;
                }
                else{
                    zaim = 0;
                    summ[i] = integer + 48;
                }        
            }
            summ[strlen(num1)] = '\0';
            summ = strip_zero_1(summ);
        
        
        free(num1);
        free(num2);
        return summ;
}


char* subtraction(char* num1, char* num2){
        //printf("num1 %s\n num2 %s\n", num1, num2);
        if(more_or_equal(num1,num2)){
            return subtraction_base(num1, num2);       
        }
        else{
    	    return appendl_char(subtraction_base(num2, num1), '-');
            
        }
}
        
   //printf("%lu\n", strlen(summ));
    //null_to_void(summ);
    //printf("%c\n", summ[0]);

char* subs_full(char* integ1, char* integ2){
    if(integ1[0] == '-' && integ2[0] == '-'){
        integ1 = stripl_el(integ1);
        integ2 = stripl_el(integ2);
        //printf("%s\n", integ1);
        //printf("%s\n", integ1);
        
        return subtraction(integ2,integ1);
        }
    else if(integ1[0] == '-'){
        integ1 = stripl_el(integ1);
            return appendl_char(addition(integ1, integ2), '-');
    }
    else if(integ2[0] == '-'){
        integ2 = stripl_el(integ2);
        return addition(integ1, integ2);
    }
    else{
        return subtraction(integ1, integ2);
    }
}

void free_struct(struct list* a);

void print_list(struct list* list){
    struct list* del = list;
    while(list != NULL){
	printf("%s ", list->data);
	list = list->next;
    }
    free_struct(del);
}


struct list* reverse_list(struct list* list){
    struct list* reverse_list = NULL;
    for(struct list* node = list, *next_node; node != NULL; node = next_node){
        
        next_node = node->next;
        node->next = reverse_list;
        reverse_list = node;
        

    }
    
    return reverse_list;

}

char* division(char* arr_1, char* arr_2){
    char* count = copy_str("0");//такие строчки скопировать!!!!
    //printf("arr11 %s\n\t", arr_1);
    //printf("arr22 %s\n\t", arr_2);
    while (more_or_equal(arr_1, arr_2))           
    {
        //arr_2 = copy_str(arr_2);
        arr_1 = subtraction(arr_1, copy_str(arr_2));
        
        //printf("subt %s\n\t", subtraction(arr_1, arr_2));
        //printf("arr1 %s\n\t", arr_1);
        //printf("comparis %d\n", comparison(arr_1, arr_2));
        
        //printf("arr2 %s\n", arr_2);
        count = addition(count, copy_str("1"));
        //printf("count %s\n", count);
        
    }
   
    return count;
}
char* div_full(char* integ1, char* integ2){
    if(integ1[0] == '-' && integ2[0] == '-'){
        integ1 = stripl_el(integ1);
        integ2 = stripl_el(integ2);
        return appendl_char(division(integ1, integ2), '-');
        
    }
    else if(integ1[0] == '-'){
        integ1 = stripl_el(integ1);
        return appendl_char(division(integ1, integ2), '-');
    }
    else if(integ2[0] == '-'){
        integ2 = stripl_el(integ2);
        return appendl_char(division(integ1, integ2), '-');
    }
        
    return division(integ1, integ2);
} 

int list_length(struct list* exp){
    
    int count = 0;
    while(exp != NULL){
	exp = exp->next;
	count++;
	}
	return count;
    }

int verify_num(char* arr);

void free_struct(struct list* exp){
    while(exp != NULL) {
	free(exp->data);
	struct list* del = exp;
	exp = exp->next;
	free(del);
	
	
    }
} 

struct list* rest(struct list* exp){
    free(exp->data);
    struct list* del = exp->next;
    free(exp);
    return del;

}


struct list* calc(struct list* exp){
    struct list* stack = NULL;
    while(exp != NULL){
	if(verify_num(exp->data)){
	    printf("numb\n");
	    stack = cons(stack, exp->data);
    	    struct list* del = exp;
	    exp = exp->next;
	    free(del);
        
	}
	else if(cmp_str(exp->data, "*")){
	    printf("multiplication\n");
	    if(list_length(stack) < 2){
            printf("произошла ошибка, проверьте правильность ввода"); 
            exit(1);
	    }
	    
	    struct list* first = stack;
	    struct list* second = stack->next;
	    stack = cons(second->next, mult_full(stack->data, second->data));
	    free(first);
	    free(second);
	    exp = rest(exp);
	    
	}
	else if(cmp_str(exp->data, "-")){
	    printf("subtraction\n");
        if(list_length(stack) < 2){
            printf("произошла ошибка, проверьте правильность ввода"); 
            exit(1);
	    }
	    
	    //12 5 -
	    //stack: 12 5
	    //          ^
	    //          first
	    
	    
        struct list* first = stack;
	    struct list* second = stack->next;
	    stack = cons(stack->next->next, subs_full(stack->next->data, stack->data));
    	    free(first);
	    free(second);
	    exp = rest(exp);
	}
	else if(cmp_str(exp->data, "+")){
	    printf("addition\n");
        if(list_length(stack) < 2){
            printf("произошла ошибка, проверьте правильность ввода"); 
            exit(1);
        }
        struct list* first = stack;
	    struct list* second = stack->next;
	    stack = cons(stack->next->next, add_full(stack->data, stack->next->data));
    	    free(first);
	    free(second);
	    exp = rest(exp);
	}
	else if(cmp_str(exp->data, "/")){
    	printf("division\n");
        if(list_length(stack) < 2){
            printf("произошла ошибка, проверьте правильность ввода"); 
            exit(1);
        }
        struct list* first = stack;
	    struct list* second = stack->next;
    	stack = cons(stack->next->next, div_full(stack->next->data, stack->data));
        free(first);
	    free(second);
    	    exp = rest(exp);
    	}
    else{
    	printf("неверный ввод"); 
    	exit(1);
    	    
    }
    
    
    }
    stack = reverse_list(stack);
    return stack;
}

int cmp_str(char* string1, char* string2){
    int len = strlen(string1);
    if(len != strlen(string2)){
	return 0;
    }
    for(int i = 0; i < len; i++){
	if(string1[i] != string2[i]){
	    return 0;
	}
    }
    return 1;
} 

/* 
7/2
7-2=5
5-2=3
3-2=1
1
3
 */
 
 
// ad-hoc
int verify_num(char* arr){
    int len = strlen(arr);
    
    if(arr[0] == '-'){
        if(strlen(arr) < 2){
            return 0;
        }
        //stripl_el(arr);
        for(int i = 1; i < len; ++i){

            //printf("%d\n", arr[i]);
            if(arr[i] < 48 || arr[i] > 57){
	            return 0;
            }
	    } 
    }
    else{ 
        for(int i = 0; i < len; ++i){ 
            //printf("%d\n", arr[i]);             
            if(arr[i] < 48 || arr[i] > 57){
                
                return 0;
             
    	    }
	}
    }
    return 1;
    
}


int automate_calc(char* arr){
    int len = strlen(arr);
    int state = 0;
        for(int i = 0; i < len; ++i){
            printf("%c\n", arr[i]);
            if(arr[i] < 48 || arr[i] >= 0 && state == 0){
                state = 0;
                printf("%d\n", state);
            }
            else if(arr[i] == ' ' || arr[i] == '-' || arr[i] == '+' || arr[i] == '*' || arr[i] == '/' && state == 0){
                state = 1;
                printf("%d\n", state);
            }
            else if(arr[i] == ' ' || arr[i] == '-' || arr[i] == '+' || arr[i] == '*' || arr[i] == '/' && state == 0){
                state = 1;
                printf("%d\n", state);
            }
            if(arr[i] < 9 || arr[i] >= 0  && state == 1){
                state = 2;
                printf("%d\n", state);

            }
            else if(arr[i] == ' ' || arr[i] == '-' || arr[i] == '+' || arr[i] == '*' || arr[i] == '/' && state == 2){
                state = 1;
                printf("%d\n", state);
            }
            else if(arr[i] == '\0' && state == 1){
                return 1;
                printf("%d\n", state);
            }

        
    }
    return 0;

}

char* stripr_el(char* str){
    int len = strlen(str);
    char* new_str = malloc(len*sizeof(char));
    for(int i = 0; i < len-1; i++){
	new_str[i] = str[i];
    }
    
    new_str[len-1] = '\0';
    return new_str;
    
}


int main(){
    //printf("%s\n", subs_full("82","82"));
    //printf("%s\n",add_full("-10", "10"));
    //print_list(reverse_list(split("34 56 + 43 *")));
    //printf("%s\n", addition("9999883", "997892"));
    //printf("%d\n", 2232/6);
    //printf("%d\n", comparison(copy_str("000946"), copy_str("000946")));
    //printf("%d\n", comparison_equal(copy_str("0946"), copy_str("000946")));
    //printf("%s\n", subtraction(copy_str("22"), copy_str("66")));
    //split("34 67 *  3 + ");
    //printf("%s\n", strip_zero("00000909"));
    //printf("%s\n", strip_zero_1(copy_str("0000050555")));
    //printf("%s\n", mul_by_digit("2334",'8'));
    //printf("%s\n", add_zeros_right("1234", 4));
    //printf("%s", mult("23333", "695"));
    //print_list(cons(cons(cons(cons(NULL, "hello"), "world"),"hey"),"hay"));
    //div_by_digit("156", '9');
    //printf("%s\n",division(copy_str("2232"), copy_str("6")));
    //print_list(calc(split(copy_str("6 8 * 88 - 40 -"))));
    //printf("%d\n",cmp_str("2224","2222"));
    //printf("%s\n", stripl_el("-222"));
    //printf("%s\n", mult_full("0", "10"));
    //printf("%d\n", verify_num(copy_str("-")));
    //printf("%s\n",div_full("-22","3"));
    //printf("%s\n", stripr_el("12345")); 
    //printf("%s\n", subs_full(copy_str("567"),copy_str("562")));
    char str[10000];
    char* str_new;
    printf("введите вырaжение: ");
    fgets(str, 10000, stdin);
    str_new = stripr_el(str);
    print_list(calc(split(str_new))); 
    //printf("%s\n", strip_minus("-8"));
    //printf("%d\n", automate_calc("22 33 - 44 + 22 * 15 -"));
   //printf("addminus %s\n", add_minus(copy_str("-6")));
}



