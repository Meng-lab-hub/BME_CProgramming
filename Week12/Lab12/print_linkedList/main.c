#include <stdio.h>
#include <stdlib.h>
 
typedef struct ListEl {
    int data;
    struct ListEl *nxt;
} ListEl;
 
ListEl *list_build(void);
int list_len(ListEl*);
ListEl* list_delete(ListEl*);
ListEl* list_insert_athead(ListEl*, int);
ListEl* list_insert_attail(ListEl*, int);
ListEl* list_search(ListEl*, int);

int main(void) {
    ListEl *head;
    ListEl* p = NULL;
    ListEl* q = NULL;
    head = list_build();
    
    for (p = head; p != NULL; p = p->nxt)
        printf("%d ", p->data);
    printf("\n");
    printf("The length of the list is: %d\n", list_len(head));
    head = list_delete(head);
    head = list_insert_athead(head, 0);
    head = list_insert_athead(head, 1);
    head = list_insert_athead(head, 2);
    for (p = head; p != NULL; p = p->nxt)
        printf("%d ", p->data);
    printf("\n");

    head = list_insert_attail(head, 3);
    head = list_insert_attail(head, 4);
    for (p = head; p != NULL; p = p->nxt)
        printf("%d ", p->data);
    printf("\n");

    q = list_search(head, 5);
    if (q == NULL)
        printf("Cannot find such element in the list!\n");
    else printf("Found the element in address %p\n", q);
    return 0;
}

/* creates a new list from the array elements */
ListEl *list_build(void) {
    int values[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };
    ListEl *lis = NULL;
 
    int i;
    for (i = 0; values[i] != -1; ++i) {
        ListEl *u;
        u = (ListEl*) malloc(sizeof(ListEl));
        u->nxt = lis;
        u->data = values[i];
        lis = u;
    }
    return lis;
}
 int list_len(ListEl* head) {
    int len = 0;
    for (int i = 0; head != NULL; i++) {
        len++;
        head = head->nxt;
    }
    return len;
 }
ListEl* list_delete(ListEl* head) {
    ListEl* p = NULL;
    ListEl* q = NULL;
    
    if (head == NULL) return NULL;
    for (p = head, q = p->nxt; p->nxt != NULL; q = p->nxt) {
        free(p);
        p = q;
    }
    free(p);
    p = NULL;
    return p;
 }

ListEl* list_insert_athead(ListEl* head, int num) {
    ListEl* p = (ListEl*)malloc(sizeof(ListEl));
    p->data = num;
    p->nxt = head;
    return p;
}
ListEl* list_insert_attail(ListEl* head, int num) {
    ListEl* p = (ListEl*)malloc(sizeof(ListEl));
    if (head == NULL) {
        p->data = num;
        p->nxt = NULL;
        return p;
    }
    for (p = head; p->nxt != NULL; p = p->nxt);
    p->nxt = (ListEl*)malloc(sizeof(ListEl));
    p->nxt->data = num;
    p->nxt->nxt = NULL;
    return head;
}
ListEl* list_search(ListEl* head, int num) {
    ListEl* p;
    for (p = head; p != NULL; p = p->nxt)
        if (p->data == num)
            return p;
    return NULL;
}