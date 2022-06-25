#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;43m"
#define WHITE   "\033[1;37m"
#define DEFAULTGR   "\x1b[0m"
#define MAGENTA "\033[35m"     
#define CYAN    "\033[36m" 
#define BLACKBG   "\033[40m" 
#define PRINT "printf"
#define DEPTH 5
//#define CURS "[10;30Н"   

//Белые - вывод заглавными буквами
//Черные строчные буквы вывод


int count_mall = 0;

void* myMalloc(size_t size, int line, const char* func)
{
    

   // printf("вызван malloc из строки %d из функции %s\n", line, func);
    count_mall++;
   // printf("count_ malloc %d\n",count_mall);
    return malloc(size);

}

#define malloc(x) myMalloc(x, __LINE__, __FUNCTION__)

int count_free = 0 ;

void myFree(void* point, int line, const char* func)
{
    

   // printf("вызван free из строки %d из функйии %s\n", line, func);
    count_free++;
   // printf("count_free %d\n",count_free);
    free(point);
}

#define free(x) myFree(x, __LINE__, __FUNCTION__)


typedef struct cell  {
	int isCastlingPossibleBlack;
	int isCastlingPossibleWhite;
	int goToY;//элемент структуры
	int goToX; 
	int goFromY; 
	int goFromX; 
	struct cell* next;//указатель на сл ноду списка
} list;


//cons(13,cons(42,cons(666,NULL))))

