#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
    
    int app_x;
    int app_y;
    int size_wh;
    int size_wv;
    int bar=0;
    int begining;
    int x = 0;
    int y = 0;
    int size_sn;
    int napr_x;
    int napr_y;
    int speed;
    struct list* coord = NULL;
    
    
    struct list
    {
    int coord_x;
    int coord_y;
    struct list* next;
    };
    
     

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
/*    coord
    |
    v
    1 -> 8 -> 9 -> 4 -> NULL          
    ^
    |
    3
*/    
void add_arr(int x, int y){
    struct list* new = malloc(sizeof(struct list));
    new ->coord_x = x;
    new ->coord_y = y;
    new ->next = coord;
    coord = new; 
	
}
    /*           ---------
              |        v
    1 -> 2 -> 3  9 -> NULL
              ^
              |
              i
*/
// O(1)
void del_arr(){
    struct list* i = coord;
    while(i->next->next != NULL){
	i = i -> next;
    }
    free(i->next);
    i ->next = NULL;
    
    }
    
    
/* 0  0 3 4 6 1 0 0 0 0
      ^     ^
      beg   bar
      
 0 0 3 4 6 1 7 9 0 0
     ^         ^
     bar       beg
  */
void print_sn(){
    struct list* i = coord;
    while(i != NULL){
	mvaddstr(i->coord_y, i->coord_x, "s");
	i = i -> next;
    }
    
    
}   



int crash_sn(int y ,int x){
    struct list* i = coord;
    while(i != NULL){
	if(y == i->coord_y && x == i->coord_y){
	    return 0;
	}
	i = i -> next;
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