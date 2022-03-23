#include <stdio.h>

struct coords
{
    int x;
    int y;
} Point;

struct coords Top;

int main()
{
    Point.x = 18;
    Point.y = 22;
    Top.x = 120;
    Top.y = 587;

    printf("%d\n", Point.x);
    printf("%d\n", Point.y);
    printf("%d\n", Top.x);
    printf("%d\n", Top.y);


}