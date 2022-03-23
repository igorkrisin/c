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
    int x = 0;
    int y = 0;

void gen_app(size_wh, size_wv){
    app_x = rand()%size_wv;
    app_y = rand()%size_wh;
}


/*1  1 1 1 1 2 0 0 0 0 0 0
  
             ^*/
             
void add_arr(int x, int y){
    for (int i=bar-1; i>=0; i--){
	coord_x[i] = coord_x[i-1];
	coord_y[i] = coord_y[i-1];
	}
    coord_x[0] = x;
    coord_y[0] = y;
    bar++;
}

void del_arr(){
    bar--;
    }
    
void print_sn(){
    for(int i = 0; i<bar; i++){
	mvaddstr(coord_y[i],coord_x[i],"s");
    }

}

int crash_sn(y,x){
    for(int i = 1; i < bar; i++){
        if (y == coord_y[i] && x == coord_x[i]){
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

gen_app(size_wh, size_wv);
coord_x = malloc(size_wv*size_wh*sizeof(int));
coord_y = malloc(size_wv*size_wh*sizeof(int));

add_arr(x,y);
while(1){
    int key = getch();
    erase();
    if(key == 'w'){
	y--;
	}
    if(key == 's'){
	y++;
	}
    if(key == 'd'){
	x++;
	}
    if(key == 'a'){
	x--;
	}
    if(key == 'q'){
        return 0;
    }
    
    if(y < 0){
        y = size_wh-1;
    }
    if(y >= size_wh){
        y = 0;
    }
    if(x < 0){
        x = size_wv-1;
    }
    if(x >= size_wv){
        x = 0;
    }
    

    if(!crash_sn(y,x)){
        return 0;
    }

    add_arr(x,y);

    if (y==app_y && x == app_x){
        gen_app(size_wh, size_wv);  
    }
    else {
	    del_arr();
	}

    print_sn();
    
    mvaddstr(app_y, app_x, "a");
    
}



endwin();

}