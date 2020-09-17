#include<iostream>
#include<math.h>
#include<climits>
#define ll long long int
using namespace std;

// Recursive insertion sort
void insertion_sort_recursion(ll x[], ll n){
    if(n == 0 or n == 1){
        return ;
    }
    
    insertion_sort_recursion(x, n-1);
    
    ll temp = x[n-1];
    ll index = n-2;
    
    while(index >= 0 and temp < x[index]){
        x[index+1] = x[index];
        index -= 1;
    }
    x[index+1] = temp;
}

int main(){
    // Taking size of array as an input
    ll n;
    cin >> n;
    
    // Defining array and taking it's element as an input
    ll x[n];
    for(ll i=0; i<n; i++){
        cin >> x[i];
    }
    
    // Sorting the array using insertion sort
    insertion_sort_recursion(x, n);
    
    // Printing the array
    for(ll i=0; i<n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    return 0;
}