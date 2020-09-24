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


void insertion_sort(struct Node** head){
    // Sorted Linked List initialization
    struct Node* ans = NULL;
    
    struct Node* temp = *head;
    while(temp != NULL){
        struct Node* next = temp->next;
        
        struct Node* temp2 = ans;
        if((ans == NULL) or (ans->value >= temp->value)){
            temp->next = ans;
            ans = temp;
        }
        
        else{
            while((temp2->next != NULL) and (temp2->next->value < temp->value)){
                temp2 = temp2->next;
            }
            
            temp->next = temp2->next;
            temp2->next = temp;
        }
        
        temp = next;
    }
    
    *head = ans;
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
    insertion_sort(&head);
    
    // Printing the array
    print_linkedList(head);
    return 0;
}