#include<iostream>
#include<math.h>
#include<climits>
#define ll long long int
using namespace std;

// Insert and Delete functions have been written by assuming 1 based indexing

// Defining Linked List
struct Node{
    int value;
    Node* next;
};

// Function for adding the node with value 'val' at the end of linked list
void append(Node** head, int val){
    Node* temp = new Node();
    Node* last = *head;
  
    temp->value = val;
    temp->next = NULL;  

    if (*head == NULL)
    {  
        *head = temp;  
        return;
    }  
  
    while(last->next != NULL)  
        last = last->next;  
  
    last->next = temp;  
    return;  
} 

// Function for inserting a node at a specified position
void Insert(Node** head, ll position, ll val){
    Node* temp = new Node();
    Node* iterate = *head;
    
    temp->value = val;
    temp->next = NULL;
    
    ll i = 0;
    while(i < position-2){
        iterate = iterate->next;
        i += 1;
    }
    
    temp->next = iterate->next;
    iterate->next = temp;
}

// Function for deleting a node at specified position
void Delete(Node** head, ll position){
    Node* iterate = *head;
    ll i=0;
    while(i < position-2){
        iterate = iterate->next;
        i += 1;
    }
    
    Node* temp = iterate->next->next;
    iterate->next = temp;
}

// Function for reversing a linked list
Node* Reverse(Node* head){
    Node *temp, *back, *forward; 
    back = NULL;
    temp = head;
    
    while(temp != NULL){
        forward = temp->next;
        temp->next = back;
        back = temp;
        temp = forward;
    }
    head = back;
}

// Printing a linked list
void print_Linked_List(Node *node){
    while(node != NULL){
        if(node->next != NULL){
            cout << node->value << " -> ";
        }
        else{
            cout << node->value << endl;
        }
        node = node->next;
    }
}

int main(){
    // Initializing head of Linked list
    Node* head = NULL;
    
    // Taking number of nodes as input
    ll n, a;
    cin >> n;
    
    // Taking the node values and inserting the node at the end of linked list
    for(ll i=0; i<n; i++){
        cin >> a;
        append(&head, a);
    }
    
    // Inserting a node with value 12 at position 2
    Insert(&head, 2, 12);
    print_Linked_List(head);
    
    // Deleting the node at position 5
    Delete(&head, 5);
    print_Linked_List(head);
    
    // Reversing the linked list
    head = Reverse(head);
    print_Linked_List(head);
}