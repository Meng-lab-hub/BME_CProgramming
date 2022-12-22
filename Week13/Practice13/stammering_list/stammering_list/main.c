//
//  main.c
//  reverse_list
//
//  Created by Khongmeng Kormoua on 2020. 12. 04..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int data;
    struct List* next;
} List;

List* add_to_list(List*, int);
void print_list(List*);
void stammering(List*);

int main(void) {
    List* head = NULL;
    add_to_list(head, 1);
    add_to_list(head, 2);
    add_to_list(head, 3);
    print_list(head);

    print_list(head);

    return 0;
}

List* add_to_list(List* head, int num) {
    List* NewEl = (List*)malloc(sizeof(List));
    NewEl->data = num;
    NewEl->next = NULL;
    
    if (head == NULL) return NewEl;
    
    List* p = head;
    while (p->next != NULL)
        p = p->next;
    
    p->next = NewEl;
    return head;
}
void print_list(List* head) {
    List* p;
    if (head == NULL) return;
    for (p = head; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}
void stammering(List* head) {
    List* p;
    for (p = head; p != NULL; p = p->next)
        if (p->data % 2 == 0) {
            List* newEl = (List*)malloc(sizeof(List));
            List* newZero = (List*)malloc(sizeof(List));
            newEl->data = p->data;
            newEl->next = p->next;
            newZero->data = 0;
            newZero->next = NULL;
            p->next = newZero;
            p = p->next->next;
        }
}
