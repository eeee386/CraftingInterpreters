#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* parent_node;
    int value;
    struct Node* child_node;
} Node;

DoublyLinkedList list = {NULL, NULL, 0};

int delete(struct DoublyLinkedList * list, int value) {
    Node * node = list->start_node;
    while(node) {
        if(node->value == value) {
            struct Node* child_node = node->child_node;
            struct Node* parent_node = node->parent_node;
            parent_node->child_node = child_node;
            child_node->parent_node = parent_node;
            return 1;
        }
        node = node->child_node;
    }
    return 0;
}

int insert(struct DoublyLinkedList * list, int value) {
    Node newNode = {list->end_node, value, NULL};
    if(!list->start_node){
        list->start_node = &newNode;
    }
    newNode.value = value;
    newNode.parent_node = list->end_node;
    newNode.child_node = NULL;
    list->end_node = &newNode;
    list->size++;
    return 0;
}

Node* find(struct DoublyLinkedList * list, int value){
    struct Node * node = list->start_node;
    while(node != NULL) {
        if(node->value == value){
            return node;
        }
        node = node->child_node;
    }
    return NULL;
}

void print(struct DoublyLinkedList * list) {
    printf("print is called\n");
    int value = list->start_node->value;
    printf("value %d\n", value);
    Node * node = list->start_node;
    //printf("node pointer: %p\n", list->start_node->value);
    while(node != NULL){
        printf("%d\n", node->value);
        node = node->child_node;
        printf("childNode %p\n", node);
    }
    return;
}


int main() {
    struct DoublyLinkedList list = {NULL, NULL, 0};
    struct DoublyLinkedList * pointer = &list;
    insert(pointer, 1);
    printf("insert %p\n", list.start_node);
    insert(pointer, 2);
    insert(pointer, 3);
    insert(pointer, 4);
    insert(pointer, 5);

    print(pointer);

    /*Node* node1 = find(1);
    printf("%d\n", node1->value);

    Node* node2 = find(2);
    printf("%d\n", node2->value);

    Node* node3 = find(3);
    printf("%d\n", node3->value);

    Node* node4 = find(4);
    printf("%d\n", node4->value);

    Node* node5 = find(5);
    printf("%d\n", node5->value);

    delete(list, 1);
    find(list, 1);*/
    return 0;
}