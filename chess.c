#include <stdio.h>
#include <stdlib.h>

//Белые - вывод заглавными буквами
//Черные строчные буквы вывод
typedef struct cell  {
    int goToY;//элемент структуры
	int goToX; 
	int goFromY; 
	int goFromX; 
	struct cell* next;//указатель на сл ноду списка
    
} list;

//cons(13,cons(42,cons(666,NULL))))

list* cons(int cellToY,int cellToX,int cellFromY,int cellFromX, list *lst) {
    list* newCell = malloc(sizeof(list));
    (*newCell).goToY = cellToY; //разименование
    newCell->goToX = cellToX;
    newCell->goFromY = cellFromY;
    newCell->goFromX = cellFromX;
    newCell->next = lst;
    
    return newCell;
} 



void printList(list* lst) {
    while(lst != NULL) {
	printf("%d ", lst->goToY);
	printf("%d ", lst->goToX);
	printf("%d ", lst->goFromY);
	printf("%d\n", lst->goFromX);
	lst = lst->next;
    }
}

list* append(list *lst1, list *lst2) {
    if(lst1 == NULL) return lst2;
	list* p1 = lst1;
	while(p1->next != NULL) {
	    p1 = p1->next;		
	}
	p1->next = lst2;
    return lst1;
	
}

