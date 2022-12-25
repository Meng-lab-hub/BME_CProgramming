#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int len;
    double* data;
} set;

set* set_init(set*);
void set_insert(set*, double);
void set_remove(set*, double);
int set_contain(set*, double);
void set_print(set*);
void set_destroy(set*);

int main(void) {
    set* s;

    s = set_init(s);
    set_insert(s, 42.1);
    set_insert(s, 8.3);
    set_insert(s, 42.1);
    set_remove(s, 8.3);
    set_insert(s, 3.1415);
    set_print(s);
    if (set_contain(s, 42.1)) printf("it is in the set\n");
    else printf("it is not in the set\n");
    set_destroy(s);
    return 0;
}
set* set_init(set* s) {
    s = (set*)malloc(sizeof(set));

    s->len = 0;
    s->data = NULL;
    return s;

}
void set_insert(set* s, double num) {
    if (set_contain(s, num)) return;

    double* tmp = (double*)malloc((s->len+1) * sizeof(double));
    for (int i = 0; i < s->len; i++)
        tmp[i] = s->data[i];
    tmp[s->len] = num;
    free(s->data);
    s->data = tmp;
    s->len++;
}
void set_remove(set* s, double num) {
    if (!set_contain(s, num))
        return;
    
    double* tmp = (double*)malloc((s->len-1) * sizeof(double));
    for (int i = 0, j = 0; i < s->len; i++)
        if (s->data[i] != num)
            tmp[j++] = s->data[i];
    free(s->data);
    s->data = tmp;
    s->len--;
}
int set_contain(set* s, double num) {
    for (int i = 0; i < s->len; i++)
        if (s->data[i] == num) return 1;
    return 0;
}
void set_print(set* s) {
    for (int i = 0; i < s->len; i++)
        printf("%g ", s->data[i]);
    printf("\n");
}
void set_destroy(set* s) {
    free(s->data);
    free(s);
}