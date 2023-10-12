
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
	
	NODE* current = head;

	while (current != NULL){
		cout<<current->data<<", ";
		current = current->next;
	}
	cout<<endl;
	
}

// FUNCTION TO SWAP TWO NODES OF SINGLE LINK LIST
void swap(struct NODE* &head, int pos1, int pos2){
	// first we'll count total nodes in list
	int count = 0;
	NODE* ptr = head;
	while(ptr != NULL){
		count ++;
		ptr = ptr->next;
	}
	
	// swaping the nodes
	if(head == NULL){
		cout<<"NO NODES EXIST"<<endl;
		return;
	}
	
	// if 1 node exist
	if(head->next == NULL){
		cout<<"NOT POSSIBLE WITH 1 NODE"<<endl;
		return;
	}
	
	// if 2 nodes exist
	if(count == 2){
		NODE* temp = head->next;
		head->next = temp->next;
		temp->next = head;
		head = temp;
		print(head);
		return;
	}
	
	// if 3 nodes exist
	if(count == 3){
		NODE* P_N = head;
		NODE* C_N = head->next;
		NODE* L_N = C_N->next;
		
		// corner case (if positions are same)
		if(pos1 == pos2){
			cout<<"YOU ARE ENTERING WRONG POSITIONS"<<endl;
			return;
		}
		
		//case 1 (last 2 nodes)
		if((pos1 == 2 && pos2 == 3) || (pos1 == 3 && pos2 == 2)){
			C_N->next = L_N->next;
			P_N->next = L_N;
			L_N->next = C_N;
			print(head);
			return;
		}
		
		//case 2 (first 2 nodes)
		if((pos1 == 1 && pos2 == 2) || (pos1 == 2 && pos2 == 1)){
			P_N->next = L_N;
			C_N->next = P_N;
			head = C_N;
			print(head);
			return;
		}
		
		// case 3 (first and last node)
		if((pos1 == 1 && pos2 == 3) || (pos1 == 3 && pos2 == 1)){
			P_N->next = L_N->next;
			C_N->next = P_N;
			L_N->next = C_N;
			head = L_N;
			print(head);
			return;
		}
	}
	
	// more than 3 nodes
	if(count > 3)
	{
		NODE* node1 = head;
		NODE* node2 = head;
		
		// loop to reach 1st node
		for(int i=1; i<pos1; i++){
			node1 = node1->next;
		}
		
		// loop to reach 2nd node
		for(int j=1; j<pos2; j++){
			node2 = node2->next;
		}
		// temp pointer to store node1 value
		NODE* temp = new NODE();
		temp->data = node1->data;
		
		// updating values
		node1->data = node2->data;
		node2->data = temp->data;
		
		// printing updated list
		print(head);
	}
	
	
}

// MAIN FUNCTION
int main(){
	NODE* head1 = NULL;
	
	int size, value, p1, p2;
	cout<<"ENTER SIZE OF LINK LIST"<<endl;
	cin>>size;
	
	for(int i=0; i<size; i++){
		cout<<"ENTER NODE'S VALUE HERE : "<<endl;
		cin>>value;
		insert_end(head1, value);
	}
		
	cout<<"PRINTING NODES BEFORE SWAPING"<<endl;
	print(head1);
	
	cout<<"ENTER THE POSITIONS TO SWAP : "<<endl;
	cin>>p1;
	cin>>p2;
	
	cout<<"\nPRINTING NODES AFTER SWAPING"<<endl;
	swap(head1, p1, p2);
	
	return 0;
}
