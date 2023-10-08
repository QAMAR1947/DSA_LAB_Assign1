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

// FUNCTION TO CHECK NON_ZERO, ODD, AND EVEN ELEMENTS
void count(struct NODE* & head){
	int non_zero = 0;
	int odd = 0;
	int even = 0;
	
	NODE* temp = head;
	if(head == NULL){
		cout<<"NO ELEMENT IN LIST"<<endl;
		return;
	}
	
	while(temp != NULL){
		// count all non_zero values
		if(temp->data != 0){
			non_zero ++;
			
			// count even values
			if(temp->data % 2 == 0){
				even ++;
			}
			
			//count odd values
			if(temp->data % 2 == 1){
				odd ++;
			}	
		}
		
		temp = temp->next;
		
	}
	
	cout<<"\nNON_ZERO VALUES : "<<non_zero<<endl;
	cout<<"\nEVEN VALUES : "<<even<<endl;
	cout<<"\nODD VALUES : "<<odd<<endl;
}


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

// MAIN FUNCTION
int main(){
	NODE* head1 = NULL;
	
	insert_end(head1,1);
	insert_end(head1,2);
	insert_end(head1,3);
	insert_end(head1,4);
	insert_end(head1,5);
	insert_end(head1,6);
	insert_end(head1,7);
	
	
	cout<<"PRINT BEFORE COUNT FUNCTION"<<endl;
	print(head1);
	
	// calling count function
	count(head1);
	
	return 0;
}
