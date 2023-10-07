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

// FUNCTION TO CONCATENATE TWO LIST
void concatenate(struct NODE* &head1, struct NODE* &head2){
	NODE* temp = head1;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = head2;
}

int main(){
	
	NODE* head1 = NULL;
	NODE* head2 = NULL;
	
	// adding nodes of list 1
	insert_end(head1,10);
	insert_end(head1,11);
	insert_end(head1,12);
	insert_end(head1,13);

	// adding nodes of list 2
	insert_end(head2,14);
	insert_end(head2,15);
	insert_end(head2,16);
	insert_end(head2,17);	
	
	// printing nodes of list 1
	cout<<"VALUE OF LIST 1"<<endl;
	print(head1);
	
	// printing nodes of list 2
	cout<<"\nVALUE OF LIST 2"<<endl;
	print(head2);
	
	// CONCATENATE FUNCTION CALL
	concatenate(head1,head2);

	// printing nodes of list 1 after concatenation
	cout<<"\nVALUE OF LIST 1 AFTER CONCATENATION"<<endl;
	print(head1);	
	
	return 0;
}
