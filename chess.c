#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;43m"
#define WHITE   "\033[1;37m"
#define DEFAULTGR   "\x1b[0m"
#define MAGENTA "\033[35m"     
#define CYAN    "\033[36m" 
#define BLACKBG   "\033[40m" 
#define PRINT "printf"
//#define CURS "[10;30Н"   

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

list* cons(int cellFromY,int cellFromX,int cellToY,int cellToX, list *lst) {
    list* newCell = (list*)malloc(sizeof(list));
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

typedef enum pieces {KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, king, queen, bishop, knight, rook, pawn, empty} piece;//todo вывести на печать фигуры юникод вместо букв на печать

    piece board[64] = {
	rook, knight, bishop, king, queen, bishop, knight, rook,
	pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn,
	empty,empty, empty, empty, empty, empty, empty, empty,
	empty,empty, empty, empty, empty, empty, empty, empty,
	empty,empty, empty, empty, empty, empty, empty, empty,
	empty,empty, empty, empty, empty, empty, empty, empty,
	PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
	ROOK, KNIGHT, BISHOP, KING, QUEEN, BISHOP, KNIGHT, ROOK,	
};

typedef struct boards {
	piece board;
	struct boards* next;
} otherBoards;
		              //0     1
typedef enum colors {white, black} color;
//прототипы
void printThrMap(int threatMap[64]);
void threatKnight(int y, int x, int threatMap[y*8+x]);
void printBord(piece board[64]);
void threatKing(int y, int x, int threatMap[64]);
void threatRook(int y, int x, int threatMap[64]);
void threatBishop(int y, int x, int threatMap[64]);
void threatQueen(int y, int x, int threatMap[64]);
void threatWitePawn(int y, int x, int threatMap[64]);
void threatBlackPawn(int y, int x, int threatMap[64]);
int checkCoord(int coordY, int coordX);
void pointEmpty(int y, int x, int threatMap[64]);
list* moveKing(int y, int x, piece board[64]);
list* moveKnight(int y, int x, piece board[64]);
list* moveRook(int y, int x, piece board[64]);
list* moveBishop(int y, int x, piece board[64]);
list* moveQueen(int y, int x, piece board[64]);
list* moveWhitePawn(int y, int x, piece board[64]);
list* moveBlackPawn(int y, int x, piece board[64]);
void printMove(piece board[64], list* move);
int findMove(int y , int x, list* move);
void switchBoard(int y,int x,piece board[64]);
void delList(list* lst);
int countEl(list* lst);
list* returnEl(list* lst, int numbEl);
void doMove(piece board[64], color(colors), list* lst);
int amountValuePiecec(piece board[64], color colors);
int minValueMove(piece board[64], list* move, color colors);
piece valueMove(piece board[64], int goToY, int goToX, int goFromY, int goFromX, color colors);
void checkKing(int* y, int* x, color colors);
piece* copyBoard(piece board[64]);
int checkMate(piece board[64], color colors);
piece returnRandPiece(piece board[64], color colors);
list* pawnCheckEnemyWhite(int y, int x, piece board[64]);
int returnValueThMap(int y, int x, color colors);
list* doMoveKingColor(int y, int x,piece board[64],color colors);
int countMove(piece board[64], color colors, int depth);

color checkColor(piece pieces) {
    piece blackPiece[6] = {rook, knight, bishop, king, queen, pawn};
    piece whitePiece[6] = {ROOK, KNIGHT, BISHOP, KING, QUEEN, PAWN};

    for(int i = 0; i < 6; i++) {
		if(whitePiece[i] == pieces) {
			return white;
		}
		else if(blackPiece[i] == pieces) {
			return black;
		}
    }
	
    //return printf("error, value piece: %d\n",pieces);
}

int comparPiece(piece piece1, piece piece2){
    piece blackPiece[6] = {rook, knight, bishop, king, queen, pawn};
    piece whitePiece[6] = {ROOK, KNIGHT, BISHOP, KING, QUEEN, PAWN};
    for(int i = 0; i < 6; i++) {
		if(piece1 == blackPiece[i] && piece2 == whitePiece[i] || piece1 == whitePiece[i] && piece2 == blackPiece[i]) {
			return 1;
		}
    }
    return 0;
}

color flipColor(color col) {
    if(col  == white) {
		return black;
    }
    return white;
}

int threatMap[64] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0
};