list* cons(int isCastlingPossibleWhite, int isCastlingPossibleBlack, int cellFromY,int cellFromX,int cellToY,int cellToX, list *lst) {
    list* newCell = (list*)malloc(sizeof(list));
    (*newCell).goToY = cellToY; //разименование
    newCell->isCastlingPossibleWhite = isCastlingPossibleWhite;
    newCell->isCastlingPossibleBlack = isCastlingPossibleBlack;
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

typedef enum pieces {KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EN_PAWN, king, queen, bishop, knight, rook, pawn, en_pawn, empty} piece;


typedef struct board {
	piece* board;
	int isCastlingPossibleBlack;
	int isCastlingPossibleWhite;
	struct board* next;
} boards;


boards* consBoard(int isCastlingPossibleWhite, int isCastlingPossibleBlack, boards* lst, piece board[64]) {
    
    boards* newCell = (boards*)malloc(sizeof(boards));
    newCell->board = board;
    newCell->next = lst;
    newCell->isCastlingPossibleWhite = isCastlingPossibleWhite;
    newCell->isCastlingPossibleBlack = isCastlingPossibleBlack;
    return newCell;
}
		      //0     1
typedef enum colors {white, black} color;
//прототипы
void printThrMap(int threatMap[64]);
void threatKnight(int y, int x, int threatMap[y*8+x], piece board[64]);
void printBord(piece board[64]);
void threatKing(int y, int x, int threatMap[64], piece board[64]);
void threatRook(int y, int x, int threatMap[64], piece board[64]);
void threatBishop(int y, int x, int threatMap[64], piece board[64]);
void threatQueen(int y, int x, int threatMap[64], piece board[64]);
void threatWitePawn(int y, int x, int threatMap[64], piece board[64]);
void threatBlackPawn(int y, int x, int threatMap[64], piece board[64]);
int checkCoord(int coordY, int coordX);
void pointEmpty(int y, int x, int threatMap[64]);
list* moveKing(int y, int x, piece board[64],  int isCastlingPossibleWhite, int isCastlingPossibleBlack);
list* moveKnight(int y, int x, piece board[64], int isCastlingPossibleWhite, int isCastlingPossibleBlack);
list* moveRook(int y, int x, piece board[64], int isCastlingPossibleWhite,  int isCastlingPossibleBlack);
list* moveBishop(int y, int x, piece board[64], int isCastlingPossibleWhite,  int isCastlingPossibleBlack);
list* moveQueen(int y, int x, piece board[64], int isCastlingPossibleWhite,  int isCastlingPossibleBlack) ;
boards* moveWhitePawn(int y, int x, piece board[64],int isCastlingPossibleWhite,int  isCastlingPossibleBlack);
boards* moveBlackPawn(int y, int x, piece board[64], int isCastlingPossibleWhite, int isCastlingPossibleBlack);
void printMove(piece board[64], list* move);
int findMove(int y , int x, list* move);
void switchBoard(int y,int x,piece board[64]);
void delList(list* lst);
int countEl(list* lst);
list* returnEl(list* lst, int numbEl);
void doMove(piece board[64], list* lst);
int amountValuePiecec(piece board[64], color colors);
int minValueMove(piece board[64], list* move, color colors);
piece valueMove(piece board[64], int goToY, int goToX, int goFromY, int goFromX, color colors);
void checkKing(int* y, int* x, color colors, piece board[64]);
piece* copyBoard(piece board[64]);
int checkCheck(piece board[64], color colors);
piece returnRandPiece(piece board[64], color colors);
boards* pawnCheckEnemyWhite(int y, int x, piece board[64],  int isCastlingPossibleWhite,  int isCastlingPossibleBlack);
boards* pawnCheckEnemyBlack(int y, int x, piece board[64],  int isCastlingPossibleWhite,  int isCastlingPossibleBlack);
int returnValueThMap(int y, int x, color colors, piece board[64]);
list* doMoveKingColor(int y, int x,piece board[64],color colors, int isCastlingPossibleWhite, int isCastlingPossibleBlack);
int countMove(piece board[64], color colors, int depth, int isCastlingPossibleWhite, int isCastlingPossibleBlack);
boards* castling(piece board[64], color colors, int isCastlingPossibleWhite, int isCastlingPossibleBlack);
void checkRook(int* y2, int* x2, color colors, piece board[64]);
boards* move2boards(list* move, piece board[64]);
boards* appendBoard(boards* board1, boards* board2);
int checkEnPassantWhiteLeft(piece board[64]);
int checkEnPassantWhiteRight(piece board[64]);
int checkEnPassantBlackLeft(piece board[64]);
int checkEnPassantBlackRight(piece board[64]);
boards* illegalMoves(boards* move2boards, color colors);
void doMoveCoord(int goFromY, int goFromX, int goToY, int goToX, piece board[64]);
boards* copyLstBoard(boards* lstBoard);
void delBoard(boards* board);
void delCellBoards(boards* board);
boards* doMoveConsBoard(boards* lst,  int isCastlingPossibleWhite,  int isCastlingPossibleBlack, int y,int  x, int yChange, int xChange, piece board[64]);
boards* returnBoard(boards* board, int numbBoard);
void playerInput(char* y, piece board[64],int  isCastlingPossibleWhite, int isCastligPossibleBlack);
int findBoardinLst(boards* lstBoard, piece board[64]);
int comparisonBoards(piece board1[64], piece board2[64]);


void printBoardList(boards* board) {
    while(board != NULL) {
	printBord(board->board);
	board = board->next;
    }
}
color checkColor(piece pieces) {
	//printf("piecec1: %d\n",pieces);
    piece blackPiece[7] = {rook, knight, bishop, king, queen, pawn, en_pawn};
    piece whitePiece[7] = {ROOK, KNIGHT, BISHOP, KING, QUEEN, PAWN, EN_PAWN};

    for(int i = 0; i < 7; i++) {
		if(whitePiece[i] == pieces) {
			return white;
		}
		else if(blackPiece[i] == pieces) {
			return black;
		} 
		
    }
    //if(pieces == empty) {
	printf("error, value piece: %s\n", "");	
	//return printf("error, value piece: %d\n",pieces);
    //}
}

color myCheckColor(piece pieces, int line, const char* func)
{
    printf("вызван checkColor из строки %d из функйии %s\n", line, func);
    return checkColor(pieces);
}

//#define checkColor(x) myCheckColor(x, __LINE__, __FUNCTION__)

int comparPiece(piece piece1, piece piece2){
    piece blackPiece[6] = {rook, knight, bishop, king, queen, pawn};
    piece whitePiece[6] = {ROOK, KNIGHT, BISHOP, KING, QUEEN, PAWN};
    for(int i = 0; i < 6; i++) {
		if(piece1 == blackPiece[i] && piece2 == whitePiece[i] 
		|| piece1 == whitePiece[i] && piece2 == blackPiece[i]
		||  piece1 == piece2){
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


boards* allMove(color colors, piece board[64],int isCastlingPossibleWhite, int  isCastlingPossibleBlack) {
    boards* amountLst = NULL;
    for(int y = 0; y < 8; y++){
		for(int x = 0; x < 8; x++) {
		 	  if(board[y*8+x] != empty && checkColor(board[y*8+x]) == colors){
				if(board[y*8+x] == king || board[y*8+x] == KING) {
					amountLst = appendBoard(move2boards( moveKing(y,x, board, isCastlingPossibleWhite,  isCastlingPossibleBlack), board), amountLst);
				}
				else if(board[y*8+x] == queen || board[y*8+x] == QUEEN) {
				    	amountLst = appendBoard(move2boards( moveQueen(y,x, board, isCastlingPossibleWhite,  isCastlingPossibleBlack), board), amountLst);
				}
				else if(board[y*8+x] == bishop || board[y*8+x] == BISHOP) {
					amountLst = appendBoard(move2boards( moveBishop(y,x, board, isCastlingPossibleWhite,  isCastlingPossibleBlack), board), amountLst);
				}
				else if(board[y*8+x] == knight || board[y*8+x] == KNIGHT) {
				    	amountLst = appendBoard(move2boards( moveKnight(y,x, board, isCastlingPossibleWhite,  isCastlingPossibleBlack), board), amountLst);
				}
				else if(board[y*8+x] == rook || board[y*8+x] == ROOK) {
					amountLst = appendBoard(move2boards( moveRook(y,x, board, isCastlingPossibleWhite,  isCastlingPossibleBlack), board), amountLst);
				}
				else if(board[y*8+x] == PAWN || board[y*8+x] == EN_PAWN) {
					amountLst = appendBoard(amountLst, moveWhitePawn(y,x, board, isCastlingPossibleWhite,  isCastlingPossibleBlack));
				}
				else if(board[y*8+x] == pawn || board[y*8+x] == en_pawn){
					amountLst = appendBoard(amountLst, moveBlackPawn(y,x, board, isCastlingPossibleWhite,  isCastlingPossibleBlack));
				}  
				
 			} 
		}
	}
	
    boards* amountBoards = illegalMoves(appendBoard(castling(board, colors, isCastlingPossibleWhite, isCastlingPossibleBlack), amountLst), colors);
    //delCellBoards(amountLst);
	
    return amountBoards;	
}

boards* move2boards(list* move, piece board[64]) {
    boards* amountBoards = NULL;
    list* tempP = move;
    while(move != NULL) {
	piece* newBoard = copyBoard(board);
	doMove(newBoard, move);
	amountBoards = consBoard(move->isCastlingPossibleWhite, move->isCastlingPossibleBlack, amountBoards, newBoard);
	move = move->next;
    }
    delList(tempP);
    return amountBoards;
}

boards* appendBoard(boards* board1, boards* board2) {
    if(board1 == NULL) return board2;
	boards* p1 = board1;
	while(p1->next != NULL) {
	    p1 = p1->next;		
	}
	p1->next = board2;
    return board1;
} 


int*  allThreatMap(color colors, piece board[64]) {
    int* newThMap = malloc(sizeof(int)*64); // malloc returnS pointer, malloc возвращвет указатель   I hop. He hopS. She hopS. We hop. It hopS.
	for(int i = 0; i < 64; i++) {
	    newThMap[i] = 0;
	}
	for(int y = 0; y < 8; y++){
		for(int x = 0; x < 8; x++) {
		    if(board[y*8+x] != empty) {
		 	  if(checkColor(board[y*8+x]) == colors) {
				if(comparPiece(board[y*8+x], KING)) {
					threatKing(y,x, newThMap, board);
				}
				else if(comparPiece(board[y*8+x], QUEEN)) {
					threatQueen(y,x, newThMap, board);
				}
				else if(comparPiece(board[y*8+x], BISHOP)) {
					threatBishop(y,x, newThMap, board);
				}
				else if(comparPiece(board[y*8+x], KNIGHT)) {
					threatKnight(y,x, newThMap, board);
				}
				else if(comparPiece(board[y*8+x], ROOK)) {
					threatRook(y,x, newThMap, board);
				}
				else if(board[y*8+x] == PAWN) {
					threatWitePawn(y,x, newThMap, board);
				}
				else if(board[y*8+x] == pawn){
					threatBlackPawn(y,x, newThMap, board);
				} 
			}
		    } 
		}
		
	}
	return newThMap;
}


 int main() {
       piece board[64] = {
	rook, knight, bishop, queen, king, bishop, knight, rook,
	pawn, pawn, pawn, pawn, pawn, pawn, pawn, pawn,
	empty,empty, empty, empty, empty, empty, empty, empty,
	empty,empty, empty, empty, empty, empty, empty, empty,
	empty,empty, empty, empty, empty, empty, empty, empty,
	empty,empty, empty, empty, empty, empty, empty, empty,
	PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
	ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK,	
} ;

/* piece board[64] = {
	empty, empty, empty, empty, king, empty, empty, empty,
	empty, empty, empty, empty, empty, empty, empty, empty,
	empty,empty, empty, empty, empty, empty, empty, empty,
	empty,empty, empty, empty, empty, empty, empty, empty,
	empty,empty, empty, empty, pawn, empty, empty, empty,
	empty,empty, empty, empty, empty, empty, empty, empty,
	empty, empty, empty, empty, empty, PAWN, empty, empty,
	empty, empty, empty, empty, KING, empty, empty, empty,	
}; 
 */
	//printf("%d",checkEnPassantWhite(board));
   //printBoardList(castling(board, black));
    
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
	//printf("%d\n", comparPiece(king, QUEEN));
	//printBord(copyBoard(board));
	//printList(pawnChekEnemyWhite(6,3,board));//TODO уравноыесить символы сделав после каждого пробьел добавить на доску номера и буквы
	int isCastlingPossibleWhite;
	int isCastlingPossibleBlack;
	playerInput("b2 c2", board, isCastlingPossibleWhite, isCastlingPossibleBlack);
	printBord(board);
/* 	int x,y;
	
	checkKing(&x, &y, black);
	printf("x: %d\n y: %d\n ", x , y);
 */	
	//printf("%d",returnValueThMap(5,3,black));
//checkMate(board, white);
//printList(doMoveKingColor(0, 3, board, black));
//int isCastlingPossibleWhite = cell->isCastlingPossibleWhite;
/* printf("checkEnPassantBlackLeft: %d\n", checkEnPassantBlackLeft(board));
printf("checkEnPassantBlackRight: %d\n", checkEnPassantBlackRight(board));
printf("checkEnPassantWhiteLeft: %d\n", checkEnPassantWhiteLeft(board));
printf("checkEnPassantWhiteRight: %d\n", checkEnPassantWhiteRight(board));
 */
 
int whiteBl = white; 
 	  while(1) {
		list* lst = NULL;
		
 	    whiteBl = flipColor(whiteBl);
		printf("wb: %d , \n", whiteBl);
 		//printf("minVal: %d\n",minValueMove(board, allMove(whiteBl, board, isCastlingPossibleWhite, isCastlingPossibleBlack), whiteBl));
		 if(checkCheck(board, white)){
		    break;
		}
		if(checkCheck(board, black)){
		    break;
		}
		
	returnBoard(allMove(whiteBl, board,  isCastlingPossibleWhite, isCastlingPossibleBlack), minValueMove(board, allMove(whiteBl, board,  isCastlingPossibleWhite, isCastlingPossibleBlack), whiteBl));

		printBoardList(allMove(whiteBl, board, isCastlingPossibleWhite,isCastlingPossibleBlack));
		//printList(moveKing(whiteBl, board));
		
		
		getchar(); 
	    
	}   
	  for(int depth = 1; depth < 5; depth++) {
	    printf("numb: %d countMove: %d\n", depth, countMove(board, white, depth, 1, 1));
	}  
 	printf("count_free %d\n",count_free);
	printf("count_ malloc %d\n",count_mall);
	
 	//doMove(board, white, returnEl(allMove(white, board), minValueMove(board, allMove(white, board), white)));
  //doMove(board, black, returnEl(allMove(black, board), minValueMove(board, allMove(black, board), black)));
  //doMove(board, white, returnEl(allMove(white, board), minValueMove(board, allMove(white, board), white)));
  //todo побитовые операции
   return 0;
}

//a3 b4

//0 2 1 3

void playerInput(char* y, piece board[64],int  isCastlingPossibleWhite, int isCastligPossibleBlack){
	printBord(board);
    char coord[10000];
    printf("введите ваш ход в формате а1 b2: ");
    fgets(coord, 10000, stdin); 
   	printf("coord: %s\n", coord);
   
	int x = coord[1];
    int goFromCoord = (coord[0] - 97) * 8 + x - 48 - 1;
	printf("goFromCoord: %d\n", goFromCoord);
	x = coord[4];
    int goToCoord = (coord[3] - 97) *8 + x - 48 - 1; //TODO разложить goToCoord and From на Х и У
    printf("goToCoord: %d\n", goToCoord);
	int tempPiece = board[goFromCoord];
	int colorPiece = checkColor(board[goFromCoord]);
	if(goFromCoord >= 64 || goFromCoord < 0 &&  goToCoord >= 64 || goToCoord < 0){
		printf("введенные координаты отсуствуют на доске\n");
	}
	else if(board[goFromCoord] != empty && board[goToCoord] != empty && colorPiece == checkColor(board[goToCoord])) {

		printf("данная клетка занята фигурой того же цвета\n");
	}
	else if (board[goToCoord] == king || board[goToCoord] == KING) {
		printf("срубить короля невозможно\n");
	}
	else if(board[goFromCoord] == empty) {
		printf("нет фигуры в выбраной клетке\n");
	}
	piece* newBoard = copyBoard(board);
	newBoard[goFromCoord] = empty;
    	newBoard[goToCoord] = tempPiece;
    	/*printf("illegal: \n");
    	printBoardList(illegalMoves(allMove(checkColor(board[goFromCoord]), 
	board, isCastlingPossibleWhite, isCastligPossibleBlack), checkColor(board[goFromCoord])));
	printf("\n");*/
	if(!findBoardinLst(illegalMoves(allMove(checkColor(board[goFromCoord]), 
	board, isCastlingPossibleWhite, isCastligPossibleBlack), checkColor(board[goFromCoord])), newBoard)){
	    	printf("данный ход невозможен\n");
	} 
	else {
    	    board[goFromCoord] = empty;
    	    board[goToCoord] = tempPiece;
	}
	printf("if enough\n");
}

int findBoardinLst(boards* lstBoard, piece board[64]){
    while(lstBoard != NULL) {
	if(comparisonBoards(lstBoard->board, board)){
	    return 1;
	}
	lstBoard = lstBoard->next;
    }
    return 0;
}

int comparisonBoards(piece board1[64], piece board2[64]){
    for(int i = 0; i < 64; i++) {
	if(board1[i] == en_pawn && board2[i] == pawn) {
	    continue;
	}
	if(board1[i] == EN_PAWN && board2[i] == PAWN) {
	    continue;
	}
	if(board1[i] != board2[i]) {
	    return 0; 
	}
    }
    return 1;
}

void printBord(piece board[64]) {
	printf("\n");
	printf("  ");
	char chars[32]; 
 	for(int i=97, n=0; i<=104; ++i, ++n){
        chars[n] = (char) i; // (char) приводит код к символу
    }
	for (int i = 1; i < 9; i++){
			printf(" %d ", i);
		}
		printf("\n");
    for(int y = 0; y < 8; y++) {
		
		printf(" %c", chars[y]);
		
		
		for(int x = 0; x < 8; x++) {
			
			switchBoard(y,x,board);
		}
			printf("\n");
	}   
		printf("\n");
}

void threatKnight(int y, int x, int threatMap[64], piece board[64]) {
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

void threatKing(int y, int x, int threatMap[64], piece board[64]) {
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
void threatRook(int y, int x, int threatMap[64], piece board[64]) {
	int arrY[] = {1, 0, 0, -1};
	int arrX[] = {0, -1, 1, 0};
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

//true && true -> true
//true && false -> false
//false && false -> false
//false && true -> false

// true || true -> true
// true || false -> true
// false || false -> false
// false || true -> true

void threatBishop(int y, int x, int threatMap[64], piece board[64]) {
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

void threatQueen(int y, int x, int threatMap[64], piece board[64]) {
	threatRook(y, x, threatMap, board);
	threatBishop(y, x, threatMap, board);
}

void threatWitePawn(int y, int x, int threatMap[64], piece board[64]) {	
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

void threatBlackPawn(int y, int x, int threatMap[64], piece board[64]) {
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

list* moveKing(int y, int x, piece board[64],  int isCastlingPossibleWhite, int isCastlingPossibleBlack) {
    int* newThMap = allThreatMap(flipColor(checkColor(board[y*8+x])), board);
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
				if(checkColor(board[arrY[i]*8+arrX[i]] == white)) {
					isCastlingPossibleWhite = 0;
				}
				else if(checkColor(board[arrY[i]*8+arrX[i]] == black)) {
					isCastlingPossibleBlack = 0;
				}
					
					lst = cons(isCastlingPossibleWhite, isCastlingPossibleBlack, y, x, arrY[i], arrX[i], lst);
				}
			}
		}
    }
	free(newThMap);
	//printList(lst);
	return lst;
}

list* moveKnight(int y, int x, piece board[64], int isCastlingPossibleWhite, int isCastlingPossibleBlack) {
	list* lst = NULL;
	int arrY[] = {y + 2, y + 1, y - 1, y - 2,y - 2, y - 1, y + 1, y + 2};
	int arrX[] = {x + 1, x + 2, x + 2, x + 1, x - 1, x - 2, x - 2, x - 1};
	for(int i = 0; i < 8; i++) {
	    if(checkCoord(arrY[i], arrX[i])) {
	        if(board[arrY[i]*8+arrX[i]] == empty){
	             lst = cons(isCastlingPossibleWhite,  isCastlingPossibleBlack, y, x, arrY[i], arrX[i], lst);
	        } 
		else if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) != checkColor(board[arrY[i]*8+arrX[i]])) {
			lst = cons(isCastlingPossibleWhite,  isCastlingPossibleBlack, y, x, arrY[i], arrX[i], lst);
			}
		}
	}
	return lst;
}
list* moveRook(int y, int x, piece board[64], int isCastlingPossibleWhite,  int isCastlingPossibleBlack) {
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

				if(checkColor(board[y*8+x] == white)) {
					isCastlingPossibleWhite = 0;
				}
				else if(checkColor(board[y*8+x] == black)) {
					isCastlingPossibleBlack = 0;
				}
				lst = cons(isCastlingPossibleWhite, isCastlingPossibleBlack, y, x, yChange, xChange, lst);
				yChange += arrY[i];
				xChange += arrX[i];
				break;
			}
			if(checkColor(board[y*8+x] == white)) {
				isCastlingPossibleWhite = 0;
			}
			else if(checkColor(board[y*8+x] == black)) {
				isCastlingPossibleBlack = 0;
			}
			lst = cons(isCastlingPossibleWhite, isCastlingPossibleBlack, y, x, yChange, xChange, lst);
			yChange += arrY[i];
			xChange += arrX[i];
		}
	}
	return lst;
}

list* moveBishop(int y, int x, piece board[64], int isCastlingPossibleWhite,  int isCastlingPossibleBlack) {
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
				lst = cons(isCastlingPossibleWhite,  isCastlingPossibleBlack, y, x, yChange, xChange, lst);
				yChange += arrY[i];
				xChange += arrX[i];
				break;
			}
			lst = cons(isCastlingPossibleWhite,  isCastlingPossibleBlack, y, x, yChange, xChange, lst);
			yChange += arrY[i];
			xChange += arrX[i];
		}
	}
	return lst;
}

