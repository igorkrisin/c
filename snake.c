#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
    
    int app_x;
    int app_y;
    int size_wh;
    int size_wv;
    int* coord_x;
    int* coord_y;
    int bar=0;
    int begining;
    int x = 0;
    int y = 0;
    int size_sn;
    int napr_x;
    int napr_y;
    int speed;

void gen_app(size_wh, size_wv){
    app_x = rand()%size_wv;
    app_y = rand()%size_wh;
}

//               bar
//               v            
/*..|1 7 9 4 8 2 0 0 0 0 0 0...
     ^
     begining
  
             ^*/
        
// O(n)             
void add_arr(int x, int y){
    
//	begining--;
	if (--begining<0) {
	    begining = size_sn-1;
	}
	coord_x[begining] = x;
	coord_y[begining] = y;
	
	
}

// O(1)
void del_arr(){
//    bar--;
    if (--bar<0)
	bar = size_sn -1;
    }
    
    
/* 0  0 3 4 6 1 0 0 0 0
      ^     ^
      beg   bar
      
 0 0 3 4 6 1 7 9 0 0
     ^         ^
     bar       beg
  */
void print_sn(){
    if (begining>bar){
	for (int i = begining; i < size_sn; i++){
	    mvaddstr(coord_y[i], coord_x[i],"s");
	}
	for (int i = 0; i < bar ; i++){
	    mvaddstr(coord_y[i], coord_x[i],"s");
	}
    }
    else {
    for(int i = begining; i<bar; i++){
	mvaddstr(coord_y[i],coord_x[i],"s");
	}
    }
	
}   



int crash_sn(int y ,int x){
    if (begining>bar){
	for(int i = begining; i < size_sn-1; i++){
    	    if (y == coord_y[i] && x ==coord_x[i]){
		return 0;    	    
    	    }
        }
        for (int i = 0; i<bar - 1; i++) {
    	    if (y == coord_y[i] && x == coord_x[i]){
    		return 0; 
    	    }
	}
	
    }
    else{
	for(int i = begining; i<bar; i++){
	    if(y == coord_y[i]&&x == coord_x[i])
		return 0;
	}
    }
   return 1;
	
    
    
    }
int main(){
srand(time(NULL));
initscr();
noecho();    
getmaxyx(stdscr, size_wh, size_wv);
speed = 5;
halfdelay(speed);
gen_app(size_wh, size_wv);
size_sn = 20; //size_wv*size_wh;
coord_x = malloc(size_sn*sizeof(int));
coord_y = malloc(size_sn*sizeof(int));
napr_x = 1;
napr_y = 0;
add_arr(x,y);
while(1){
    

    int key = getch();
    erase();
    
    

    if(key == 'w'){
	napr_y = -1;
    napr_x = 0;
	}
    else if(key == 's'){
	napr_y = 1;
    napr_x = 0;
	}
    else if(key == 'd'){
	napr_y = 0;
    napr_x = 1;
	}
    else if(key == 'a'){
	napr_y = 0;
    napr_x = -1;
	}
    else if(key == 'q'){
        return 0;
    }

    x = napr_x+x;
    y = napr_y+y;
    
    if(y < 0){
        y = size_wh-1;
    }
    else if(y >= size_wh){
        y = 0;
    }
    if(x < 0){
        x = size_wv-1;
    }
    else if(x >= size_wv){
        x = 0;
    }
    if(!crash_sn(y,x)){
        return 1;
    }
    add_arr(x,y);

    if (y==app_y && x == app_x){
        gen_app(size_wh, size_wv);
        speed++;  
    }
    else {
	    del_arr();
	}

    print_sn();
    
    mvaddstr(app_y, app_x, "a");
    
}



endwin();

}