// todo BCPL

list* allMove(color colors, piece board[64]) {
    list* amountLst = NULL;
    for(int y = 0; y < 8; y++){
		for(int x = 0; x < 8; x++) {
		 	  if(checkColor(board[y*8+x]) == colors) {
				if(board[y*8+x] == king || board[y*8+x] == KING) {
					//printf("%s \n", "king");
					amountLst = append(amountLst, moveKing(y,x, board));
				}
			  
				else if(board[y*8+x] == queen || board[y*8+x] == QUEEN) {
					//printf("%s \n", "queen");
					amountLst = append(amountLst, moveQueen(y,x, board));
				}
				else if(board[y*8+x] == bishop || board[y*8+x] == BISHOP) {
					//printf("%s \n", "bishop");
					amountLst = append(amountLst, moveBishop(y,x, board));
				}
				else if(board[y*8+x] == knight || board[y*8+x] == KNIGHT) {
					//printf("%s \n", "knight");
					amountLst = append(amountLst, moveKnight(y,x, board));
				}
				else if(board[y*8+x] == rook || board[y*8+x] == ROOK) {
					//printf("%s \n", "rook");
					amountLst = append(amountLst, moveRook(y,x, board));
				}
				else if(board[y*8+x] == PAWN) {
					//printf("%s \n", "whitePW");
					amountLst = append(amountLst, moveWhitePawn(y,x, board));
				}
				else if(board[y*8+x] == pawn){
					//printf("%s \n", "blackPW");
					amountLst = append(amountLst, moveBlackPawn(y,x, board));
				} 
			} 
		}
	}
    return amountLst;	
}




