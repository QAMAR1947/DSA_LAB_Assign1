#include <iostream>
using namespace std;

// CREATING STRUCTURE OF LINKED LIST
struct NODE {
    int data;
    NODE* next;
};

// FUNCTION TO INSERT NODE AT THE END OF LIST
void insert_end(struct NODE* &tail, int x) {
    NODE* new_node = new NODE();
    new_node->data = x;
    new_node->next = NULL;

    // IF THERE IS NO NODE IN LIST (CORNER CASE)
    if (tail == NULL) {
        new_node->next = new_node;  // Circular link to itself
        tail = new_node;  // Set the tail to the new node
        return;
    }

    new_node->next = tail->next;  // New node's next points to the current first node
    tail->next = new_node;  // Update the current tail's next to point to the new node
    tail = new_node;  // Update the tail to the new node
}

// FUNCTION TO REMOVE LAST NODE AND INSERT IT AT THE BEGINNING
void last_node_to_beginning(struct NODE* &tail) {
    if (tail == NULL || tail->next == tail) {
        // If the list is empty or has only one node, nothing to do
        return;
    }

    NODE* last_node = tail;
    NODE* previous = tail;

    // Find the node just before the last node
    while (previous->next != tail) {
        previous = previous->next;
    }

    // Update the tail to the previous node
    tail = previous;

    // Update the last node's next to point to the current first node
    last_node->next = tail->next;

    // Update the tail's next to point to the last node
    tail->next = last_node;
}

// FUNCTION TO PRINT NODES
void print(struct NODE* tail) {
    if (tail == NULL) {
        cout << "LIST IS EMPTY" << endl;
        return;
    }

    NODE* current = tail->next;
    NODE* start = current;  // Keep track of the starting node

    do {
        cout << current->data << ", ";
        current = current->next;
    } while (current != start); // Continue until we've looped back to the first node
    cout << endl;
}

// MAIN FUNCTION
int main() {
    NODE* tail = NULL;

    // inserting nodes in the circular linked list
    insert_end(tail, 10);
    insert_end(tail, 11);
    insert_end(tail, 12);
    insert_end(tail, 13);
    insert_end(tail, 14);

    // printing nodes of the circular linked list
    cout << "Printing nodes before moving the last node to the beginning" << endl;
    print(tail);

    // Calling the last_node_to_beginning function
    last_node_to_beginning(tail);

    // Printing nodes of the circular linked list after moving the last node to the beginning
    cout << "Printing nodes after moving the last node to the beginning" << endl;
    print(tail);

    return 0;
}

