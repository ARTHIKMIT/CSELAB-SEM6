#include <stdio.h>

int main() {
    int a = 255;
    float b = 3.14159;
    char c = 'X';
    char str[] = "Hello";

    printf("%d\n", a);
    printf("%x\n", a);
    printf("%o\n", a);
    printf("%f\n", b);
    printf("%.2f\n", b);
    printf("%e\n", b);
    printf("%c\n", c);
    printf("%s\n", str);
    return 0;
}
