#include <stdio.h>

//Белые - вывод заглавными буквами
//Черные строчные буквы вывод
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
			printf("piecesWhite: %d\t", pieces);
			printf("i: %d\t", i);
			printf("whitePiece[i]: %d\n", whitePiece[i]);
			return white;
		}
		else if(blackPiece[i] == pieces) {
			printf("piecesBlack: %d\t", pieces);
			printf("i: %d\t", i);
			printf("blackPiece[i]: %d\n", whitePiece[i]);

			return black;
		}
    }
	
    return printf("error, value piece: %d\n",pieces);
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

void allThereMap(color colors) {
	for(int y = 0; y < 8; y++){
		for(int x = 0; x < 8; x++) {
			if(checkColor(bord[y][x]) == colors) {
				if(bord[y][x] == king || bord[y][x] == KING) {
					threatKing(y,x, threatMap);
				}
			}
			if(checkColor(bord[y][x]) == colors) {
				if(bord[y][x] == queen || bord[y][x] == QUEEN) {
					threatKing(y,x, threatMap);
				}
			}
			if(checkColor(bord[y][x]) == colors) {
				if(bord[y][x] == bishop || bord[y][x] == BISHOP) {
					threatKing(y,x, threatMap);
				}
			}
			if(checkColor(bord[y][x]) == colors) {
				if(bord[y][x] == knight || bord[y][x] == KNIGHT) {
					threatKing(y,x, threatMap);
				}
			}
			if(checkColor(bord[y][x]) == colors) {
				if(bord[y][x] == rook || bord[y][x] == ROOK) {
					threatKing(y,x, threatMap);
				}
			}
			if(checkColor(bord[y][x]) == colors) {
				if(bord[y][x] == pawn || bord[y][x] == PAWN) {
					threatKing(y,x, threatMap);
				}
			}
		}
	}
}
int main() {
	allThereMap(1);
    //printf("%d",checkColor(pawn));
    //printBord(bord);
	//threatKnight(3,  5,  threatMap);
	//printThrMap(threatMap);
	//threatKing(3,5,threatMap);
	//threatRook(3,5, threatMap);
	//threatBishop(3,5,threatMap);
	//threatQueen(3,5,threatMap);
	//threatWitePawn(4, 2, threatMap);
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
	threatMap[y][x] = 9;
	
	if(y < 6 || x < 7){
		y += 2;
		x += 1;
		threatMap[y][x] = 1;
		y -= 2;
		x -= 1;
    }
	
    if(y < 7 || x < 6){
		y += 1;
		x += 2;
		threatMap[y][x] = 1;
		y -= 1;
		x -= 2;

	}
	
	if(y > 1 || x < 6){
		y -= 1;
		x += 2;
		threatMap[y][x] = 1;
		y += 1;
		x -= 2;
	}
	
	
	if(y > 2 || x < 7){
		y -= 2;
		x += 1;
		threatMap[y][x] = 1;
		y += 2;
		x -= 1;
	}
	
	if(y > 2 || x > 1){
		y -= 2;
		x -= 1;
		threatMap[y][x] = 1;
		y += 2;
		x += 1;
	}	
	
	if(y > 1 || x > 2){
		y -= 1;
		x -= 2;
		threatMap[y][x] = 1;
		y += 1;
		x += 2;
	}
		
	if(y < 7 || x > 2){
		y += 1;
		x -= 2;
		threatMap[y][x] = 1;
		y -= 1;
		x += 2;
	}
	
	if(y < 6 || x > 1){
		y += 2;
		x -= 1;
		threatMap[y][x] = 1;
		y -= 2;
		x += 1;	
	}
	
	printThrMap(threatMap);
}

void threatKing(int y, int x, int threatMap[8][8]) {
	threatMap[y][x] = 9;
	
	if(y < 7 || x < 7){
		y += 1;
		x += 1;
		threatMap[y][x] = 1;
		y -= 1;
		x -= 1;
    }
	
    if(y < 7){
		y += 1;
		threatMap[y][x] = 1;
		y -= 1;
	}
	
	if(y < 7 || x > 1){
		y += 1;
		x -= 1;
		threatMap[y][x] = 1;
		y -= 1;
		x += 1;
	}
	
	
	if(x > 1){
		x -= 1;
		threatMap[y][x] = 1;
		x += 1;
	}
	
	if(y > 1 || x > 1){
		y -= 1;
		x -= 1;
		threatMap[y][x] = 1;
		y += 1;
		x += 1;
	}	
	
	if(y > 1){
		y -= 1;
		threatMap[y][x] = 1;
		y += 1;
	}
		
	if(y > 1 || x < 7){
		y -= 1;
		x += 1;
		threatMap[y][x] = 1;
		y += 1;
		x -= 1;
	}
	
	if(x < 7){
		x += 1;
		threatMap[y][x] = 1;
		x -= 1;	
	}
	
	printThrMap(threatMap);
}

