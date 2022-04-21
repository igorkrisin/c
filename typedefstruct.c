#include <stdio.h>
#define begin(x, y) ((x)*(y))
#define end }

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"

int main() {
    printf("%s00\n",    YELLOW);
    printf("%s===3\n", RED);
    printf("%s-.\n",  WHITE);

    return 0;
}




















