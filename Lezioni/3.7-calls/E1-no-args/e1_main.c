#include <stdio.h>

int g() { return 10; }
int f();

int main() {
    int res = f();
    printf("%d\n", res); // deve stampare 11
    return 0;
}
