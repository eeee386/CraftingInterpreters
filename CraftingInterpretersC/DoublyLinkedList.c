#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* parent_node;
    int value;
    struct Node* child_node;
} Node;

struct Node* head; // global variable - pointer to head node.

struct Node* GetNewNode(int value) {
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->value = value;
	newNode->parent_node = NULL;
	newNode->child_node = NULL;
	return newNode;
}


void delete(int value) {
    struct Node * node = head;
    while(node != NULL) {
        if(node->value == value) {
            printf("delete\n");
            struct Node* child_node = node->child_node;
            struct Node* parent_node = node->parent_node;
            if(parent_node != NULL) {
                parent_node->child_node = child_node;
                head = child_node;
            }
            if(child_node != NULL){
                child_node->parent_node = parent_node;
            }
        }
        node = node->child_node;
    }
}

void append(int value) {
    struct Node * node = head;
    struct Node * newNode = GetNewNode(value);

    if(node == NULL){
        head = newNode;
        return;
    }
    while(node->child_node){

        node = node->child_node;
    }
    node->child_node = newNode;
    return;

}

struct Node* find(int value){
    struct Node * node = head;
    while(node != NULL) {
        if(node->value == value){
            printf("it is called");
            return node;
        }
        node = node->child_node;
    }
    return NULL;
}

void print() {
    struct Node * node = head;
    while(node != NULL){
        printf("%d\n", node->value);
        node = node->child_node;
    }
    return;
}


int main() {
    struct Node * head = NULL;
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);

    print(head);

    struct Node* node1 = find(1);
    printf("%d\n", node1->value);

    struct Node* node2 = find(2);
    printf("%d\n", node2->value);

    struct Node* node3 = find(3);
    printf("%d\n", node3->value);

    struct Node* node4 = find(4);
    printf("%d\n", node4->value);

    struct Node* node5 = find(5);
    printf("%d\n", node5->value);

    delete(1);
    struct Node* nodeDeleted = find(1);
    printf("%p\n", nodeDeleted);

    print(head);
    return 0;
}
