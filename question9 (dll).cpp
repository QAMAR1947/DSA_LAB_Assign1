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

// FUNCTION TO STORE ODD AND EVEN ELEMENTS IN SEPARATE LISTS
void separate(struct NODE* &head, struct NODE* &list1, struct NODE* &list2) {
    NODE* temp1 = head;
    NODE* temp2 = head;

    // if no node exists
    if (head == NULL) {
        cout << "LIST IS EMPTY" << endl;
        return;
    }

    // if only 1 node exists
    if (head->next == NULL) {
        cout << "ONLY 1 NODE" << endl;
        return;
    }

    while (temp1 != NULL) {
        // for even value of node
        if (temp1->data % 2 == 0) {
            insert_end(list1, temp1->data);
        }

        // for odd value of node
        if (temp1->data % 2 == 1) {
            insert_end(list2, temp1->data);
        }

        // updating addresses
        temp1 = temp1->next;
        if (temp1 != NULL) {
            head = temp1;
            delete (temp2);
            temp2 = temp1;
        }
    }
}

// MAIN FUNCTION
int main() {
    NODE* head1 = NULL;
    NODE* list1 = NULL;
    NODE* list2 = NULL;

    insert_end(head1, 1);
    insert_end(head1, 2);
    insert_end(head1, 3);
    insert_end(head1, 4);
    insert_end(head1, 5);

    cout << "PRINT BEFORE SEPARATE FUNCTION" << endl;
    print(head1);

    // calling separate function
    separate(head1, list1, list2);

    cout << "\nPRINT MAIN LIST AFTER SEPARATE FUNCTION" << endl;
    print(head1);

    cout << "\nPRINT LIST 1 (EVEN) AFTER SEPARATE FUNCTION" << endl;
    print(list1);
    cout << "\nPRINT LIST 2 (ODD) AFTER SEPARATE FUNCTION" << endl;
    print(list2);

    return 0;
}

