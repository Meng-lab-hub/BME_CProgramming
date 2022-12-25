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
List* delete_list(List*);
List* reverse_list(List*);

int main(void) {
    List* head = NULL;
    int num;
    
    printf("Enter your sequence of number here: ");
    scanf("%d", &num);
    while (num != 0) {
        head = add_to_list(head, num);
        scanf("%d", &num);
    }
    print_list(head);
    head = reverse_list(head);
    print_list(head);
    delete_list(head);
    
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
List* delete_list(List* head) {
    List* p = head;
    while (p != NULL) {
        List* tmp = p;
        p = p->next;
        free(tmp);
    }
    return NULL;
}
List* reverse_list(List* head) {
    List* reversed = NULL;
    
    while (head != NULL) {
        List* tmp = head->next;
        head->next = reversed;
        reversed = head;
        head = tmp;
    }
    return reversed;
}