int*  allThreatMap(color colors) {
    int* newThMap = malloc(sizeof(int)*64); // malloc returnS pointer, malloc возвращвет указатель   I hop. He hopS. She hopS. We hop. It hopS.
	for(int i = 0; i < 64; i++) {
	    newThMap[i] = 0;
	}
	for(int y = 0; y < 8; y++){
		for(int x = 0; x < 8; x++) {
		 	  if(checkColor(board[y*8+x]) == colors) {
				if(comparPiece(board[y*8+x], KING)) {
					threatKing(y,x, newThMap);
				}
				else if(comparPiece(board[y*8+x], QUEEN)) {
					threatQueen(y,x, newThMap);
				}
				else if(comparPiece(board[y*8+x], BISHOP)) {
					threatBishop(y,x, newThMap);
				}
				else if(comparPiece(board[y*8+x], KNIGHT)) {
					threatKnight(y,x, newThMap);
				}
				else if(comparPiece(board[y*8+x], ROOK)) {
					threatRook(y,x, newThMap);
				}
				else if(board[y*8+x] == PAWN) {
					threatWitePawn(y,x, newThMap);
				}
				else if(board[y*8+x] == pawn){
					threatBlackPawn(y,x, newThMap);
				} 
			} 
		}
		
	}
	return newThMap;
}
int main() {
	//allThreatMap(white);
    //printf("%d",checkColor(pawn));
    //printBord(board);
	//threatKnight(0,  1,  threatMap);
	//printThrMap(threatMap);
	//threatKing(0,3,threatMap);
	//threatRook(3, 5, threatMap);
	//threatBishop(3,3,threatMap);
	//                                                                                                                                                                                                                    ф threatQueen(4,4,threatMap);
	//threatWitePawn(2, 2, threatMap);
	//threatBlackPawn(1, 3, threatMap);
	//printf("threatMap: %d",threatMap[7][7]);
	//printList(cons(13, 15, 16, 18,cons(42,6, 78, 55, cons(666, 777, 444, 222, NULL))));
	//printList(moveKing(4, 6, board));
	//printList(moveKnight(1, 4, board));
	//printList(moveRook(1, 4, board));
	//printList(moveBishop(3, 3, board));
	//printList(moveQueen(5,3, board));
	//printList(allMove(black, board));
	//printMove(board,moveWhitePawn(6, 4, board));
	//printList(moveBlackPawn(1,3,board));
	//printList(moveKnight(0, 6, board));
	//printMove(board, moveKnight(0, 6, board));
	//printf("%d",findMove(1,3, moveKing(1, 3, board)));
	//delList(moveBlackPawn(1, 3, board));
	//doMove(board, 0);
	//printf("%d",gameOver(board, 0, 3));
	//printf("%d",amountValuePiecec(board, white));
	//printf("%d",valueMove(board,5,2,6,2,white));
	//printf("%d",minValueMove(board, moveKnight(7,1,board), white));
	//doMove(board, white, returnEl(allMove(white, board), minValueMove(board, allMove(white, board), white)));
	//printf("%d\n",returnRandPiece(board, white));	
	//printf("%d\n", comparPiece(king, QUEEN)); //todo использовать по назначению - не понял как применить?
	//printBord(copyBoard(board));
	//printList(pawnChekEnemyWhite(6,3,board));
/* 	int x,y;
	
	checkKing(&x, &y, black);
	printf("x: %d\n y: %d\n ", x , y);
 */	
	//printf("%d",returnValueThMap(5,3,black));
//checkMate(board, white);
//printList(doMoveKingColor(0, 3, board, black));
   int whiteBl = white;
 	  while(1) {
 	    whiteBl = flipColor(whiteBl);
		printf("wb: %d , ", whiteBl);
 	    printf("minVal: %d\n",minValueMove(board, allMove(whiteBl, board), whiteBl));
		 if(checkMate(board, white)){
		    break;
		}
		if(checkMate(board, black)){
		    break;
		}
		doMove(board, whiteBl, returnEl(allMove(whiteBl, board), minValueMove(board, allMove(whiteBl, board), whiteBl)));
		printBord(board);
		//printList(moveKing(whiteBl, board));
		
		
		getchar();
	    
	} 
	/* for(int depth = 1; depth < 7; depth++) {
	    printf("numb: %d countMove: %d\n", depth, countMove(board, white, depth));
	}  */
	
 	//doMove(board, white, returnEl(allMove(white, board), minValueMove(board, allMove(white, board), white)));
  //doMove(board, black, returnEl(allMove(black, board), minValueMove(board, allMove(black, board), black)));
  //doMove(board, white, returnEl(allMove(white, board), minValueMove(board, allMove(white, board), white)));
   return 0;
}

void printBord(piece board[64]) {
    for(int y = 0; y < 8; y++) {
		for(int x = 0; x < 8; x++) {
			switchBoard(y,x,board);
		}
			printf("\n");
	}   
}

void threatKnight(int y, int x, int threatMap[64]) {
	int arrY[] = {y + 2, y + 1, y - 1, y - 2,y - 2, y - 1, y + 1, y + 2};
	int arrX[] = {x + 1, x + 2, x + 2, x + 1, x - 1, x - 2, x - 2, x - 1};
	for(int i = 0; i < 8; i++) {
		if(checkCoord(arrY[i], arrX[i])) {
		if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) == checkColor(board[arrY[i]*8+arrX[i]])) {
			continue;
		}
		else {
				threatMap[arrY[i]*8+arrX[i]] = 1;
			}
		}
	}
	//printThrMap(threatMap);
}

