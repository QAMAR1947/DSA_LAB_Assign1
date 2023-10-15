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

// FUNCTION TO CHECK TOTAL OCCURRENCE OF AN ELEMENT
void occur(struct NODE* &head, int value) {
    int count = 0;

    NODE* temp = head;
    if (head == NULL) {
        cout << "NO ELEMENT IN LIST" << endl;
        return;
    }

    while (temp != NULL) {
        if (value == temp->data) {
            count++;
        }

        temp = temp->next;
    }

    cout << "THE NUMBER " << value << " OCCURRED " << count << " TIMES" << endl;
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

// MAIN FUNCTION
int main() {
    NODE* head1 = NULL;

    insert_end(head1, 10);
    insert_end(head1, 11);
    insert_end(head1, 10);
    insert_end(head1, 13);
    insert_end(head1, 10);
    insert_end(head1, 12);
    insert_end(head1, 10);

    cout << "PRINT BEFORE OCCUR FUNCTION" << endl;
    print(head1);

    // calling occur function
    occur(head1, 10);

    return 0;
}

