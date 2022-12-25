//
//  main.c
//  trees
//
//  Created by Khongmeng Kormoua on 2020. 12. 11..
//  Copyright © 2020. Khongmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Word {
    char word[30 + 1];
    int occurrences;
    struct Word* left;
    struct Word* right;
} Word;

typedef struct Contact {
    char* name;
    char phone[20 + 1];
    struct Contact* left;
    struct Contact* right;
} Contact;

typedef struct Morse {
    char letter;
    struct Morse* left;
    struct Morse* right;
} Morse;

Contact* insert_contact(Contact*, char* , char* );
void print_contacts(Contact*);
void print_smith(Contact*);
int tree_height(Contact*);
int tree_compare(Contact*, Contact*);

int main(void) {
    Contact* contacts = NULL;
    contacts = insert_contact(contacts, "Kormoua, Deyoun", "+36 70 623-6684");
    contacts = insert_contact(contacts, "Kormoua, Dar", "+12 345-6789");
    contacts = insert_contact(contacts, "Kormoua, Meng", "995 667 123");
    contacts = insert_contact(contacts, "Smith, John", "012 667 123");
    contacts = insert_contact(contacts, "Ameri, sherry", "012 667 123");
    contacts = insert_contact(contacts, "Ben, tenisan", "012 667 123");
    
    print_contacts(contacts);
    //print_smith(contacts);
    printf("Height = %d\n", tree_height(contacts));
    
    Contact* contacts2 = NULL;
    contacts = insert_contact(contacts2, "Kormoua, Deyoun", "+36 70 623-6684");
    contacts = insert_contact(contacts2, "Kormoua, Dar", "+12 345-6789");
    contacts = insert_contact(contacts2, "Kormoua, Meng", "995 667 123");
    contacts = insert_contact(contacts2, "Smith, John", "012 667 123");
    contacts = insert_contact(contacts2, "Ameri, sherry", "012 667 123");
    contacts = insert_contact(contacts2, "Ben, tenisan", "012 667 123");
    
    printf("Two trees are equal %d\n", tree_compare(contacts2, contacts));
    return 0;
}

Contact* insert_contact(Contact* root, char* name, char* phone) {
    if (root == NULL) {
        Contact* new_node = (Contact*)malloc(sizeof(Contact));
        new_node->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
        strcpy(new_node->name, name);
        strcpy(new_node->phone, phone);
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (strcmp(root->name, name) > 0)
        root->left = insert_contact(root->left, name, phone);
    else
        root->right = insert_contact(root->right, name, phone);
    return root;
}
void print_contacts(Contact* root) {
    if (root == NULL)
        return;
    print_contacts(root->left);
    printf("%s\t%s\n", root->name, root->phone);
    print_contacts(root->right);
}
void print_smith(Contact* root) {
    if (root == NULL)
        return;
    print_contacts(root->left);
    if (strncmp(root->name, "Smith,", 6) == 0)
        printf("%s\t%s\n", root->name, root->phone);
    print_contacts(root->right);
}
int tree_height(Contact* root) {
    if (root == NULL)
        return 0;
    int height_left = tree_height(root->left);
    int height_right = tree_height(root->right);
    if (height_left > height_right)
        return height_left + 1;
    else
        return height_right + 1;
}
int tree_compare(Contact* root1, Contact* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    
    // in case of root1 and root2 are not NULL
    int le = tree_compare(root1->left, root2->left);
    int re = tree_compare(root1->right, root2->right);
    return le
        && re
        && strcmp(root1->name, root2->name) == 0
        && strcmp(root1->phone, root2->phone) == 0;
}
