#include <stdio.h>




//Белые - вывод заглавными буквами
//король - 1
//ферзь - 2
//жеребец - 3
//ладья - 4
//слон - 5
//пешка - 6


//Черные строчные буквы вывод
//король - 7
//ферзь - 8
//жеребец - 9
//ладья - 10
//слон - 11
//пешка - 12

//ничего - 13



int bord[8][8] = {
{11, 9, 10, 7, 8, 10, 9, 11},
{12, 12, 12, 12, 12, 12, 12, 12},
{13,13, 13, 13, 13, 13, 13, 13},
{13,13, 13, 13, 13, 13, 13, 13},
{13,13, 13, 13, 13, 13, 13, 13},
{13,13, 13, 13, 13, 13, 13, 13},
{6, 6, 6, 6, 6, 6, 6, 6},
{5, 3, 4, 1, 2, 4, 3, 5},	
};



int threatMap[8][8] {
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
};

void threatHors(int y, int x) {


    y = y+2;
    x = x+1;
    
    if(y < 7) || (x < 7 {
	threatMap[y][x] = 1;
    }
    
    
    y = 
}

//to do почитать и переделать программу в телеге ссылка
//to do разобраться с англ названиями
//to do доделать treatHors и распечатать  threatMap  для проверки

void printBord(int bord[8][8]) {
    for(int y = 0; y < 8; y++) {
	for(int x = 0; x < 8; x++) {
	switch(bord[y][x]) { 
	case 1:
	    printf("К");
	    break;
	case 2:
	    printf("Ф");
	    break;
	case 3:
	    printf("Ж");
	    break;
	case 4:
	    printf("Л");
	    break;
	case 5:
	    printf("С");
	    break;    
	case 6:
	    printf("П");
	    break;    
	case 7:
	    printf("к");
	    break;    
	case 8:
	    printf("ф");
	    break;
	case 9:
	    printf("ж");
	    break;
	case 10:
	    printf("л");
	    break;
	case 11:
	    printf("с");
	    break;    
	case 12:
	    printf("п");
	    break;    
	case 13:
	    printf(" ");
	    break;
	    }
	
	
	}
        printf("\n");
    }
    
}

 


int main() {

    printBord(bord);



    return 0;
}