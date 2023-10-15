#include <iostream>
using namespace std;

// CREATING STRUCTURE OF DOUBLY LINKED LIST
struct NODE {
    int data;
    NODE* next;
    NODE* prev;
};

// FUNCTION TO INSERT NODE AT THE END OF LIST
void insert_end(struct NODE* &head, int x) {
    NODE* new_node = new NODE();
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;

    // IF THERE IS NO NODE IN LIST (CORNER CASE)
    if (head == NULL) {
        head = new_node;
        return;
    }

    NODE* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    new_node->prev = current;
}

// FUNCTION TO PRINT NODES
void print(struct NODE* &head) {
    if (head == NULL) {
        cout << "LIST IS EMPTY" << endl;
        return;
    }

    NODE* current = head;

    while (current != NULL) {
        cout << current->data << ", ";
        current = current->next;
    }
    cout << endl;
}

// FUNCTION TO FIND LARGEST, SMALLEST, TOTAL, AND AVERAGE OF ELEMENTS OF LINKED LIST
void calculation(struct NODE* &head) {
    NODE* temp = head;

    int count = 0, max = 0, min = temp->data, total = 0, avg = 0;

    if (head == NULL) {
        cout << "LIST IS EMPTY" << endl;
        return;
    }

    while (temp != NULL) {
        if (temp->data > max)
            max = temp->data;

        if (temp->data <= min)
            min = temp->data;

        total = total + temp->data;
        temp = temp->next;

        count++;
    }

    avg = total / count;

    cout << "\nSMALLEST ELEMENT IS : " << min << endl;
    cout << "\nLARGEST ELEMENT IS : " << max << endl;
    cout << "\nTOTAL OF ELEMENTS IS : " << total << endl;
    cout << "\nAVERAGE OF ELEMENTS IS : " << avg << endl;
}

// MAIN FUNCTION
int main() {
    NODE* head1 = NULL;

    insert_end(head1, 1);
    insert_end(head1, 2);
    insert_end(head1, 3);
    insert_end(head1, 4);
    insert_end(head1, 5);
    insert_end(head1, 6);
    insert_end(head1, 7);

    cout << "PRINT BEFORE CALCULATION FUNCTION" << endl;
    print(head1);

    // calling calculate function
    calculation(head1);

    return 0;
}

