#include <stdio.h>

typedef struct 
{
    int x;
    int y;
}Point;

typedef struct 
{
    Point a;
    Point b;
} Box;

Point top = {22, 48};
Point bottom;
Box rect = {6, 12, 34, 67};

int main()
{
    bottom.x = 5;
    bottom.y = 8;
    printf("%d\n", top.x);
    printf("%d\n", top.y);
    printf("%d\n", bottom.x);
    printf("%d\n", bottom.y);
    printf("rect.a.x = %d\n", rect.a.x);
    printf("rect.a.y = %d\n", rect.a.y);
    printf("rect.b.x = %d\n", rect.b.x);
    printf("rect.b.y = %d\n", rect.b.y);






}