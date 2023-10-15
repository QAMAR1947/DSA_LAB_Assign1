#include <iostream>
using namespace std;

// CREATING STRUCTURE OF CIRCULAR LINKED LIST
struct NODE {
    int data;
    NODE* next;
};

// FUNCTION TO INSERT NODE AT THE END OF CIRCULAR LIST
void insert_end(struct NODE* &tail, int x) {
    NODE* new_node = new NODE();
    new_node->data = x;
    new_node->next = NULL;

    if (tail == NULL) {
        new_node->next = new_node; // Point to itself in a circular list
        tail = new_node;
    }
    else {
        new_node->next = tail->next; // New node points to the first node
        tail->next = new_node; // Update the last node's next to point to the new node
        tail = new_node; // Update the tail pointer to the new node
    }
}

// FUNCTION TO PRINT NODES IN CIRCULAR LIST
void print(struct NODE* tail) {
    if (tail == NULL) {
        cout << "LIST IS EMPTY" << endl;
        return;
    }

    NODE* current = tail->next; // Start from the first node

    do {
        cout << current->data << ", ";
        current = current->next;
    } while (current != tail->next);

    cout << endl;
}

// FUNCTION TO CONCATENATE TWO CIRCULAR LISTS
void concatenate(struct NODE* &tail1, struct NODE* &tail2) {
    if (tail1 == NULL || tail2 == NULL) {
        return; // Return if either list is empty
    }

    NODE* temp1 = tail1->next; // First node of list 1
    NODE* temp2 = tail2->next; // First node of list 2

    tail1->next = temp2; // Connect the last node of list 1 to the first node of list 2
    tail2->next = temp1; // Connect the last node of list 2 to the first node of list 1

    tail1 = tail2; // Update the tail pointer to the last node of list 2
}

int main() {
    NODE* tail1 = NULL;
    NODE* tail2 = NULL;

    // Adding nodes to list 1
    insert_end(tail1, 10);
    insert_end(tail1, 11);
    insert_end(tail1, 12);
    insert_end(tail1, 13);

    // Adding nodes to list 2
    insert_end(tail2, 14);
    insert_end(tail2, 15);
    insert_end(tail2, 16);
    insert_end(tail2, 17);

    // Printing nodes of list 1
    cout << "VALUE OF LIST 1" << endl;
    print(tail1);

    // Printing nodes of list 2
    cout << "\nVALUE OF LIST 2" << endl;
    print(tail2);

    // CONCATENATE FUNCTION CALL
    concatenate(tail1, tail2);

    // Printing nodes of list 1 after concatenation
    cout << "\nVALUE OF LIST 1 AFTER CONCATENATION" << endl;
    print(tail1);

    return 0;
}