list* moveQueen(int y, int x, piece board[64], int isCastlingPossibleWhite,  int isCastlingPossibleBlack) {
	return append(moveRook(y,x, board, isCastlingPossibleWhite,  isCastlingPossibleBlack), moveBishop(y,x,board, isCastlingPossibleWhite,  isCastlingPossibleBlack));
}

boards* doMoveConsBoard(boards* lst,  int isCastlingPossibleWhite,  int isCastlingPossibleBlack, int y,int  x, int yChange, int xChange, piece board[64]) {
    piece* newBoard = copyBoard(board);
    doMoveCoord(y,x, yChange, xChange, newBoard);
    return  consBoard( isCastlingPossibleWhite,  isCastlingPossibleBlack,  lst, newBoard);
}

boards* pawnCheckEnemyWhite(int y, int x, piece board[64], int isCastlingPossibleWhite,  int isCastlingPossibleBlack){
	boards* lst = NULL;
	int arrY[] = {y - 1, y - 1};
	int arrX[] = {x + 1, x - 1};
	for(int i = 0; i < 2; i++){
		if(checkCoord(arrY[i], arrX[i])){
/* 			printf("arrY[i]: %d\n", arrY[i]);
			printf("arrX[i]: %d\n", arrX[i]);
 */
			if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) != checkColor(board[arrY[i]*8+arrX[i]])) {
			    lst = doMoveConsBoard(lst, isCastlingPossibleWhite,  isCastlingPossibleBlack, y, x, arrY[i], arrX[i], board);
			}
		}
		
	}
	//printList(lst);
	return lst;
}

