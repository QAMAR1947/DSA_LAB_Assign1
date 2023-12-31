#include <iostream>
using namespace std;

// Define a struct for a linked list node
struct NODE {
    int coff;
    int exp;
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
		cout<<current->coff<<" x";
		cout<<current->exp<<", ";
		current = current->next;
	}
	cout<<endl;
	
}

// FUNCTION TO INSERT NODE AS POLYNOMIAL IN DESCENDING ORDER
void insert(struct NODE* &head, int coffecient, int exponent){
	
	NODE* new_node = new NODE();
	new_node->coff = coffecient;
	new_node->exp = exponent;
	new_node->next = NULL;
	
	
	if(head == NULL || new_node->exp > head->exp){
		new_node->next = head;
		head = new_node;
		return;
		}
		
	NODE* temp = head;
	while(temp->next != NULL && temp->next->exp > new_node->exp){
		temp = temp->next;
	}
	new_node->next = temp->next;
	temp->next = new_node;
	
}

// FUNCTION TO MULTIPLY A NUMBER WITH POLYNOMIAL
void mult(struct NODE* head, int num){
	NODE* temp = head;
	int number = num;
	
	while(temp != NULL){
		temp->coff = number * temp->coff;
		cout<<temp->coff<<" x";
		cout<<temp->exp<<", ";
		temp = temp->next;
	}
	
}

// MAIN FUNCTION
int main(){
	NODE* head = NULL;
	
	insert(head,5,4);
	insert(head,4,3);
	insert(head,3,2);
	insert(head,2,1);
	
	cout<<"PRINTING POLYNOMIAL BEFORE MULTIPLYING WITH NUMBER"<<endl;
	print(head);
	
	cout<<"PRINTING POLYNOMIAL AFTER MULTIPLYING WITH NUMBER"<<endl;
	mult(head, 3);
	
	
	return 0;
}