void threatKing(int y, int x, int threatMap[64]) {
    int arrY[] = {y+1, y+1, y+1, y, y-1, y-1, y-1, y};
    int arrX[] = {x+1, x, x-1, x-1, x-1, x, x+1, x+1};
    for(int i = 0; i < 8; i++) {
	if(checkCoord(arrY[i], arrX[i] )){
		if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) == checkColor(board[arrY[i]*8+arrX[i]])) {
			continue;
		}
		else {
				threatMap[arrY[i]*8+arrX[i]] = 1;
			}
		}
    }
	//printThrMap(threatMap);
}
void threatRook(int y, int x, int threatMap[64]) {
	int arrY[] = {1, 0, 0, -1};
	int arrX[] = {0, -1, 1, 0};
	for(int i = 0; i < 4; i++){
		int xChange = x;
		int yChange = y;
		xChange += arrX[i];
		yChange += arrY[i];
		while(yChange <= 7&& xChange <= 7 && xChange >= 0&& yChange >= 0){
			if(checkColor(board[y*8+x]) == checkColor(board[yChange*8+xChange]) && board[yChange*8+xChange] != empty) {
				break;
			} 
			else if(board[yChange*8+xChange] != empty && checkColor(board[y*8+x]) != checkColor(board[yChange*8+xChange])) {
			    threatMap[yChange*8+xChange] = 1;
			    break;
			}			
 		threatMap[yChange*8+xChange] = 1;
			yChange += arrY[i];
			xChange += arrX[i];
			
		}
	}
	//printThrMap(threatMap);
}

void threatBishop(int y, int x, int threatMap[64]) {
	int arrY[] = {1, 1, -1, -1};
	int arrX[] = {1, -1, 1, -1};
	for(int i = 0; i < 4; i++){
		int xChange = x;
		int yChange = y;
		xChange += arrX[i];
		yChange += arrY[i];
		while(yChange <= 7&& xChange <= 7 && xChange >= 0&& yChange >= 0){
			if(board[yChange*8+xChange] != empty && checkColor(board[y*8+x]) == checkColor(board[yChange*8+xChange])) {
				break;
			} 
			else if(board[yChange*8+xChange] != empty && checkColor(board[y*8+x]) != checkColor(board[yChange*8+xChange])) {
			    threatMap[yChange*8+xChange] = 1;
			    break;
			}			
 		threatMap[yChange*8+xChange] = 1;
			yChange += arrY[i];
			xChange += arrX[i];
			
		}
	}
	//printThrMap(threatMap);
}

void threatQueen(int y, int x, int threatMap[64]) {
	threatRook(y, x, threatMap);
	threatBishop(y, x, threatMap);
}

void threatWitePawn(int y, int x, int threatMap[64]) {	
	int arrY[] = {y - 1, y - 1};
	int arrX[] = {x - 1, x + 1};
	for(int i = 0; i < 2; i++) {
		if(checkCoord(arrY[i], arrX[i])){
			if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) == checkColor(board[arrY[i]*8+arrX[i]])) {
				continue;
			}
			else {
				threatMap[arrY[i]*8+arrX[i]] = 1;
				}
			}
	}
		//printThrMap(threatMap);
}

void pointEmpty(int y, int x, int threatMap[64]) {
			threatMap[y*8+x] = 0;
}

void threatBlackPawn(int y, int x, int threatMap[64]) {
	int arrY[] = {y + 1, y + 1};
	int arrX[] = {x + 1, x - 1};
	for(int i = 0; i < 2; i++) {
	if(checkCoord(arrY[i], arrX[i])){
		if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) == checkColor(board[arrY[i]*8+arrX[i]])) {
			continue;
		}
		else {
				threatMap[arrY[i]*8+arrX[i]] = 1;
			}
		}
	}
		//printThrMap(threatMap);
}
 
list* moveKing(int y, int x, piece board[64]) {
    int* newThMap = allThreatMap(flipColor(checkColor(board[y*8+x])));
    list* lst = NULL;
    int arrY[] = {y+1, y+1, y+1, y, y-1, y-1, y-1, y};
    int arrX[] = {x+1, x, x-1, x-1, x-1, x, x+1, x+1};
    for(int i = 0; i < 8; i++) {
		if(checkCoord(arrY[i], arrX[i] )){
		if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) == checkColor(board[arrY[i]*8+arrX[i]])) {
			continue;
		}
		else {
			if(newThMap[arrY[i]*8+arrX[i]] == 1) {
				continue;
			}
			else {
			
					lst = cons(y, x, arrY[i], arrX[i], lst);
				} 
			}
		}
    }
	//printList(lst);
	return lst;
}

