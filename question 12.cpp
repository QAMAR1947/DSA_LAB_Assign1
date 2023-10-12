#include<iostream>
#include<string>
using namespace std;

// CREATING STRUCTURE OF LINKED LIST
struct NODE{
	char data;
	NODE* next;
};

// FUNCTION TO INSERT NODE AT THE END OF LIST
void insert_end(struct NODE* &head, char x){	
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
	NODE* head2 = NULL;
	
	string num;
	
	cout<<"ENTER A NUMBER"<<endl;
	cin>>num;
	
	int size = num.length();
	
	for(int i=0; i<size; i++){
		insert_end(head1,num[i] );
	}
	print(head1);
	return 0;
	
}
