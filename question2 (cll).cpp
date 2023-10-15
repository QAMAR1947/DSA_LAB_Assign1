#include <iostream>
using namespace std;

// CREATING STRUCTURE OF CIRCULAR LINKED LIST
struct NODE {
    int data;
    NODE* next;
};

// GLOBAL VARIABLE TO COUNT TOTAL NODES
int count = 0;

// FUNCTION TO INSERT NODE AT THE END OF CIRCULAR LIST
void insert_end(struct NODE* &tail, int x) {
    NODE* new_node = new NODE();
    new_node->data = x;
    new_node->next = NULL;

    if (tail == NULL) {
        new_node->next = new_node; // Point to itself in a circular list
        tail = new_node;
        count++;
        return;
    }

    new_node->next = tail->next; // New node points to the first node
    tail->next = new_node; // Update the last node's next to point to the new node
    tail = new_node; // Update the tail pointer to the new node
    count++;
}

// FUNCTION TO SPLIT LIST INTO TWO PARTS
void split(struct NODE* &tail) {
    NODE* temp1 = tail->next; // First node of the circular list

    if (tail == NULL || tail->next == tail) {
        return; // If the list is empty or has only one node, return
    }

    // EVEN CASE
    if (count % 2 == 0) {
        for (int i = 0; i < count / 2; i++) {
            cout << temp1->data << ", ";
            temp1 = temp1->next;
        }
        cout << endl;
        for (int i = 0; i < count / 2; i++) {
            cout << temp1->data << ", ";
            temp1 = temp1->next;
        }
    }

    // ODD CASE
    if (count % 2 == 1) {
        for (int i = 0; i < int(count / 2) + 1; i++) {
            cout << temp1->data << ", ";
            temp1 = temp1->next;
        }
        cout << endl;
        for (int i = 0; i < int(count / 2); i++) {
            cout << temp1->data << ", ";
            temp1 = temp1->next;
        }
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

// MAIN FUNCTION
int main() {
    NODE* tail1 = NULL;

    insert_end(tail1, 1);
    insert_end(tail1, 2);
    insert_end(tail1, 3);
    insert_end(tail1, 4);
    insert_end(tail1, 5);
    insert_end(tail1, 6);
    insert_end(tail1, 7);

    split(tail1);

    return 0;
}

