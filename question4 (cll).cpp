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
    } else {
        new_node->next = tail->next; // New node points to the first node
        tail->next = new_node; // Update the last node's next to point to the new node
        tail = new_node; // Update the tail pointer to the new node
    }
}

// FUNCTION TO REMOVE FIRST NODE AND ADD AT THE END
void end_node(struct NODE* &tail) {
    if (tail == NULL) {
        return; // If the list is empty, return
    }

    NODE* temp = tail->next; // First node

    if (temp == tail) {
        return; // If there's only one node in the list, return
    }

    tail->next = temp->next; // Update the tail's next pointer to the second node
    temp->next = NULL;
    insert_end(tail, temp->data); // Insert the first node at the end
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

int main() {
    NODE* tail = NULL;

    // Inserting nodes into the circular list
    insert_end(tail, 10);
    insert_end(tail, 11);
    insert_end(tail, 12);
    insert_end(tail, 13);
    insert_end(tail, 14);

    // Printing nodes of the circular list
    cout << "VALUE OF CIRCULAR LIST" << endl;
    print(tail);

    // Calling the end_node function to remove the first node and add it at the end
    end_node(tail);
    end_node(tail);
    end_node(tail);

    // Printing nodes of the circular list after end_node function
    cout << "\nVALUE OF CIRCULAR LIST AFTER end_node FUNCTION" << endl;
    print(tail);

    return 0;
}

