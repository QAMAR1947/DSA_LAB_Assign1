#include<iostream>
using namespace std;

// CREATING STRUCTURE OF LINKED LIST
struct NODE{
	int data;
	NODE* next;
};

// FUNCTION TO INSERT NODE AT THE END OF LIST
void insert_end(struct NODE* &head, int x){	
	NODE* new_node = new NODE();
	new_node -> data = x;
	new_node -> next = NULL; 
	
		// IF THERE IS NO NODE IN LIST (CORNER CASE)
		if(head == NULL){
		head = new_node;
		return;
	}
	
	NODE *current = head;
	
	while(current -> next != NULL){
		current = current->next;
	}
	current->next = new_node;
	
}

// FUNCTION TO REMOVE FIRST NODE AND ADD AT THE END
void first_node(struct NODE* &head){
	NODE* current_node = head;
	
	while(current_node->next->next != NULL){
		current_node = current_node->next;
	}
	NODE* last_node = current_node->next;
	last_node->next = head;
	head = current_node->next;
	current_node->next = NULL;
}

// FUNCTION TO PRINT NODES
void print(struct NODE* &head){
	
	if(head == NULL){
		cout<<"LIST IS EMPTY"<<endl;
		return;
	}
	
	NODE* current = new NODE();
	current = head;
	
	while (current != NULL){
		cout<<current->data<<", ";
		current = current->next;
	}
	cout<<endl;
	
}

// MAIN FUNCTION
int main(){
	NODE* head = NULL;
	
	// inserting nodes in list
	insert_end(head,10);
	insert_end(head,11);
	insert_end(head,12);
	insert_end(head,13);
	insert_end(head,14);
	
	// printing nodes of list
	print(head);
	
	// calling our end_node function
	first_node(head);
	
	// printing nodes of list after end_node function
	print(head);
	
	return 0;
}
