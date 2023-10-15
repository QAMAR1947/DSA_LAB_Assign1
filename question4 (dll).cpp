#include<iostream>
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

// FUNCTION TO REMOVE FIRST NODE AND ADD AT THE END
void end_node(struct NODE* &head) {
    if (head == NULL) {
        return;
    }
    
    NODE* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    NODE* temp2 = head;
    head = temp2->next;
    temp2->next = NULL;
    temp2->prev = temp;
    temp->next = temp2;
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
    NODE* head = NULL;

    // inserting nodes in list
    insert_end(head, 10);
    insert_end(head, 11);
    insert_end(head, 12);
    insert_end(head, 13);
    insert_end(head, 14);

    // printing nodes of list
    cout << "Value of List:" << endl;
    print(head);

    // calling our end_node function
    end_node(head);
    end_node(head);
    end_node(head);

    // printing nodes of list after end_node function
    cout << "\nValue of List after end_node function:" << endl;
    print(head);

    return 0;
}