typedef enum pieces {KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, king, queen, bishop, knight, rook, pawn, empty} piece;

    piece bord[8][8] = {
	{rook, knight, bishop, king, queen, bishop, knight, rook},
	{pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn},
	{empty,empty, pawn, empty, empty, empty, empty, empty},
	{empty,empty, empty, empty, empty, empty, empty, empty},
	{empty,empty, empty, empty, empty, empty, empty, empty},
	{empty,empty, empty, empty, empty, empty, empty, empty},
	{PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
	{ROOK, KNIGHT, BISHOP, KING, QUEEN, BISHOP, KNIGHT, ROOK},	
};
		      //0     1
typedef enum colors {white, black} color;

color checkColor(piece pieces) {
    piece blackPiece[6] = {rook, knight, bishop, king, queen, pawn};
    piece whitePiece[6] = {ROOK, KNIGHT, BISHOP, KING, QUEEN, PAWN};

    for(int i = 0; i < 12; i++) {
		if(whitePiece[i] == pieces) {
			return white;
		}
		else if(blackPiece[i] == pieces) {
			return black;
		}
    }
	
    //return printf("error, value piece: %d\n",pieces);
}

color flipColor(piece color) {
    if(checkColor(color) == white) {
	return black;
    }
}



int threatMap[8][8] = {
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
};

void printThrMap(int threatMap[8][8]);
void threatKnight(int y, int x, int threatMap[y][x]);
void printBord(piece bord[8][8]);
void threatKing(int y, int x, int threatMap[8][8]);
void threatRook(int y, int x, int threatMap[8][8]);
void threatBishop(int y, int x, int threatMap[8][8]);
void threatQueen(int y, int x, int threatMap[8][8]);
void threatWitePawn(int y, int x, int threatMap[8][8]);
void threatBlackPawn(int y, int x, int threatMap[8][8]);
int checkCoord(int coordY, int coordX);
void pointEmpty(int y, int x, int threatMap[8][8]);
list* moveKing(int y, int x, piece bord[8][8]);
list* moveKnight(int y, int x, piece bord[8][8]);
list* moveRook(int y, int x, piece bord[8][8]);
list* moveBishop(int y, int x, piece bord[8][8]);
list* moveQueen(int y, int x, piece bord[8][8]);
list* moveWitePawn(int y, int x, piece bord[8][8]);
list* moveBlackPawn(int y, int x, piece bord[8][8]);
void printMove(list* lst,piece bord[8][8]);
// todo BCPL

list* allMove(color colors, piece bord[8][8]) {
    list* amountLst = NULL;
    for(int y = 0; y < 8; y++){
		for(int x = 0; x < 8; x++) {
		 	  if(checkColor(bord[y][x]) == colors) {
				if(bord[y][x] == king || bord[y][x] == KING) {
					amountLst = append(amountLst, moveKing(y,x, bord));
				}
			  
				else if(bord[y][x] == queen || bord[y][x] == QUEEN) {
					amountLst = append(amountLst, moveQueen(y,x, bord));
				}
				else if(bord[y][x] == bishop || bord[y][x] == BISHOP) {
					amountLst = append(amountLst, moveBishop(y,x, bord));
				}
				else if(bord[y][x] == knight || bord[y][x] == KNIGHT) {
					amountLst = append(amountLst, moveKnight(y,x, bord));
				}
				else if(bord[y][x] == rook || bord[y][x] == ROOK) {
					amountLst = append(amountLst, moveRook(y,x, bord));
				}
				else if(bord[y][x] == PAWN) {
					moveWitePawn(y,x, bord);
				}
				else if(bord[y][x] == pawn){
					moveBlackPawn(y,x, bord);
				} 
			} 
		}
	}
    return amountLst;	
}



void allThreatMap(color colors) {
	for(int y = 0; y < 8; y++){
		for(int x = 0; x < 8; x++) {
		 	  if(checkColor(bord[y][x]) == colors) {
				if(bord[y][x] == king || bord[y][x] == KING) {
					threatKing(y,x, threatMap);
				}
			  
				else if(bord[y][x] == queen || bord[y][x] == QUEEN) {
					threatQueen(y,x, threatMap);
				}
				else if(bord[y][x] == bishop || bord[y][x] == BISHOP) {
					threatBishop(y,x, threatMap);
				}
				else if(bord[y][x] == knight || bord[y][x] == KNIGHT) {
					threatKnight(y,x, threatMap);
				}
				else if(bord[y][x] == rook || bord[y][x] == ROOK) {
					threatRook(y,x, threatMap);
				}
				else if(bord[y][x] == PAWN) {
					threatWitePawn(y,x, threatMap);
				}
				else if(bord[y][x] == pawn){
					threatBlackPawn(y,x, threatMap);
				} 
			} 
		}
	}
}
int main() {
	//allThereMap(1);
    //printf("%d",checkColor(pawn));
    //printBord(bord);
	//threatKnight(0,  1,  threatMap);
	//printThrMap(threatMap);
	//threatKing(0,3,threatMap);
	//threatRook(7, 0, threatMap);
	//threatBishop(7,2,threatMap);
	//threatQueen(4,4,threatMap);
	//threatWitePawn(6, 2, threatMap);
	//threatBlackPawn(1, 3, threatMap);

	//printf("threatMap: %d",threatMap[7][7]);
	//printList(cons(13, 15, 16, 18,cons(42,6, 78, 55, cons(666, 777, 444, 222, NULL))));
	
	//printList(moveKing(1, 4, bord));
	//printList(moveKnight(1, 4, bord));
	//printList(moveRook(1, 4, bord));
	//printList(moveBishop(1, 4, bord));
	//printList(moveQueen(5,3, bord));
	//printList(allMove(black, bord));
	//printList(moveWitePawn(1,3,bord));
	//printList(moveBlackPawn(1, 3, bord));
	printMove(moveBishop(2,3,bord), bord);
    return 0;
}

void printBord(piece bord[8][8]) {
    for(int y = 0; y < 8; y++) {
		for(int x = 0; x < 8; x++) {
		switch(bord[y][x]) { 
		case king:
			printf("k");
			break;
		case queen:
			printf("q");
			break;
		case bishop:
			printf("b");
			break;
		case knight:
			printf("k");
			break;
		case rook:
			printf("r");
			break;    
		case pawn:
			printf("p");
			break;    
		case KING:
			printf("K");
			break;    
		case QUEEN:
			printf("Q");
			break;
		case BISHOP:
			printf("B");
			break;
		case KNIGHT:
			printf("K");
			break;
		case ROOK:
			printf("R");
			break;    
		case PAWN:
			printf("P");
			break;    
		case empty:
			printf(" ");
			break;
			}
		
		
		}
			printf("\n");
	}
    
}

void threatKnight(int y, int x, int threatMap[8][8]) {
	int arrY[] = {y + 2, y + 1, y - 1, y - 2,y - 2, y - 1, y + 1, y + 2};
	int arrX[] = {x + 1, x + 2, x + 2, x + 1, x - 1, x - 2, x - 2, x - 1};
	for(int i = 0; i < 8; i++) {
		if(bord[arrY[i]][arrX[i]] != 12 && checkColor(bord[y][x]) == checkColor(bord[arrY[i]][arrX[i]])) {
			continue;
		}
		else {
			if(checkCoord(arrY[i], arrX[i])) {
				threatMap[arrY[i]][arrX[i]] = 1;
			}
		}
	}
	printThrMap(threatMap);
}

void threatKing(int y, int x, int threatMap[8][8]) {
    int arrY[] = {y+1, y+1, y+1, y, y-1, y-1, y-1, y};
    int arrX[] = {x+1, x, x-1, x-1, x-1, x, x+1, x+1};
    for(int i = 0; i < 8; i++) {
		if(bord[arrY[i]][arrX[i]] != 12 && checkColor(bord[y][x]) == checkColor(bord[arrY[i]][arrX[i]])) {
			continue;
		}
		else {
			if(checkCoord(arrY[i], arrX[i] )){
				threatMap[arrY[i]][arrX[i]] = 1;
			}
		}
    }
    	
	printThrMap(threatMap);
}

void threatRook(int y, int x, int threatMap[8][8]) {
	//threatMap[y][x] = 9;
	int arrY[] = {0, 0, 1, -1};
	int arrX[] = {1, -1, 0, 0};
	for(int i = 0; i < 4; i++) {
	    int xChange = x;
	    int yChange = y;
		xChange += arrX[i];
		yChange += arrY[i];
	    while(yChange <= 7&&xChange <= 7&& xChange >= 0&& yChange >= 0){
			if(bord[yChange][xChange] != 12 && checkColor(bord[y][x]) == checkColor(bord[yChange][xChange])) {
				break;
			} 
			threatMap[yChange][xChange] = 1;
			yChange += arrY[i];
			xChange += arrX[i];
		}

	}
	printThrMap(threatMap);
}

void threatBishop(int y, int x, int threatMap[8][8]) {
	int arrY[] = {1, 1, -1, -1};
	int arrX[] = {-1, 1, 1, -1};
	for(int i = 0; i < 4; i++){
		int xChange = x;
		int yChange = y;
		xChange += arrX[i];
		yChange += arrY[i];
		while(yChange <= 7&&xChange <= 7&& xChange >= 0&& yChange >= 0){
			if(bord[yChange][xChange] != 12 && checkColor(bord[y][x]) == checkColor(bord[yChange][xChange])) {
				break;
			} 
			threatMap[yChange][xChange] = 1;
			yChange += arrY[i];
			xChange += arrX[i];
			
		}
	}
	printThrMap(threatMap);
}

void threatQueen(int y, int x, int threatMap[8][8]) {
	//threatMap[y][x] = 9;
	threatBishop(y, x, threatMap);
	threatRook(y, x, threatMap);
}

void threatWitePawn(int y, int x, int threatMap[8][8]) {	
	int arrY[] = {y - 1, y - 1, y - 2, y - 2};
	int arrX[] = {x - 1, x + 1, x - 1, x + 1};
	for(int i = 0; i < 2; i++) {
		if(bord[arrY[i]][arrX[i]] != 12 && checkColor(bord[y][x]) == checkColor(bord[arrY[i]][arrX[i]])) {
			continue;
		}
		else {
			if(checkCoord(arrY[i], arrX[i])){
				threatMap[arrY[i]][arrX[i]] = 1;
			}
		}
	}
					
		printThrMap(threatMap);
}

void pointEmpty(int y, int x, int threatMap[8][8]) {
			threatMap[y][x] = 0;
}

void threatBlackPawn(int y, int x, int threatMap[8][8]) {
	int arrY[] = {y + 1, y + 1, y + 2, y + 2};
	int arrX[] = {x + 1, x - 1, x + 1, x - 1};
	
	for(int i = 0; i < 2; i++) {
		if(bord[arrY[i]][arrX[i]] != 12 && checkColor(bord[y][x]) == checkColor(bord[arrY[i]][arrX[i]])) {
			continue;;
		}
		else {
			if(checkCoord(arrY[i], arrX[i])){
				threatMap[arrY[i]][arrX[i]] = 1;
			}
		}
	}
				
		printThrMap(threatMap);

}
 

list* moveKing(int y, int x, piece bord[8][8]) {
    allThreatMap(flipColor(checkColor(bord[y][x])));
    list* lst = NULL;
    int arrY[] = {y+1, y+1, y+1, y, y-1, y-1, y-1, y};
    int arrX[] = {x+1, x, x-1, x-1, x-1, x, x+1, x+1};
    for(int i = 0; i < 8; i++) {
    
		if(threatMap[arrY[i]][arrX[i]] == 1) {
		    continue;
		}
		if(checkCoord(arrY[i], arrX[i] )){
			lst = cons(y, x, arrY[i], arrX[i], lst);
		} 
    }
    	
	return lst;//todo посмотреть в калькуляторе прием по контролю баланса malloc-free
	// todo посмотреть лекции про макросы в си
	// todo карта с цветными ходами через эскейп последовательности
}

list* moveKnight(int y, int x, piece bord[8][8]) {
	list* lst = NULL;
	int arrY[] = {y + 2, y + 1, y - 1, y - 2,y - 2, y - 1, y + 1, y + 2};
	int arrX[] = {x + 1, x + 2, x + 2, x + 1, x - 1, x - 2, x - 2, x - 1};
	for(int i = 0; i < 8; i++) {
		if(checkCoord(arrY[i], arrX[i])) {
			lst = cons(y, x, arrY[i], arrX[i], lst);
			
		}
	}
	return lst;
}

list* moveRook(int y, int x, piece bord[8][8]) {
	list* lst= NULL;
	int arrY[] = {0, 0, 1, -1};
	int arrX[] = {1, -1, 0, 0};
	
	for(int i = 0; i < 4; i++) {
	    int xChange = x;
	    int yChange = y;
		xChange += arrX[i];
		yChange += arrY[i];
	    while(yChange <= 7&&xChange <= 7&& xChange >= 0&& yChange >= 0){
			
			lst = cons(y, x, yChange, xChange, lst);
			yChange += arrY[i];
			xChange += arrX[i];
		}

	}
	return lst;
}

list* moveBishop(int y, int x, piece bord[8][8]) {
	list* lst =NULL;
	int arrY[] = {1, 1, -1, -1};
	int arrX[] = {-1, 1, 1, -1};
	for(int i = 0; i < 4; i++){
		int xChange = x;
		int yChange = y;
		xChange += arrX[i];
		yChange += arrY[i];
		while(yChange <= 7&&xChange <= 7&& xChange >= 0&& yChange >= 0){
			lst = cons(y, x, yChange, xChange, lst);
			yChange += arrY[i];
			xChange += arrX[i];
			
		}
	}
	return lst;
}

list* moveQueen(int y, int x, piece bord[8][8]) {
	return append(moveRook(y,x, bord), moveBishop(y,x,bord));
}

list* moveWitePawn(int y, int x, piece bord[8][8]) {	
	list* lst = NULL;
	int arrY[] = {y - 1, y - 1, y - 2, y - 2};
	int arrX[] = {x - 1, x + 1, x - 1, x + 1};
	for(int i = 0; i < 2; i++) {
		if(checkCoord(arrY[i], arrX[i])) {
			lst = cons(y, x, arrY[i], arrX[i], lst);
		}
	}
					
		return lst;
}

list* moveBlackPawn(int y, int x, piece bord[8][8]) {
	list* lst = NULL;
	int arrY[] = {y + 1, y + 1, y + 2, y + 2};
	int arrX[] = {x + 1, x - 1, x + 1, x - 1};
	
	for(int i = 0; i < 2; i++) {
		if(checkCoord(arrY[i], arrX[i])) {
			lst = cons(y, x, arrY[i], arrX[i], lst);
		}
	}
				
		return lst;

}


int checkCoord(int coordY, int coordX) {
    if(coordY > 7 || coordY < 0 || coordX > 7 || coordX < 0) {
		return 0;
    }
    else {
		return 1;
    }

}

void printThrMap(int threatMap[8][8]){
	for(int y = 0; y < 8; y++) {
		for(int x = 0; x < 8; x++){
			printf("%d",threatMap[y][x]);
		}
		printf("\n");
	}
		printf("\n");
}

void printMove(list* lst,piece bord[8][8]) {
	while (lst->next != NULL) {
		printf("%p", bord);
	}
	 
}




