boards* pawnCheckEnemyBlack(int y, int x, piece board[64], int isCastlingPossibleWhite,  int isCastlingPossibleBlack){
	boards* lst = NULL;
	int arrY[] = {y + 1, y + 1};
	int arrX[] = {x + 1, x - 1};
	
	for(int i = 0; i < 2; i++){
		if(checkCoord(arrY[i], arrX[i])){
		    	if(board[arrY[i]*8+arrX[i]] != empty && checkColor(board[y*8+x]) != checkColor(board[arrY[i]*8+arrX[i]])) {
			    lst = doMoveConsBoard(lst, isCastlingPossibleWhite,  isCastlingPossibleBlack, y, x, arrY[i], arrX[i], board);
			}
		}
	}
	//printList(lst);
	return lst;
}

/*if усл:
 ....
elif not усл:
 ....
 
-> 
else:
  .....
*/

void finalizeEnPass(piece board[64]) {
    for(int i = 0; i < 64; i++) {
		if(board[i] == EN_PAWN) {
			board[i] = PAWN;
		}
		else if(board[i] == en_pawn) {
			board[i] = pawn;
		}
    }
}

boards* moveWhitePawn(int y, int x, piece board[64],int isCastlingPossibleWhite,int  isCastlingPossibleBlack) {	
	boards* lst = pawnCheckEnemyWhite(y, x, board, isCastlingPossibleWhite,  isCastlingPossibleBlack);
	//printList(lst);
	if (y != 6) {
		if(checkCoord(y - 1, x) && board[(y - 1) * 8 + x] == empty){
		    //lst = doMoveConsBoard(isCastlingPossibleWhite,  isCastlingPossibleBlack, y, x, y-1, x, board);
		    piece* newBoard = copyBoard(board);
		    doMoveCoord(y,x, y - 1, x, newBoard);
		    if((y - 1) == 0) {
				newBoard[(y-1)*8+x] = QUEEN;
		    }
		    lst = consBoard(isCastlingPossibleWhite, isCastlingPossibleBlack, lst, newBoard);
		    
		}
	}	
	else{
			if(checkCoord(y - 1, x) && board[(y-1) * 8 + x] == empty){
				lst = doMoveConsBoard(lst, isCastlingPossibleWhite,  isCastlingPossibleBlack, y, x, y - 1, x, board);
			
			}
			piece* newBoard2 = copyBoard(board);
			if(checkCoord(y - 1, x) && checkCoord(y - 2, x) && board[(y - 1) * 8 + x] == empty && board[(y - 2) * 8 + x] == empty) {
			
				newBoard2[(y) * 8 + x] = EN_PAWN;
				//newBoard2[y * 8 + x] = empty;
				lst = consBoard(isCastlingPossibleWhite, isCastlingPossibleBlack,lst ,newBoard2);
				lst = doMoveConsBoard(lst, isCastlingPossibleWhite,  isCastlingPossibleBlack, y, x, y + 2, x, board);
			}
				if(checkEnPassantBlackLeft(newBoard2)){
			    newBoard2[y*8+x] = empty;
			    newBoard2[(y-1)*8+x] = pawn;
				newBoard2[(y-2)*8+x+1] = empty;
			}
			if(checkEnPassantBlackRight(newBoard2)){
			    newBoard2[y*8+x] = empty;
			    newBoard2[(y-1)*8+x] = pawn;
				newBoard2[(y-2)*8+x-1] = empty;
			}
		}
	return lst; 
}