list* moveKnight(int y, int x, piece board[64]) {
	list* lst = NULL;
	int arrY[] = {y + 2, y + 1, y - 1, y - 2,y - 2, y - 1, y + 1, y + 2};
	int arrX[] = {x + 1, x + 2, x + 2, x + 1, x - 1, x - 2, x - 2, x - 1};
	for(int i = 0; i < 8; i++) {
	    if(checkCoord(arrY[i], arrX[i])) {
		if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) == checkColor(board[arrY[i]*8+arrX[i]])) {
			continue;
		}
		else {
				lst = cons(y, x, arrY[i], arrX[i], lst);
			}
		}
	}
	return lst;
}

list* moveRook(int y, int x, piece board[64]) {
	list* lst= NULL;
	int arrY[] = {0, 0, 1, -1};
	int arrX[] = {1, -1, 0, 0};
	
	for(int i = 0; i < 4; i++) {
	    int xChange = x;
	    int yChange = y;
		xChange += arrX[i];
		yChange += arrY[i];
	    while(yChange <= 7&&xChange <= 7&& xChange >= 0&& yChange >= 0){
			if(board[yChange*8+xChange] != empty && checkColor(board[y*8+x]) == checkColor(board[yChange*8+xChange])) {
				break;
			}
			else if(board[yChange*8+xChange] != empty && checkColor(board[y*8+x]) != checkColor(board[yChange*8+xChange])) {
				lst = cons(y, x, yChange, xChange, lst);
				yChange += arrY[i];
				xChange += arrX[i];
				break;
			}
			lst = cons(y, x, yChange, xChange, lst);
			yChange += arrY[i];
			xChange += arrX[i];
		}
	}
	return lst;
}

list* moveBishop(int y, int x, piece board[64]) {
	list* lst =NULL;
	int arrY[] = {1, 1, -1, -1};
	int arrX[] = {-1, 1, 1, -1};
	for(int i = 0; i < 4; i++){
		int xChange = x;
		int yChange = y;
		xChange += arrX[i];
		yChange += arrY[i];
		while(yChange <= 7&&xChange <= 7&& xChange >= 0&& yChange >= 0){
			if(board[yChange*8+xChange] != empty && checkColor(board[y*8+x]) == checkColor(board[yChange*8+xChange])) {
				break;
			}
			else if(board[yChange*8+xChange] != empty && checkColor(board[y*8+x]) != checkColor(board[yChange*8+xChange])) {
				lst = cons(y, x, yChange, xChange, lst);
				yChange += arrY[i];
				xChange += arrX[i];
				break;
			}
			lst = cons(y, x, yChange, xChange, lst);
			yChange += arrY[i];
			xChange += arrX[i];
		}
	}
	return lst;
}

list* moveQueen(int y, int x, piece board[64]) {
	return append(moveRook(y,x, board), moveBishop(y,x,board));
}

list* pawnCheckEnemyWhite(int y, int x, piece board[64]){
	list* lst = NULL;
	int arrY[] = {y - 1, y - 1};
	int arrX[] = {x + 1, x - 1};
	
	for(int i; i < 2; i++){
		if(checkCoord(arrY[i], arrX[i])){
			if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) != checkColor(board[arrY[i]*8+arrX[i]])) {
				lst = cons(y, x, arrY[i], arrX[i], lst);
			}
		}
		else{
			continue;
		}
	}
	return lst;
}


list* pawnCheckEnemyBlack(int y, int x, piece board[64]){
	list* lst = NULL;
	int arrY[] = {y + 1, y + 1};
	int arrX[] = {x + 1, x - 1};
	
	for(int i; i < 2; i++){
		if(checkCoord(arrY[i], arrX[i])){
			if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) != checkColor(board[arrY[i]*8+arrX[i]])) {
				lst = cons(y, x, arrY[i], arrX[i], lst);
			}
		}
		else{
			continue;
		}
	}
	return lst;
}
//проблема 1: белый начинеет ход приемущественно с пешек, черный с других фигур, черный пешками не ходит.
//проблема 2: белый пешками не рубит
//проблема 3: segmentation fault когда происходит мат

