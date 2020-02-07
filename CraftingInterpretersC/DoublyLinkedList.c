#include <string.h>
#include <stdio.h>

typedef struct {
    struct Node* parent_node;
    char* value[100];
    struct Node* child_node;
} Node;

typedef struct {
    struct Node* start_node;
    struct Node* end_node;
    int size;
} DoublyLinkedList;

int delete(DoublyLinkedList list, char* value) {
    Node* node = list.start_node;
    while(node) {
        if(strcmp(&node->value, value)) {
            Node* child_node = &node->child_node;
            Node* parent_node = &node->parent_node;
            parent_node->child_node = child_node;
            child_node->parent_node = parent_node;
            return 1;
        }
        node = &node->child_node;
    }
    return 0;
}

int insert(DoublyLinkedList list, char* value) {
    Node newNode = {list.end_node, value, NULL};
    list.size++;
    return 1;
}

Node* find(DoublyLinkedList list, char* value){
    struct Node* node = list.start_node;
    while(&node) {
        if(strcmp(&node->value, value)){
            return node;
        }
        node = &node->child_node;
    }
}


int main() {
    DoublyLinkedList list = {NULL, NULL};
    insert(list, "1");
    insert(list, "2");
    insert(list, "3");
    insert(list, "4");
    insert(list, "5");

    Node* node1 = get(list, "1");
    printf("%s", &node1->value);

    Node* node2 = get(list, "2");
    printf("%s", &node2->value);

    Node* node3 = get(list, "3");
    printf("%s", &node3->value);

    Node* node4 = get(list, "4");
    printf("%s", &node4->value);

    Node* node5 = get(list, "5");
    printf("%s", &node5->value);

    delete(list, "1");
    get(list, "1");    
}