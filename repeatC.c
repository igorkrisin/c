#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Abstract {
    int hight, weight;
};

void calc(struct Abstract *obj);

/* void printHello() {
    printf("Hello");
}
void string(char arr[]);

int fac(int n){
    if(n == 1){
        return 1;
        
    } else {
        return fac(n -1)*n;
        
    }

} */

/* struct Car {
    int speed;
    char name[50];
    float weight;
}; */

/* struct Abstract
{
    int weight, hight;
}; */

//void calc(struct Abstract *object);

int main(){
    struct Abstract square = {5,7};
    calc(&square);


///////Работа с файлами

char line[255];
    FILE *file = fopen("test.txt", "r");
    
    while(!feof(file)){
        if (fgets(line, 255, file) != NULL){ 
            printf("%s", line);
        }
        //fprintf(file, "\nsome new text");
    }
    




    fclose(file);





    /* int num = 0;

    int * pNum = &num;
    printf("%p - %p\n", pNum, &num);
    *pNum = 10;
    printf("%d - %d\n", *pNum, num);
 */
    /* struct Car bmw;
    bmw.speed = 250;
    strcpy(bmw.name, "BMW M5");
    bmw.weight = 2500.00f;

    struct Car audi = {300, "A8", 2700.00f};
   printf("%s его скорость: %d\n", audi.name, audi.speed);
    printf("%s его вес: %f\n", audi.name, audi.weight);

     */
    //printHello();
   // printf("%d",fac(5));
   /*  printf("Hello world! \n");
    

    int arr[] = {1, 2, 3, 4, 5, 6};

    printf("%d\n", arr[1]);


    float numbers[3];
    numbers[0] = 5.4f;

    char word[] = {'S','o','m','e'};

    char words[] = "Some use cases";
    words[1] = 'U';
    printf("%c\n",words[1]);
    printf("%s\n",words);

    for(int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
 int i = 10;
    while (i!=100)
    {
        i++;
        printf("%d", i);
    }
    
 */

   /*  int arr[] = {5, 67, 33 ,6, - 10};
    for(int i = 0; i< 5; i++) {
        printf("%d\n", arr[i]);
    }
    printf("\t");
    int i = 0;
    
    while(i<5) {
        
        printf("%d\n", arr[i]);
        i++;
    } 
     printf("\t");

    i=0;
    do
    {
        
        printf("%d\n", arr[i]);
        i++;
    } while (i<0);
 */

    int arr[] = {5, 67, 33 ,6, - 10};
    int min = arr[0];
    for (int i = 0; i < 5; i++){
        if(min>arr[i]) {
            min = arr[i];
        }
    }
    //printf("%d\n", min);
     return 0;
}

void calc(struct Abstract *obj) {
    int res = obj->hight * obj->weight;
    printf("%d",res);
}













/* void calc(struct Abstract *object){
    int res = object->weight * object->hight;
    printf("Результат: %d", res);
} */