boards* moveBlackPawn(int y, int x, piece board[64], int isCastlingPossibleWhite, int isCastlingPossibleBlack) {	
	boards* lst = pawnCheckEnemyBlack( y, x, board,isCastlingPossibleWhite,  isCastlingPossibleBlack);
	if (y != 1) {
		if(checkCoord(y + 1, x) && board[(y + 1) * 8 + x] == empty){
		//lst = doMoveConsBoard(isCastlingPossibleWhite,  isCastlingPossibleBlack, y, x, y+1, x, board);
		    piece* newBoard = copyBoard(board);
		    doMoveCoord(y,x, y + 1, x, newBoard);
		    if((y+1) == 7) {
				newBoard[(y+1)*8+x] = queen;
		    }
			lst = consBoard(isCastlingPossibleWhite, isCastlingPossibleBlack, lst, newBoard); 
		}
	}	
	else {
			if(checkCoord(y + 1, x) && board[(y + 1) * 8 + x] == empty){
				lst = doMoveConsBoard(lst, isCastlingPossibleWhite,  isCastlingPossibleBlack, y, x, y + 1, x, board);
			
			}
			piece* newBoard2 = copyBoard(board);
			if(checkCoord(y + 1, x) && checkCoord(y + 2, x) && board[(y + 1) * 8 + x] == empty && board[(y + 2) * 8 + x] == empty) {			
				newBoard2[(y) * 8 + x] = en_pawn;
				//newBoard2[y * 8 + x] = empty;
				lst = consBoard(isCastlingPossibleWhite, isCastlingPossibleBlack,lst ,newBoard2);
				lst = doMoveConsBoard(lst, isCastlingPossibleWhite,  isCastlingPossibleBlack, y, x, y + 2, x, board);
			}
			if(checkEnPassantWhiteLeft(newBoard2)){
			    newBoard2[y*8+x] = empty;
			    newBoard2[(y+1)*8+x] = PAWN;
				newBoard2[(y+2)*8+x+1] = empty;
			}
			if(checkEnPassantWhiteRight(newBoard2)){
			    newBoard2[(y)*8+x] = empty;
				newBoard2[(y+2)*8+x-1] = empty;
			    newBoard2[(y+1)*8+x] = PAWN;
			}
		}
			
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
			printf("[\u265A]");
			break;
		case queen:
			printf("[\u265B]");
			break;
		case bishop:
			printf("[\u265D]");
			break;
		case knight:
			printf("[\u265E]");
			break;
		case rook:
			printf("[\u265C]");
			break;    
		case pawn:
			printf("[\u265F]");
			break;
		case en_pawn:
			printf("[\u265F]");
			break;     
		case KING:
			printf("[\u2654]");
			break;    
		case QUEEN:
			printf("[\u2655]");
			break;
		case BISHOP:
			printf("[\u2657]");
			break;
		case KNIGHT:
			printf("[\u2658]");
			break;
		case ROOK:
			printf("[\u2656]");
			break;    
		case PAWN:
			printf("[\u2659]");
			break;    
		case EN_PAWN:
			printf("[\u2659]");
			break;    
		case empty:
			printf("[ ]");
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
void delBoard(boards* board) {
    while(board != NULL) {
		boards* tempP = board;
		free(board->board);//удаление указателя на массив (самого массива)
		board = board->next;
		free(tempP);
    }
}

void delCellBoards(boards* board) {
        while(board != NULL) {
		boards* tempP = board;
		board = board->next;
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

boards* returnBoard(boards* board, int numbBoard) {
	int count  = 0;
	while (count != numbBoard) {
		count ++;
		board = board ->next;
	}
	return board;
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

void doMove(piece board[64], list* lst) {
    board[lst->goToY*8 + lst->goToX] = board[lst->goFromY*8+lst->goFromX];
    board[lst->goFromY*8+lst->goFromX] = empty; 
}
void checkKing(int* y, int* x, color colors, piece board[64]) {
    for(int y1 = 0; y1 < 8; y1++) {
		for(int x1 = 0; x1 < 8; x1++) {
		    if(board[y1*8+x1] == king && checkColor(board[y1*8+x1]) == colors || board[y1*8+x1] == KING && checkColor(board[y1*8+x1]) == colors) {
				*y = y1;
				*x = x1;
		    }
		}
    }
}

void checkRook(int* y2, int* x2, color colors, piece board[64]) {
    for(int y1 = 0; y1 < 8; y1++) {
		for(int x1 = 0; x1 < 8; x1++) {
		    if(board[y1*8+x1] == rook && checkColor(board[y1*8+x1]) == colors || board[y1*8+x1] == ROOK && checkColor(board[y1*8+x1]) == colors) {
				*y2 = y1;
				*x2 = x1;
		    }
		}
    }
}



/* 
int checkMate(piece board[64], color colors) {
	int x, y;
	checkKing(&y, &x, colors);
	int* newThMap = allThreatMap(flipColor(colors), board);
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

int returnValueThMap(int y, int x, color colors, piece board[64]) {
	int* newThMap = allThreatMap(flipColor(colors), board);
	if(newThMap[y*8+x] == 1) {
		free(newThMap);
		return 1;
	}
	free(newThMap);
	return 0;
}

int checkCheck(piece board[64], color colors) {//проверка шаха
	int x, y;
	checkKing(&y, &x, colors, board);
	if(returnValueThMap(y,x,colors, board)/*&& doMoveKingColor(y, x, board, colors) == NULL*/){  //когда будет готова логика ухода короля от удара - раскомментировать
		return 1;
	}
	return 0;
}

list* doMoveKingColor(int y, int x,piece board[64],color colors, int isCastlingPossibleWhite, int isCastlingPossibleBlack) {
	int* newThMap = allThreatMap(colors, board);
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
			
					lst = cons(isCastlingPossibleWhite, isCastlingPossibleBlack, y, x, arrY[i], arrX[i], lst);
				} 
			}
		}
    }
	free(newThMap);
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

