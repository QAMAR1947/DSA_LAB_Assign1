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

// FUNCTION TO STORE ODD AND EVEN ELEMENTS IN SEPARATE LISTS
void separate(struct NODE* &tail, struct NODE* &list1, struct NODE* &list2) {
    if (tail == NULL) {
        cout << "LIST IS EMPTY" << endl;
        return;
    }

    NODE* temp = tail->next; // Start from the first node

    do {
        if (temp->data % 2 == 0) {
            insert_end(list1, temp->data);
        } else {
            insert_end(list2, temp->data);
        }

        temp = temp->next;
    } while (temp != tail->next);

    // Clear the original list
    while (tail->next != tail) {
        NODE* temp = tail->next;
        tail->next = tail->next->next;
        delete temp;
    }
    tail = NULL; // Set the tail to NULL since the original list is now empty
}

int main() {
    NODE* tail1 = NULL;
    NODE* list1 = NULL;
    NODE* list2 = NULL;

    insert_end(tail1, 1);
    insert_end(tail1, 2);
    insert_end(tail1, 3);
    insert_end(tail1, 4);
    insert_end(tail1, 5);

    cout << "PRINT BEFORE SEPARATE FUNCTION" << endl;
    print(tail1);

    // Calling separate function
    separate(tail1, list1, list2);

    cout << "\nPRINT MAIN LIST AFTER SEPARATE FUNCTION" << endl;
    print(tail1);

    cout << "\nPRINT LIST 1 (EVEN) AFTER SEPARATE FUNCTION" << endl;
    print(list1);
    cout << "\nPRINT LIST 2 (ODD) AFTER SEPARATE FUNCTION" << endl;
    print(list2);

    return 0;
}

