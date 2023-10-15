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

// FUNCTION TO SWAP TWO NODES OF DOUBLE LINKED LIST
void swap(struct NODE* &head, int pos1, int pos2) {
    // First, count the total nodes in the list
    int count = 0;
    NODE* ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    // Swapping the nodes
    if (head == NULL) {
        cout << "NO NODES EXIST" << endl;
        return;
    }

    // If 1 node exists
    if (head->next == NULL) {
        cout << "NOT POSSIBLE WITH 1 NODE" << endl;
        return;
    }

    // If 2 nodes exist
    if (count == 2) {
        NODE* temp = head->next;
        head->next = temp->next;
        temp->next = head;
        head->prev = temp; // Update the prev pointer
        temp->prev = NULL; // Set temp's prev to NULL
        head = temp;
        print(head);
        return;
    }

    // If 3 nodes exist
    if (count == 3) {
        NODE* P_N = head;
        NODE* C_N = head->next;
        NODE* L_N = C_N->next;

        // Corner case (if positions are the same)
        if (pos1 == pos2) {
            cout << "YOU ARE ENTERING WRONG POSITIONS" << endl;
            return;
        }

        // Case 1 (last 2 nodes)
        if ((pos1 == 2 && pos2 == 3) || (pos1 == 3 && pos2 == 2)) {
            C_N->next = L_N->next;
            P_N->next = L_N;
            L_N->next = C_N;
            if (L_N->next != NULL) {
                L_N->next->prev = L_N; // Update the prev pointer for the next node
            }
            C_N->prev = L_N; // Update the prev pointer for C_N
            L_N->prev = P_N; // Update the prev pointer for L_N
            P_N->prev = NULL; // Set P_N's prev to NULL
            head = L_N;
            print(head);
            return;
        }

        // Case 2 (first 2 nodes)
        if ((pos1 == 1 && pos2 == 2) || (pos1 == 2 && pos2 == 1)) {
            P_N->next = L_N;
            C_N->next = P_N;
            L_N->prev = P_N; // Update the prev pointer for L_N
            P_N->prev = C_N; // Update the prev pointer for P_N
            C_N->prev = NULL; // Set C_N's prev to NULL
            head = C_N;
            print(head);
            return;
        }

        // Case 3 (first and last node)
        if ((pos1 == 1 && pos2 == 3) || (pos1 == 3 && pos2 == 1)) {
            P_N->next = L_N->next;
            C_N->next = P_N;
            L_N->next = C_N;
            if (P_N->next != NULL) {
                P_N->next->prev = P_N; // Update the prev pointer for the next node
            }
            C_N->prev = L_N; // Update the prev pointer for C_N
            L_N->prev = P_N; // Update the prev pointer for L_N
            P_N->prev = NULL; // Set P_N's prev to NULL
            head = L_N;
            print(head);
            return;
        }
    }

    // More than 3 nodes
    if (count > 3) {
        NODE* node1 = head;
        NODE* node2 = head;

        // Loop to reach the first node
        for (int i = 1; i < pos1; i++) {
            node1 = node1->next;
        }

        // Loop to reach the second node
        for (int j = 1; j < pos2; j++) {
            node2 = node2->next;
        }
        // Temp pointer to store node1 value
        int temp_data = node1->data;

        // Updating values
        node1->data = node2->data;
        node2->data = temp_data;

        // Printing the updated list
        print(head);
    }
}

// MAIN FUNCTION
int main() {
    NODE* head1 = NULL;

    int size, value, p1, p2;
    cout << "ENTER SIZE OF LINKED LIST" << endl;
    cin >> size;

    for (int i = 0; i < size; i++) {
        cout << "ENTER NODE'S VALUE HERE: " << endl;
        cin >> value;
        insert_end(head1, value);
    }

    cout << "PRINTING NODES BEFORE SWAPPING" << endl;
    print(head1);

    cout << "ENTER THE POSITIONS TO SWAP: " << endl;
    cin >> p1;
    cin >> p2;

    cout << "\nPRINTING NODES AFTER SWAPPING" << endl;
    swap(head1, p1, p2);

    return 0;
}