list* moveWhitePawn(int y, int x, piece board[64]) {	
	list* lst = NULL;
	list* lst2 = NULL;
	int arrY[] = {y - 1, y - 2};
	int arrX[] = {x , x};
	lst2 = pawnCheckEnemyWhite(y, x, board);
			if(lst2 != NULL){
				lst = append(lst, lst2);
			}
	if (y != 6) {
		for(int i = 0; i < 1; i++) {
			if(checkCoord(arrY[i], arrX[i])) {
			if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) == checkColor(board[arrY[i]*8+arrX[i]])) {
				continue;
			}
			else if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) != checkColor(board[arrY[i]*8+arrX[i]])) {
				continue;
			}
			else {
					lst = cons(y, x, arrY[i], arrX[i], lst);
				}
			}
		}	
	}
	else {
		for(int i = 0; i < 2; i++) {
			if(checkCoord(arrY[i], arrX[i])) {
				if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) == checkColor(board[arrY[i]*8+arrX[i]])) {
					continue;
				}
				else if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) != checkColor(board[arrY[i]*8+arrX[i]])) {
					continue;
				}
				else {
						lst = cons(y, x, arrY[i], arrX[i], lst);
				}
			}
		}	
	}	
		return lst;
}



list* moveBlackPawn(int y, int x, piece board[64]) {
	list* lst = NULL;
	list* lst2 = NULL;
	int arrY[] = {y + 1, y + 2};
	int arrX[] = {x , x};
	lst2 = pawnCheckEnemyBlack(y, x, board);
			if(lst2 != NULL){
				lst = append(lst, lst2);
			}
	if (y != 6) {
		for(int i = 0; i < 1; i++) {
			if(checkCoord(arrY[i], arrX[i])) {
			if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) == checkColor(board[arrY[i]*8+arrX[i]])) {
				continue;
			}
			else if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) != checkColor(board[arrY[i]*8+arrX[i]])) {
				continue;
			}
			else {
					lst = cons(y, x, arrY[i], arrX[i], lst);
				}
			}
		}	
	}
	else {
		for(int i = 0; i < 2; i++) {
			if(checkCoord(arrY[i], arrX[i])) {
				if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) == checkColor(board[arrY[i]*8+arrX[i]])) {
					continue;
				}
				else if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) != checkColor(board[arrY[i]*8+arrX[i]])) {
					continue;
				}
				else {
						lst = cons(y, x, arrY[i], arrX[i], lst);
				}
			}
		}
		
	}	
	
	//printList(lst);
		return lst;
}


//if x>0: return 1 else return 0
//return x>0

int checkCoord(int coordY, int coordX) {
    return !(coordY > 7 || coordY < 0 || coordX > 7 || coordX < 0);
}

void printThrMap(int threatMap[64]){
	for(int y = 0; y < 8; y++) {
		for(int x = 0; x < 8; x++){
			printf("%d",threatMap[y*8+x]);
		}
		printf("\n");
	}
		printf("\n");
}

// a[i]
// *(a+i)

int findMove(int y , int x, list* move) {
    while(move != NULL) {
		if(y == move->goToY && x == move->goToX) {
			return 1;
		}
		else {
			move = move->next;
		}
    }
    return 0;
}

void printMove(piece board[64], list* move) {
    for(int y = 0; y < 8; y++) {
		printf("%s", BLACKBG);
		for(int x = 0; x < 8; x++) {	
			if(findMove(y , x, move)) {
				printf("%s", RED );
			}
			else {
				printf("%s", WHITE);
			}
			switchBoard(y, x, board);
		} 
		printf("%s\n", DEFAULTGR);
	}   
}

