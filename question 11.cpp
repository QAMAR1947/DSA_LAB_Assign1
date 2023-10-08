#include <iostream>
using namespace std;

// Define a struct for a linked list node
struct NODE {
    int data;
    NODE* next;
};

// FUNCTION TO PRINT NODES
void print(struct NODE* &head){
	
	if(head == NULL){
		cout<<"LIST IS EMPTY"<<endl;
		return;
	}
	
	NODE* current = head;

	while (current != NULL){
		cout<<current->data<<", ";
		current = current->next;
	}
	cout<<endl;
	
}

// Function to insert a new node in descending order
void insertDescending(struct NODE* &head, int value){
	NODE* new_node = new NODE();
	new_node->data = value;
	new_node->next = NULL;
	
	if(head == NULL || value >= head->data){
		new_node->next = head;
		head = new_node;
	}
	else
	{
		NODE* current_node = head;
		while(current_node->next != NULL && current_node->next->data > value){
			current_node = current_node->next;
		}
		new_node->next = current_node->next;
		current_node->next = new_node;
	}
}


int main() {
    NODE* head = NULL;

    // Insert elements in descending order
    insertDescending(head, 5);
    insertDescending(head, 10);
    insertDescending(head, 2);
    insertDescending(head, 8);

    // Print the sorted linked list
    cout<< "Sorted Linked List: "<<endl;;
    print(head);

    

    return 0;
}

