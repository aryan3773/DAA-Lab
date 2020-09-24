#include<iostream>
#include<math.h>
#include<climits>
#define ll long long int
using namespace std;

// Defining Linked List
struct Node{
    int value;
    struct Node* next;
};

// Printing a given Linked List
void print_linkedList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        if(temp->next != NULL){
            cout << temp->value << " -> ";
        }
        else{
            cout << temp->value << endl;
        }
        
        temp = temp->next;
    }
}

// Adding the node at the end of Linked List
void append(struct Node** head, ll data){
    struct Node* temp = new Node();
    struct Node* last = *head;
    
    temp->value = data;
    temp->next = NULL;
    
    if(*head == NULL){
        *head =  temp;
        return;
    }
    
    while(last->next != NULL){
        last = last->next;
    }

    last -> next = temp;
}

// Function for splitting a linked list into 2 linked lists from middle
void split_linkedList(Node* head, Node** x, Node** y){
    struct Node* temp1; 
    struct Node* temp2; 
    temp1 = head; 
    temp2 = head->next; 
  
    while (temp2 != NULL){ 
        temp2 = temp2->next;
        
        if (temp2 != NULL){
            temp1 = temp1->next; 
            temp2 = temp2->next;
        }
    }
    
    *x = head;
    *y = temp1->next;
    temp1->next = NULL;
}

// Function for merging 2 sorted linked list
Node* merge(Node* x, Node* y) 
{ 
    struct Node* ans=NULL;
    
    // If the first linked list is empty then return the second linked list
    if (x == NULL)
        return y;
        
    // If the second linked list is empty then return the first linked list
    else if (y == NULL) 
        return x; 
  
    if (x->value <= y->value) { 
        ans = x; 
        ans->next = merge(x->next, y); 
    } 
    else { 
        ans = y; 
        ans->next = merge(x, y->next); 
    } 
    return ans; 
}

void merge_sort(Node** head){
    struct Node* temp = *head;
    
    // Defining 2 nodes which will be used for dividing the original Linked List
    struct Node* x;
    struct Node* y;
    
    // Handling base case i.e if length of Linked List is 1 or 0
    if((temp == NULL) or (temp->next == NULL)){
        return ;
    }
    
    split_linkedList(temp, &x, &y);
    
    merge_sort(&x);
    merge_sort(&y);
    
    *head = merge(x, y);
}

int main(){
    // n is the size of Linked List
    ll n, temp;
    cin >> n;
    
    struct Node* head = NULL;
    
    // Taking Linked List as input
    for(ll i=0; i<n; i++){
        cin >> temp;
        append(&head, temp);
    }
    
    // Sorting the Linked List using Insertion Sort
    merge_sort(&head);
    
    // Printing the array
    print_linkedList(head);
    return 0;
}