#include<iostream>
#include<math.h>
#include<climits>
#define ll long long int
using namespace std;

// Function for printing array
void print_array(ll x[], ll n){
    for(ll i=0; i<n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

// Function for swapping 2 integers
void swap(ll &x, ll &y){
    ll temp = x;
    x = y;
    y = temp;
}

// Function for partitioning array using middle element as a pivot
ll partition(ll x[], ll start, ll end){
    // Find the middle element of the array
    ll middle = start + (end - start)/2;
    
    // swapping middle element with the last element so now middle element will be pivot
    swap(x[middle], x[end]);
    
    ll pivot = x[end];
    ll i = start - 1;
    
    for(ll j=start; j<end; j++){
        if(x[j] < pivot){
            i += 1;
            swap(x[i], x[j]);
        }
    }
    i += 1;
    swap(x[i], x[end]);
    return i;
}

// Function for Quick sort
void quick_sort(ll x[], ll start, ll end){
    if(start < end){
        ll i = partition(x, start, end);
        //cout << i << endl; -> To get which index were chosen
        quick_sort(x, start, i-1);
        quick_sort(x, i+1, end);
    }
}

int main(){
    // n is the size of array
    ll n;
    cin >> n;
    
    // Taking array as input
    ll x[n];
    for(ll i=0; i<n; i++){
        cin >> x[i];
    }
    
    // Applying quicksort to the array
    quick_sort(x, 0, n-1);
    
    // Printing the array
    print_array(x, n);
    return 0;
}