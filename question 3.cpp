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

// FUNCTION TO COPY 1 LIST TO ANOTHER
void copy(struct NODE* &head1, struct NODE* &head2){
	while(head1 != NULL){
		insert_end(head2, head1->data);		// everytime create new node of list 2 and save value of list 1 into it
		head1 = head1->next;
	}
}

// MAIN FUNCTION
int main(){
	
	NODE* head1 = NULL;
	NODE* head2 = NULL;
	
	// adding nodes of list 1
	insert_end(head1,10);
	insert_end(head1,11);
	insert_end(head1,12);
	insert_end(head1,13);

	// printing nodes of list 1
	cout<<"VALUE OF LIST 1"<<endl;
	print(head1);
	
	// calling copying function
	copy(head1,head2);
	
	// printing nodes of list 2 after copying function call
	cout<<"\nVALUE OF LIST 2 AFTER COPYING"<<endl;
	print(head2);	
	
	return 0;
}
