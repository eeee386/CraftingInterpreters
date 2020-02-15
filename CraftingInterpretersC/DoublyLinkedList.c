#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct Node {
    struct Node* parent_node;
    char data[100];
    struct Node* child_node;
} Node;

struct DoublyLinkedList {
    struct Node * start_node;
    struct Node * end_node;
    int size;
} DoublyLinkedList;

//struct Node* head;
struct DoublyLinkedList* list;

struct Node* GetNewNode(char * value) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Error: Insufficent memory");
    }
	strcpy(newNode->data, value);
	newNode->parent_node = NULL;
	newNode->child_node = NULL;
	return newNode;
}

struct DoublyLinkedList* GetNewList(struct Node * newNode){
    struct DoublyLinkedList* list = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    if(newNode == NULL){
        printf("Error: Insufficient memory");
    }
    list->start_node = newNode;
    list->end_node = newNode;
    list->size = 1;
    return list;
}


void delete(char * value) {
    struct Node * node = list->start_node;
    while(node != NULL) {
        if(!strcmp(node->data, value)) {
            struct Node* child_node = node->child_node;
            struct Node* parent_node = node->parent_node;
            if(parent_node != NULL) {
                parent_node->child_node = child_node;
            } else {
                list->start_node = child_node;
            }
            if(child_node != NULL){
                child_node->parent_node = parent_node;
            } else {
                list->end_node = parent_node;
            }
            return;
        }
        node = node->child_node;
    }
}

void append(char * value) {
    struct Node * newNode = GetNewNode(value);
    if(list == NULL){
        list = GetNewList(newNode);
        return;
    }
    list->end_node->child_node = newNode;
    list->end_node->parent_node = list->end_node;
    list->end_node = newNode;
    list->size++;
    return;
}

void insertBefore(char * value) {
    struct Node* newNode = GetNewNode(value);
    if(list == NULL){
        list = GetNewList(newNode);
        return;
    }
    list->start_node->parent_node = newNode;
    newNode->child_node = list->start_node;
    list->start_node = newNode;
    list->size++;
}

struct Node* find(char * value){
    struct Node * node = list->start_node;
    while(node != NULL) {
        if(!strcmp(node->data, value)){
            return node;
        }
        node = node->child_node;
    }
    return NULL;
}

void print() {
    struct Node * node = list->start_node;
    printf("print started\n");
    while(node != NULL){
        printf("%s\n", node->data);
        node = node->child_node;
    }
    printf("print ended\n");
    return;
}


int main() {
    append("1");
    append("2");
    append("3");
    append("4");
    append("5");

    print();

    struct Node* node1 = find("1");
    printf("%s\n", node1->data);

    struct Node* node2 = find("2");
    printf("%s\n", node2->data);

    struct Node* node3 = find("3");
    printf("%s\n", node3->data);

    struct Node* node4 = find("4");
    printf("%s\n", node4->data);

    struct Node* node5 = find("5");
    printf("%s\n", node5->data);

    struct Node * endNode = list->end_node;
    print("%s\n", endNode->data);

    delete("3");
    struct Node* nodeDeleted = find("3");
    printf("%p\n", nodeDeleted);

    delete("1");
    struct Node* nodeDeleted2 = find("1");
    printf("%p\n", nodeDeleted2);

    insertBefore("0");

    print();
    return 0;
}
