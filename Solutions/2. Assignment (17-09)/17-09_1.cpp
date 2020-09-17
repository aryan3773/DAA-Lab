#include<iostream>
#include<math.h>
#include<climits>
#define ll long long int
using namespace std;

// Function for swapping two integers
void swap(ll &x, ll &y){
    ll temp = x;
    x = y;
    y = temp;
}

// Insertion Sort Function (inplace)
void insertion_sort(ll x[], ll n){
    ll temp;
    for(ll i=1; i<n; i++){
        temp = x[i];
        ll j = i-1;
        while(j >= 0 and temp < x[j]){
            x[j+1] = x[j];
            j -= 1;
        }
        x[j+1] = temp;
    }
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
    insertion_sort(x, n);
    
    // Printing the array
    for(ll i=0; i<n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    return 0;
}