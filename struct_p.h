#ifndef STRUCT_P_H_INCLUDED
#define STRUCT_P_H_INCLUDED

#include <string.h>
#include <stdio.h>

// base structure and functions
typedef struct _employee{
    char name[32];
    unsigned char age;
} Employee;

int compareEmployee(Employee* e1, Employee* e2);
void displayEmployee(Employee* e);


typedef void (*DISPLAY)(void*);
typedef int (*COMPARE)(void*, void*);


// Linked list node and list structure
typedef struct _node{
    void *data;
    struct _node *next;
} Node;
typedef struct _linkedlist{
    Node *head;
    Node *tail;
    Node *current;
} LinkedList;

void initializeList(LinkedList*);
void addHead(LinkedList*, void*);
void addTail(LinkedList*, void*);
void delete(LinkedList*, Node*);
Node* getNode(LinkedList*, COMPARE, void*);
void displayLinkedList(LinkedList*, DISPLAY);


// queue
typedef LinkedList Queue;

void initializeQueue(Queue* q);
void enqueue(Queue* q, void* node);
void* dequeue(Queue* q);


// stack
typedef LinkedList Stack;

void initializeStack(Stack* s);
void push(Stack* s, void* node);
void* pop(Stack* s);


// tree
typedef struct _tree{
    void *data;
    struct _tree *left;
    struct _tree *right;
} TreeNode;

void insertNode(TreeNode **root, COMPARE compare, void* data);
void inOrder(TreeNode *root, DISPLAY display);
void postOrder(TreeNode *root, DISPLAY display);
void preOrder(TreeNode *root, DISPLAY display);


#endif // STRUCT_P_H_INCLUDED
