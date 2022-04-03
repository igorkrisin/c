#include <stdio.h>
#include <stdlib.h>

//Белые - вывод заглавными буквами
//Черные строчные буквы вывод
typedef struct cell  {
    int goToY; int goToX; int goFromY; int goFromX; struct cell* next;
    
} list;

//cons(13,cons(42,cons(666,NULL))))

list* cons(list* lst, int cellToY,int cellToX,int cellFromY,int cellFromX) {
    list* newCell = malloc(1000);
    (*newCell).goToY = cellToY; //разименование
    newCell->goToX = cellToX;
    newCell->goFromY = cellFromY;
    newCell->goFromX = cellFromX;
    newCell->next = lst;
    
    return newCell;
} 


typedef enum pieces {KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, king, queen, bishop, knight, rook, pawn, empty} piece;

    piece bord[8][8] = {
	{rook, knight, bishop, king, queen, bishop, knight, rook},
	{pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn},
	{empty,empty, empty, empty, empty, empty, empty, empty},
	{empty,empty, empty, empty, empty, empty, empty, empty},
	{empty,empty, empty, empty, empty, empty, empty, empty},
	{empty,empty, empty, empty, empty, empty, empty, empty},
	{PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
	{ROOK, KNIGHT, BISHOP, KING, QUEEN, BISHOP, KNIGHT, ROOK},	
};
		      //0     //1
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
void threatEmpty(int y, int x, int threatMap[8][8]);

void allThereMap(color colors) {
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
	//threatKnight(3,  4,  threatMap);
	//printThrMap(threatMap);
	//threatKing(3,5,threatMap);
	//threatRook(3,5, threatMap);
	threatBishop(7,2,threatMap);
	//threatQueen(4,4,threatMap);
	//threatWitePawn(5, 2, threatMap);
	//threatBlackPawn(1, 3, threatMap);

	//printf("threatMap: %d",threatMap[7][7]);
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
	//threatMap[y][x] = 9;
	int arrY[] = {y + 2, y + 1, y - 1, y - 2,y - 2, y - 1, y + 1, y + 2};
	int arrX[] ={x + 1, x + 2, x + 2, x + 1, x - 1, x - 2, x - 2, x - 1};

	for(int i = 0; i < 8; i++) {
		if(checkCoord(arrY[i], arrX[i])) {
			threatMap[arrY[i]][arrX[i]] = 1;
		}
	}
	printThrMap(threatMap);
}

void threatKing(int y, int x, int threatMap[8][8]) {
    
    
    int arrY[] = {y+1, y+1, y+1, y, y-1, y-1, y-1, y};
    int arrX[] = {x+1, x, x-1, x-1, x-1, x, x+1, x+1};
    for(int i = 0; i < 8; i++) {
	if(checkCoord(arrY[i], arrX[i] )){
	    threatMap[arrY[i]][arrX[i]] = 1;
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
	    while (checkCoord(yChange, xChange)){ 
			xChange += arrX[i];
			yChange += arrY[i];
			if (yChange <= 7&&xChange <= 7&& xChange >= 0&& yChange >= 0){
				threatMap[yChange][xChange] = 1;
			}
		}
	}//to do  если на борд клетка не empty, то область удара уменьшается в соответсвии с расположением фигуры (если это противник, то на клетку с фигурой можно встать, если совой, то нельзя)
	    
	printThrMap(threatMap);
}


//123
//456x
//789

//123456789

void threatBishop(int y, int x, int threatMap[8][8]) {
	int arrY[] = {1, 1, -1, -1};
	int arrX[] = {-1, 1, 1, -1};
	for(int i = 0; i < 4; i++){
		int xChange = x;
		int yChange = y;
		while(checkCoord(yChange, xChange)){
			yChange += arrY[i];
			xChange += arrX[i];
			if (yChange <= 7&&xChange <= 7&& xChange >= 0&& yChange >= 0){//todo сократить количество проверок, рефакторить код
				threatMap[yChange][xChange] = 1;
			}
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
	if (y == 6) {
		for(int i = 0; i < 4; i++) {
			
			if(checkCoord(arrY[i], arrX[i])){
				threatMap[arrY[i]][arrX[i]] = 1;
			}
		}
	}
	else {
		for(int i = 0; i < 2; i++) {
			if(checkCoord(arrY[i], arrX[i])){
				threatMap[arrY[i]][arrX[i]] = 1;
			}
		}
	}				
		printThrMap(threatMap);
}

void threatEmpty(int y, int x, int threatMap[8][8]) {
			threatMap[y][x] = 0;
}

void threatBlackPawn(int y, int x, int threatMap[8][8]) {
	int arrY[] = {y + 1, y + 1, y + 2, y + 2};
	int arrX[] = {x + 1, x - 1, x + 1, x - 1};
	if (y == 1) {
		for(int i = 0; i < 4; i++) {
			
			if(checkCoord(arrY[i], arrX[i])){
				threatMap[arrY[i]][arrX[i]] = 1;
			}
		}
	}
	else {
		for(int i = 0; i < 2; i++) {
			if(checkCoord(arrY[i], arrX[i])){
				threatMap[arrY[i]][arrX[i]] = 1;
			}
		}
	}				
		printThrMap(threatMap);

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




