void threatRook(int y, int x, int threatMap[8][8]) {
	threatMap[y][x] = 9;
	int xChange = x;
	int yChange = y;

	while (xChange <= 7)
	{
		xChange++;
		threatMap[y][xChange] = 1;
	}
	xChange = x;
	while (xChange >= 0)
	{
		xChange--;
		threatMap[y][xChange] = 1;
	}
	xChange = x;
	while (yChange <= 7)
	{
		yChange++;
		threatMap[yChange][x] = 1;
	}
	yChange = y;
	while (yChange >= 0)
	{
		yChange--;
		threatMap[yChange][x] = 1;
	}
	yChange = y;
	
	printThrMap(threatMap);
}

void threatBishop(int y, int x, int threatMap[8][8]) {
	threatMap[y][x] = 9;
	int xChange = x;
	int yChange = y;

	while (xChange <= 7 || yChange >= 0)
	{
		xChange++;
		yChange--;
		threatMap[yChange][xChange] = 1;
	}
	xChange = x;
	yChange = y;
	while (xChange <= 7 || yChange <= 7)
	{
		xChange++;
		yChange++;
		threatMap[yChange][xChange] = 1;
	}
	xChange = x;
	yChange = y;
	while (xChange >= 0 || yChange <= 7)
	{
		xChange--;
		yChange++;
		threatMap[yChange][xChange] = 1;
	}
	xChange = x;
	yChange = y;
	while (xChange >= 0 || yChange >= 0)
	{
		xChange--;
		yChange--;
		threatMap[yChange][xChange] = 1;
	}
	xChange = x;
	yChange = y;
	
	printThrMap(threatMap);
}

void threatQueen(int y, int x, int threatMap[8][8]) {
	threatMap[y][x] = 9;
	int xChange = x;
	int yChange = y;

	while (xChange <= 7 || yChange >= 0)
	{
		xChange++;
		yChange--;
		threatMap[yChange][xChange] = 1;
	}
	xChange = x;
	yChange = y;
	while (xChange <= 7 || yChange <= 7)
	{
		xChange++;
		yChange++;
		threatMap[yChange][xChange] = 1;
	}
	xChange = x;
	yChange = y;
	while (xChange >= 0 || yChange <= 7)
	{
		xChange--;
		yChange++;
		threatMap[yChange][xChange] = 1;
	}
	xChange = x;
	yChange = y;
	while (xChange >= 0 || yChange >= 0)
	{
		xChange--;
		yChange--;
		threatMap[yChange][xChange] = 1;
	}
	xChange = x;
	yChange = y;

	while (xChange <= 7)
	{
		xChange++;
		threatMap[y][xChange] = 1;
	}
	xChange = x;
	while (xChange >= 0)
	{
		xChange--;
		threatMap[y][xChange] = 1;
	}
	xChange = x;
	while (yChange <= 7)
	{
		yChange++;
		threatMap[yChange][x] = 1;
	}
	yChange = y;
	while (yChange >= 0)
	{
		yChange--;
		threatMap[yChange][x] = 1;
	}
	yChange = y;
	
	printThrMap(threatMap);
}

void threatWitePawn(int y, int x, int threatMap[8][8]) {
	threatMap[y][x] = 9;
if (y == 6) {
	for(int n = 0; n < 2; n++) {
			y --;
		if(checkCoord(y, x)) {
			threatMap[y][x] = 1;
		}
	}
} else {
	    if(checkCoord(y, x)) {
		y--;
		threatMap[y][x] = 1;
	}
}
	printThrMap(threatMap);

}

void threatBlackPawn(int y, int x, int threatMap[8][8]) {
	threatMap[y][x] = 9;
if (y == 1) {
	for(int n = 0; n < 2; n++) {
		y ++;
		if(checkCoord(y, x)) {	
			threatMap[y][x] = 1;
		}
	}
} else {
	y++;
	if(checkCoord(y, x)) {
	    threatMap[y][x] = 1;
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

