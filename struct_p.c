#include "struct_p.h"
#include <stdlib.h>

int compareEmployee(Employee* e1, Employee* e2)
{
    return strcmp(e1->name, e2->name);
}
void displayEmployee(Employee* e)
{
    printf("%s\t %d\n", e->name, e->age);
}


void initializeList(LinkedList* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

void addHead(LinkedList* list, void* data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    if(list->head == NULL){
        list->tail = node;
    }
    node->next = list->head;
    list->head = node;
}

void addTail(LinkedList* list, void* data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if(list->head == NULL){
        list->head = node;
    }
    else{
        list->tail->next = node;
    }
    list->tail = node;
}

void delete(LinkedList* list, Node* node)
{
    if(node == list->head){
        if(list->head->next == NULL){
            list->head = list->tail = NULL;
        }
        else{
            list->head = list->head->next;
        }
    }else{
        Node* tmp = list->head;
        while(tmp != NULL && tmp->next != node){
            tmp = tmp->next;
        }
        if(tmp != NULL){
            tmp->next = node->next;
        }
    }
    free(node);
}
Node* getNode(LinkedList* list, COMPARE compare, void* data)
{
    Node* node = list->head;
    while(node != NULL){
        if(compare(node->data, data) == 0){
            break;
        }
        node = node->next;
    }
    return node;
}
void displayLinkedList(LinkedList* list, DISPLAY display)
{
    printf("\nLinked List\n");
    Node* current = list->head;
    while(current != NULL){
        display(current->data);
        current = current->next;
    }
}


void initializeQueue(Queue* q)
{
    initializeList(q);
}
void enqueue(Queue* q, void* node)
{
//    addHead(q, node);
    addTail(q, node);
}
void* dequeue(Queue* q)
{
    Node* node = q->head;
    if(node == NULL){
        return NULL;
    }
    else if(node == q->tail){
        q->head = q->tail = NULL;
    }
    else{
        q->head = q->head->next;
    }
    void* data = node->data;
    free(node);
    return data;
}


void initializeStack(Stack* s)
{
    initializeList(s);
}
void push(Stack* s, void* node)
{
    addHead(s, node);
}
void* pop(Stack* s)
{
    Node* node = s->head;
    if(node == NULL){
        return NULL;
    }
    else if(node == s->tail){
        s->head = s->tail = NULL;
    }
    else{
        s->head = s->head->next;
    }
    void* data = node->data;
    free(node);
    return data;
}


void insertNode(TreeNode **root, COMPARE compare, void* data)
{
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    if(*root == NULL){
        *root = node;
        return;
    }

    while(1){
        if(compare((*root)->data, data) > 0){
            if((*root)->left != NULL){
                *root = (*root)->left;
            }
            else{
                (*root)->left = node;
                break;
            }
        }
        else{
            if((*root)->right != NULL){
                *root = (*root)->right;
            }
            else{
                (*root)->right = node;
                break;
            }
        }
    }
}

void inOrder(TreeNode *root, DISPLAY display)
{
    if(root != NULL){
        inOrder(root->left, display);
        display(root->data);
        inOrder(root->right, display);
    }
}
void postOrder(TreeNode *root, DISPLAY display)
{
    if(root != NULL){
        postOrder(root->left, display);
        postOrder(root->right, display);
        display(root->data);
    }

}
void preOrder(TreeNode *root, DISPLAY display)
{
    if(root != NULL){
        display(root->data);
        preOrder(root->left, display);
        preOrder(root->right, display);
    }

}