boards* copyLstBoard(boards* lstBoard) {
    boards* newLstBoard = (boards*)malloc(sizeof(boards));
    while(lstBoard != NULL){
		newLstBoard = appendBoard(lstBoard, newLstBoard);
		lstBoard = lstBoard->next;
	}
    return newLstBoard;
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
	case en_pawn:
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
	case EN_PAWN:
	    return 1;
    }
    printf("%d %s\n",piecec,"error in valuePiece");
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

// I'm loving it!
// I love it.


int miniMax(piece board[64], color colors, int depth, int isCastlingPossibleWhite, int isCastlingPossibleBlack) {
    if(depth == 0) {
	return amountValuePiecec(board, colors);
    }
    else {
	int value = 0;
	int minValue = 10;
	int maxValue = 0;
	boards* lstBoard = allMove(colors, board, isCastlingPossibleWhite, isCastlingPossibleBlack);
	boards* tempP = lstBoard;
	if(colors == white){//comp plays black
	    while(lstBoard != NULL) {
		value = miniMax(lstBoard->board, flipColor(colors), depth - 1, isCastlingPossibleWhite, isCastlingPossibleBlack);
		if(value < minValue){
		    minValue = value;
		}
	    lstBoard = lstBoard->next;
	    return minValue; 
	    //free(newBoard);
	    }
	}
	if(colors == black){
    	    while(lstBoard != NULL) {
	        value = miniMax(lstBoard->board, flipColor(colors), depth - 1, isCastlingPossibleWhite, isCastlingPossibleBlack);
	        if(value > maxValue) {
			maxValue = value;
	        }
	        lstBoard = lstBoard->next;
	        return maxValue;
	    }
	}
	delBoard(tempP);
    }
}

