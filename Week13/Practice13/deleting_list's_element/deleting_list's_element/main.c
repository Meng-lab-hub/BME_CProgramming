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
    char word[100];
    struct List* next;
} List;

List* add_to_list(List*, int);
void print_list(List*);
List* delete_list(List*);
List* reverse_list(List*);

int main(void) {
    List* head = NULL;
    int num;
    
    add_to_list(head, "apple");
    add_to_list(head, "lime")
    print_list(head);
    head = reverse_list(head);
    print_list(head);
    delete_list(head);
    
    return 0;
}

List* add_to_list(List* head, char word) {
    List* NewEl = (List*)malloc(sizeof(List));
    NewEl->word = word;
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
        printf("%s ", p->word);
    printf("\n");
}
List* delete_short(List* head,)
