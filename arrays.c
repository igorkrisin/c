#include <stdio.h>

void arr_print(int* arr, int size){
    for (int i = 0; i < size; i++){
	printf("%d ", arr[i]);
    }
}

int is_sorted(int* arr, int size){
    for (int i = 0; i< size-1; i ++){
	if (*(i+arr)>arr[i+1]){
	    return 0;
	}
    
    }
    return 1;

}


void bubble_sort(int* arr, int size){
    int flag = 1;
	//for(int y = 0; y< size-1; y++)
	do{
		flag=0;
		for (int i = 0; i < size-1; i++) {
			printf("%d\n\t\t", i);
			if (arr[i+1]<arr[i]||flag == 1){
				int n = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = n;
				flag =1;
			}
		}
	}
	while (flag == 1);	
}

void swap(int* a,int* b){
    //int f = *a;
    
    int c = *a;
    *a = *b;
    *b = c;
    

}


#define IN 1
#define OUT 0

void count_simb(){
    int c, nl, nw, nc, state;
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
}

/* void count_num(){
    int c, i, nwhite, nother;
    int ndigit[10];
    nwhite = nother = 0;
    for(i = 0; i < 10; ++i){
        ndigit[i] = 0;
    }
    while ((c = getchar()) != EOF)
    {
        if(c >= '0' && c <= '9')

    }
    
    
} */


int main(){
//int arr[10]  = {23,13,45,51,66,6,78,84,85,9};
//bubble_sort(arr, 10);
//arr_print(arr, 10);
//printf("%d\n",arr[1]));  // *(arr+1)
//  [1]arr   *(1+arr)
//   arr[0]  *(arr+0)  
count_simb();
for (int i = 0; i<10; i++){
//    printf("%d  ", arr[i]);
}

//printf("%d ", is_sorted(arr,10));
  /* int y=42;
   int *x=&y;
   printf("%d\n",*x);
   *x=666;
   printf("%d\n",y);
   printf("%p\n",x);*/
   int a=13;
   int b=42;
   swap(&a,&b);
   //printf("%d %d\n",a,b);   
}

