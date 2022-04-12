#include <stdio.h>
#define begin(x, y) ((x)*(y))
#define end }


struct companies {
    char name[50];
    int cost;
    int n_workers;
};



int main() {
   int name[10];
   struct companies it_companies[10] = {{"Google", 300, 1000},
                                        {"Tesla", 450, 2000}, 
                                        {"Intel", 300, 9000}};
    
    it_companies[3].cost = 500;
    it_companies[3].n_workers = 20000;
    return 0;
}
























