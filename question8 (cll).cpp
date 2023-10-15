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

// FUNCTION TO CALCULATE SMALLEST, LARGEST, TOTAL, AND AVERAGE OF ELEMENTS
void calculation(struct NODE* &tail) {
    NODE* temp = tail->next; // Start from the first node

    if (tail == NULL) {
        cout << "LIST IS EMPTY" << endl;
        return;
    }

    int count = 0, max = temp->data, min = temp->data, total = 0, avg = 0;

    do {
        if (temp->data > max)
            max = temp->data;

        if (temp->data < min)
            min = temp->data;

        total += temp->data;
        temp = temp->next;

        count++;
    } while (temp != tail->next);

    avg = total / count;

    cout << "\nSMALLEST ELEMENT IS : " << min << endl;
    cout << "\nLARGEST ELEMENT IS : " << max << endl;
    cout << "\nTOTAL OF ELEMENTS IS : " << total << endl;
    cout << "\nAVERAGE OF ELEMENTS IS : " << avg << endl;
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
    NODE* tail1 = NULL;

    insert_end(tail1, 1);
    insert_end(tail1, 2);
    insert_end(tail1, 3);
    insert_end(tail1, 4);
    insert_end(tail1, 5);
    insert_end(tail1, 6);
    insert_end(tail1, 7);

    cout << "PRINT BEFORE COUNT FUNCTION" << endl;
    print(tail1);

    // Calling calculation function
    calculation(tail1);

    return 0;
}

