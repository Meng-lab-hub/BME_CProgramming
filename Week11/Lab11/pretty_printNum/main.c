#include <stdio.h>

void pretty_print(int);

int main(void) {
    int num = 1000222;
    pretty_print(num);
    printf("\n");
    return 0;
}
void pretty_print(int num) {
    if (num < 1000) {
        printf("%d ", num%1000);
        return;
    }
    if (num >= 1000)
        pretty_print(num/1000);
    printf("%03d ", num%1000);
}