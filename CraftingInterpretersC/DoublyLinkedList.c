#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* parent_node;
    int value;
    struct Node* child_node;
} Node;

typedef struct DoublyLinkedList {
    struct Node* start_node;
    struct Node* end_node;
    int size;
} DoublyLinkedList;

DoublyLinkedList list = {NULL, NULL, 0};

int delete(struct DoublyLinkedList list, int value) {
    Node * node = list.start_node;
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

struct DoublyLinkedList insert(struct DoublyLinkedList list, int value) {
    Node newNode = {list.end_node, value, NULL};
    if(!list.start_node){
        list.start_node = &newNode;
    }
    newNode.value = value;
    newNode.parent_node = list.end_node;
    newNode.child_node = NULL;
    list.end_node = &newNode;
    list.size++;
    printf("node.value %d\n", newNode.value);
    printf("node.value from list %d\n", list.end_node->value);
    printf("start node %p\n", list.start_node);
    return list;
}

Node* find(struct DoublyLinkedList list, int value){
    struct Node * node = list.start_node;
    while(node != NULL) {
        if(node->value == value){
            return node;
        }
        node = node->child_node;
    }
    return NULL;
}

void print(struct DoublyLinkedList list) {
    printf("print is called\n");
    Node * node = list.start_node;
    printf("node pointer: %p\n", list.start_node);
    //printf("node pointer: %p\n", node->value);
    //printf("node %d\n", &(node->value));
    while(node != NULL){
        printf("%d\n", node->value);
        node = node->child_node;
        printf("childNode %p\n", node);
    }
    return;
}


int main() {
    struct DoublyLinkedList list = {NULL, NULL, 0};

    list = insert(list, 1);
    printf("insert %p\n", list.start_node);
    insert(list, 2);
    insert(list, 3);
    insert(list, 4);
    insert(list, 5);

    print(list);

    /*Node* node1 = find(1);
    printf("%d\n", node1->value);

    Node* node2 = find(2);
    printf("%d\n", node2->value);

    Node* node3 = find(3);
    printf("%d\n", node3->value);

    Node* node4 = find(4);
    printf("%d\n", node4->value);

    Node* node5 = find(5);
    printf("%d\n", node5->value);*/

    delete(list, 1);
    find(list, 1);
    return 0;
}