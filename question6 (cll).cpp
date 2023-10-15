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

// FUNCTION TO CHECK TOTAL OCCURRENCE OF AN ELEMENT
void occur(struct NODE* &tail, int value) {
    int count = 0;

    if (tail == NULL) {
        cout << "NO ELEMENT IN LIST" << endl;
        return;
    }

    NODE* temp = tail->next; // Start from the first node

    do {
        if (value == temp->data) {
            count++;
        }

        temp = temp->next;
    } while (temp != tail->next);

    cout << "THE NUMBER " << value << " OCCURRED " << count << " TIMES" << endl;
}

// FUNCTION TO PRINT NODES IN CIRCULAR LIST
void print(struct NODE* &tail) {
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
    NODE* tail1 = NULL;

    insert_end(tail1, 10);
    insert_end(tail1, 11);
    insert_end(tail1, 10);
    insert_end(tail1, 13);
    insert_end(tail1, 10);
    insert_end(tail1, 12);
    insert_end(tail1, 10);

    cout << "PRINT BEFORE OCCUR FUNCTION" << endl;
    print(tail1);

    // Calling occur function
    occur(tail1, 10);
    return 0;
}

