#include <stdio.h>

int g(int x) { return x + 1; }
int f(int x);

int main() {
    int res = f(10);
    printf("%d\n", res); 
    return 0;
}