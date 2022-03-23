#include <stdio.h>
#include <string.h>




int main(){

int state = 0;

char* str = "aaabba";

for(int i = 0;i < strlen(str); ++i){
    if(str[i] == 'a' && state == 0){
	state = 0;
    }
    else if(str[i] == 'b' && state == 0){
	state = 1;
    }
    else if(str[i] == 'b' && state == 1){
	state = 1;	
    }
    else if(str[i] == 'a' && state == 1){
	state = 2;
    }
    else if(str[i] == 'a' || str[i] == 'b' && state == 2){
	state = 1;
    }
}    

if(state == 1){
    printf("yes");
}
else{
    printf("no");
}
}