int miniMaxValueMove(boards* lstBoards, color colors) {
    int minValue = -1;//добавил flipColors, что бы считать очки противника
    int numberEl = 0;
    int numberMinEl  = 0;
    boards* tempP = lstBoards;
    while(lstBoards != NULL) {
    //printList(move);
    int minMaxVar = miniMax(lstBoards->board, colors, DEPTH, lstBoards->isCastlingPossibleWhite, lstBoards->isCastlingPossibleBlack);
		if(minMaxVar < minValue) {
			minValue = minMaxVar;	//TODO видео про минимакс
			numberMinEl = numberEl;
    	}
    		numberEl++;
		lstBoards = lstBoards->next;
    }
	//delBoard(tempP);
	return numberMinEl;
}



//оценка хода 
piece valueMove(piece board[64], int goToY, int goToX, int goFromY, int goFromX, color colors) {
    piece* newBoard = copyBoard(board);
    newBoard[goToY*8 + goToX] = newBoard[goFromY*8+goFromX];
    newBoard[goFromY*8+goFromX] = empty; 
    return amountValuePiecec(newBoard, colors); 
}
//функция берет список всех ходов и находит минимально ценный ход

int minValueMove(piece board[64], list* move, color colors) {
    int minValue = valueMove(board, move->goToY, move->goToX, move->goFromY, move->goFromX, flipColor(colors));//добавил flipColors, что бы считать очки противника
    int numberEl = 0;
    int numberMinEl  = 0;
	list* tempP = move;
    while(move != NULL) {
    //printList(move);
		if(valueMove(board, move->goToY, move->goToX, move->goFromY, move->goFromX, flipColor(colors)) < minValue) {
			minValue = valueMove(board, move->goToY, move->goToX, move->goFromY, move->goFromX, flipColor(colors));	
			numberMinEl = numberEl;
    	}
    		numberEl++;
		move = move->next;
    }
	delList(tempP);
	return numberMinEl;
}



int countMove(piece board[64], color colors, int depth, int isCastlingPossibleWhite, int isCastlingPossibleBlack) {
    if(depth == 0) {
	return 1;
    }
    else { 
	int count = 0;
	boards* lstBoard = allMove(colors, board, isCastlingPossibleWhite, isCastlingPossibleBlack);
	boards* tempP = lstBoard;
	while(lstBoard != NULL) {	
	    count += countMove(lstBoard->board, flipColor(colors), depth - 1, isCastlingPossibleWhite, isCastlingPossibleBlack);
	    lstBoard = lstBoard->next;
	    //free(newBoard);
	}
	delBoard(tempP);
	return count; 
    }
    
}

