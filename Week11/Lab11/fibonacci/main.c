#include <stdio.h>

int fib(int);

int main(void) {
    int n = 40;
    for (int i = 0; i < n; i++) printf("%d ", fib(i));
    printf("\n");
    return 0;
}
int fib(int n) {
    if (n <= 1) return n;
    else return fib(n-2) + fib(n-1);
}