void switchBoard(int y,int x,piece board[64]){
	switch(board[y*8+x]) { 
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
			printf("h");
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
			printf("H");
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

void delList(list* lst) {
    while(lst != NULL) {
	list* tempP = lst;
	lst = lst->next;
	free(tempP);
    }
}

int countEl(list* lst) {
    int count = 0;
    while(lst != NULL) {
	count++;
	lst = lst->next;
    }
    return count;
}

list* returnEl(list* lst, int numbEl) {
    int count = 0;
    while(count != numbEl) {
	count++;
	lst = lst -> next;
    }
    return lst;
}

piece returnRandPiece(piece board[64], color colors) {
	int count = 0;
	for(int y1 = 0; y1 < 8; y1++) {
		for(int x1 = 0; x1 < 8; x1++) { 
			if(board[y1*8+x1] > 0 && board[y1*8+x1] <= 11 && checkColor(board[y1*8+x1]) == colors) {
				count++;
			}
		}
	}
		
	int randTime;

	long ltime = time(NULL); 
	randTime = (unsigned) ltime/2;
	srand(randTime);
    return  rand()%count;   
} 

//создаем список всех возможных ходов, смотрим сколько там ходов и из этого диапазона создем ранд число,
// выбираем ход исходя из ранд числа из списка возможных ходов , изменяем карту так, тчо бы фигура придвинулась в это место

/* void doMove(piece board[64], color(colors)) {
    list* lst = allMove(colors, board);
	//printList(lst);
	int randTime;
	long ltime = time(NULL); 
	randTime = (unsigned) ltime/2;
	srand(randTime);
    int randEl = rand()%countEl(lst);
    list* temp = returnEl(lst, randEl);
    board[temp->goToY*8 + temp->goToX] = board[temp->goFromY*8+temp->goFromX];
    board[temp->goFromY*8+temp->goFromX] = empty; 
	printBord(board)  ;
} */

void doMove(piece board[64], color(colors), list* lst) {
    board[lst->goToY*8 + lst->goToX] = board[lst->goFromY*8+lst->goFromX];
    board[lst->goFromY*8+lst->goFromX] = empty; 
}
void checkKing(int* y, int* x, color colors) {
    for(int y1 = 0; y1 < 8; y1++) {
		for(int x1 = 0; x1 < 8; x1++) {
		    if(board[y1*8+x1] == king && checkColor(board[y1*8+x1]) == colors || board[y1*8+x1] == KING && checkColor(board[y1*8+x1]) == colors) {
				*y = y1;
				*x = x1;
		    }
		}
    }
}

/* 
int checkMate(piece board[64], color colors) {
	int x, y;
	checkKing(&y, &x, colors);
	int* newThMap = allThreatMap(flipColor(colors));
	if(newThMap[y*8+x]){ 
	printf("%d\n", 1);
	printList(moveKing(y, x, board));
		if(moveKing(y,x,board) == NULL ) {
		printf("%s\n", "moveKing != NULL");
			list* temp = allMove(colors, board);
			printList(temp);
			while(temp != NULL) {
			printf("%s\n", "trmp != null");
				piece* cpBoard = copyBoard(board);
				doMove(cpBoard, colors, temp);
				//cpBoard[temp->goToY*8 + temp->goToX] = cpBoard[temp->goFromY*8+temp->goFromX];
				//cpBoard[temp->goFromY*8+temp->goFromX] = empty; 
				printBord(cpBoard);
				if(moveKing(y, x, cpBoard) != NULL) {
				printf("%s\n", "dont mate");
				//todo minimax  алгоритм по значениям для макимального урона и минимальных потерь
				// проверка на мат делаем для всех фигур не рубит ли она короля - если рубит то break
					return 1;
				}
				temp = temp->next;
			}
			return 0;
		}	
	}
		printf("%s\n", "dont mate end");
	return 1;
} */

int returnValueThMap(int y, int x, color colors) {
	int* newThMap = allThreatMap(flipColor(colors));
	if(newThMap[y*8+x] == 1) {
		return 1;
	}
	return 0;
}

int checkMate(piece board[64], color colors) {
	int x, y;
	checkKing(&y, &x, colors);
	//printList(doMoveKingColor(y, x, board, colors));
	if(returnValueThMap(y,x,colors)/*&& doMoveKingColor(y, x, board, colors) == NULL*/){  //когда будет готова логика ухода короля от удара - раскомментировать
		printf("returnValueThMap: %d\n", 1);
		return 1;
	}
	return 0;
}

list* doMoveKingColor(int y, int x,piece board[64],color colors) {
	 int* newThMap = allThreatMap(colors);
    list* lst = NULL;
    int arrY[] = {y+1, y+1, y+1, y, y-1, y-1, y-1, y};
    int arrX[] = {x+1, x, x-1, x-1, x-1, x, x+1, x+1};
    for(int i = 0; i < 8; i++) {
		if(checkCoord(arrY[i], arrX[i] )){
		if(board[arrY[i]*8+arrX[i]] != empty && colors == checkColor(board[arrY[i]*8+arrX[i]])) {
			continue;
		}
		else {
			if(newThMap[arrY[i]*8+arrX[i]] == 1) {
				continue;
			}
			else {
			
					lst = cons(y, x, arrY[i], arrX[i], lst);
				} 
			}
		}
    }
	//printList(lst);
	return lst;
}



piece* copyBoard(piece board[64]) {
    piece* newBoard = (piece*)malloc(sizeof(piece)*64);
    for(int y = 0; y < 8; y++) {
		for(int x = 0; x < 8; x++) {
			newBoard[y*8+x] = board[y*8+x];	
		}	
    }
    return newBoard;
}

int valuePiece(piece piecec) {
    switch(piecec) {
	case king:
	    return 6;
	case queen:
	    return 5;
	case knight:
	    return 4;
	case rook:
	    return 3;
	case bishop:
	    return 2;
	case pawn:
	    return 1;
	case KING:
	    return 6;
	case QUEEN:
	    return 5;
	case KNIGHT:
	    return 4;
	case ROOK:
	    return 3;
	case BISHOP:
	    return 2;
	case PAWN:
	    return 1;
    }
    
}

int amountValuePiecec(piece board[64], color colors) {
    int amount = 0;
    for(int y = 0; y < 8; y++) {
		for(int x = 0; x < 8; x++) {
			if(board[y*8+x] != empty && checkColor(board[y*8+x]) == colors) { 
				amount += valuePiece(board[y*8+x]);
			}
		}	
    }
    return amount;
}

//оценка хода 
piece valueMove(piece board[64], int goToY, int goToX, int goFromY, int goFromX, color colors) {
    piece* newBoard = copyBoard(board);
    newBoard[goToY*8 + goToX] = newBoard[goFromY*8+goFromX];
    newBoard[goFromY*8+goFromX] = empty; 
    return amountValuePiecec(newBoard, colors); 
}
//функция берет список всех ходов и находит минимвльно ценный ход

int minValueMove(piece board[64], list* move, color colors) {
    int minValue = valueMove(board, move->goToY, move->goToX, move->goFromY, move->goFromX,flipColor(colors));//добавил flipColors, что бы считать очки противника
    int numberEl = 0;
    int numberMinEl  = 0;
    while(move != NULL) {
    //printList(move);
		if(valueMove(board, move->goToY, move->goToX, move->goFromY, move->goFromX, flipColor(colors)) < minValue) {
			minValue = valueMove(board, move->goToY, move->goToX, move->goFromY, move->goFromX, flipColor(colors));	
			numberMinEl = numberEl;
    	}
    		numberEl++;
		move = move->next;
    }
	return numberMinEl;
}

int countMove(piece board[64], color colors, int depth) {
	int count = 0;
    if(depth == 0) {
	return 1;
    }
    else { 
	list* listMove = allMove(colors, board);
	
	while(listMove != NULL) {
	    piece* newBoard = copyBoard(board);
	    doMove(newBoard, colors, listMove);
	    count += countMove(newBoard, flipColor(colors), depth - 1);
	    listMove = listMove->next;
	    free(newBoard);
	}
	
	delList(listMove);
    }
    return count;
}

//todo проверить мат для короля
//todo погуглить глубину перебора в шахматах и какие вообще существовали в истории
//ханойская башня
/* y=1 x=0
123
456
789

X=3
h=y*X+x
123456789 */