void doMoveCoord(int goFromY, int goFromX, int goToY, int goToX, piece board[64]) {
    board[goToY*8+goToX] = board[goFromY*8+goFromX];
    board[goFromY*8+goFromX] = empty;
    
}

int checkEnPassantWhiteLeft(piece board[64]) { //рубят белые
		for(int x = 0; x < 8; x++) {
			if(checkCoord(1, x - 1)){
				if(board[3 * 8 + x] == PAWN && board[1 * 8 + x - 1] == en_pawn)  {
						return 1;
				}
			}
		}
		return 0;
	}

	int checkEnPassantWhiteRight(piece board[64]){ //рубят белые
		for(int x = 0; x < 8; x++) {
			if(checkCoord(1, x + 1)){
				if(board[3 * 8 + x] == PAWN && board[1 * 8 + x + 1] == en_pawn)  {
						return 1;
				}
			}
		}
		return 0;
	}

	int checkEnPassantBlackLeft(piece board[64]) {//рубят черные
		for(int x = 0; x < 8; x++) {
			if(checkCoord(6, x - 1)){
				if(board[4 * 8 + x] == pawn && board[6  * 8 + x - 1] == EN_PAWN)  {
						return 1;
				}
			}
		}
		return 0;
	}

	int checkEnPassantBlackRight(piece board[64]) {//рубят черные
		for(int x = 0; x < 8; x++) {
			if(checkCoord(6, x + 1)&&checkCoord(6, x - 1)){
				if(board[4 * 8 + x] == pawn && board[6 * 8 + x + 1] == EN_PAWN)  {
						return 1;
				}
			}
		}
		return 0;
	}


/*boards* enPassantBoards(piece board[64], color colors, int x, int y) {
	boards* lstBoards = NULL;
	int isEnpassantPossibleWhite;//пока не в структуре
	int isEnpassantPossibleBlack;
	if(isEnpassantPossibleWhite == 1) {//for white en passant
		if(1) {
			piece* newBoard = copyBoard(board);
			doMoveCoord(y, x, y+2, 2, newBoard);//move black
			doMoveCoord(0, 0, 0, 3, newBoard);// move white
			lstBoards = consBoard(isEnpassantPossibleWhite, 0, lstBoards, newBoard);
		}
	}
}
*/


boards* castling(piece board[64], color colors, int isCastlingPossibleWhite, int isCastlingPossibleBlack){
	boards* lstBoards = NULL;
	if(!checkCheck(board, black) && isCastlingPossibleBlack == 1) {
		if(board[1] == empty && board[2] == empty && board[3] == empty && board[0] == rook && board[4] == king ) {//left black
			piece* newBoard = copyBoard(board);
			doMoveCoord(0, 4, 0, 2, newBoard);//move king
			doMoveCoord(0, 0, 0, 3, newBoard);// move rook
			lstBoards = consBoard(isCastlingPossibleWhite, 0, lstBoards, newBoard);
		}
		if(board[5] == empty && board[6] == empty && board[7] == rook && board[4] == king) {//right blaCK
			piece* newBoard = copyBoard(board);
			doMoveCoord(0, 4, 0, 6, newBoard);
			doMoveCoord(0, 7, 0, 5, newBoard);
			lstBoards = consBoard(isCastlingPossibleWhite, 0, lstBoards, newBoard);
		}
	} 
	else {
		return lstBoards;
	}
	if(!checkCheck(board, white) && isCastlingPossibleBlack == 1) {

		if(board[57] == empty && board[58] == empty && board[59] == empty && board[56] == ROOK && board[60] == KING) { //left white
		    piece* newBoard = copyBoard(board);
		    doMoveCoord(7, 4, 7, 2, newBoard);
			doMoveCoord(7, 0, 7, 3, newBoard);
			lstBoards = consBoard(isCastlingPossibleWhite, isCastlingPossibleBlack, lstBoards, newBoard);
		}
		if(board[61] == empty && board[62] == empty && board[63] == ROOK && board[60] == KING) { //right white
		    piece* newBoard = copyBoard(board);
			doMoveCoord(7, 4, 7, 6, newBoard);
			doMoveCoord(7, 7, 7, 5, newBoard);
			lstBoards = consBoard(isCastlingPossibleWhite, isCastlingPossibleBlack, lstBoards, newBoard);
		} 
		
	}
	else {
		return lstBoards;
	}

		return lstBoards;
}

boards* illegalMoves(boards* lstBoard, color colors) {//TODO унифицировать расположение isCastlingWhite и black 
    boards* newLstBoard = NULL;
    boards* tempP = lstBoard;

    int x = 0;
    int y = 0;
    while(lstBoard != NULL) {
	checkKing(&y, &x, colors, lstBoard->board);
	int* threatMap  = allThreatMap(flipColor(colors), lstBoard->board);
	finalizeEnPass(lstBoard->board);
	if(threatMap[y*8+x] == 0) {
	    newLstBoard = consBoard(lstBoard->isCastlingPossibleWhite, lstBoard->isCastlingPossibleBlack, newLstBoard, lstBoard->board);
	}
	else {
	    free(lstBoard->board);
	}
	 lstBoard = lstBoard->next;
	 free(threatMap);
    }
    delCellBoards(tempP);
    return newLstBoard;
}

//ханойская башня
/* y=1 x=0
123
456
789

X=3
h=y*X+x
123456789 */


