#include<iostream>
using namespace std;

// CREATING STRUCTURE OF LINKED LIST
struct NODE{
	int data;
	NODE* next;
};

// GLOBAL VARIABLE TO COUNT TOTAL NODES
int count = 0;

// FUNCTION TO INSERT NODE AT THE END OF LIST
void insert_end(struct NODE* &head, int x){	
	NODE* new_node = new NODE();
	new_node -> data = x;
	new_node -> next = NULL; 
	
		// IF THERE IS NO NODE IN LIST (CORNER CASE)
		if(head == NULL){
		head = new_node;
		count ++;
		return;
	}
	
	NODE *current = head;
	
	while(current -> next != NULL){
		current = current->next;
	}
	current->next = new_node;
	
	count ++;
	
}

// FUNCTION TO SPLIT LIST INTO TWO PARTS
void split(struct NODE* &head1){
	// head1, list1, and list2 are local variables of this function 
	NODE* temp1 = head1;
	if(head1 == NULL || head1->next == NULL){
		return;
	}
	
	// EVEN CASE 
	if (count % 2 == 0){
		for(int i=0 ; i<count/2 ; i++){
			cout<<temp1->data;
			temp1 = temp1->next;
		}
		cout<<endl;
		for(int i=0 ; i<count/2 ; i++){
			cout<<temp1->data;
			temp1 = temp1->next;
		}
	}
	
	if (count % 2 == 1){
		for(int i=0 ; i<int(count/2)+1 ; i++){
			cout<<temp1->data;
			temp1 = temp1->next;
		}
		cout<<endl;
		for(int i=0 ; i<int(count/2); i++){
			cout<<temp1->data;
			temp1 = temp1->next;
		}
	}
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
	
	insert_end(head1, 1);
	insert_end(head1, 2);
	insert_end(head1, 3);
	insert_end(head1, 4);
	insert_end(head1, 5);
	insert_end(head1, 6);
	insert_end(head1, 7);
	
	
	split(head1);
	
	
	return 0;
}
