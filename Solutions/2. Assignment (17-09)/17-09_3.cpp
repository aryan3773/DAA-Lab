#include<iostream>
#include<math.h>
#include<climits>
#define ll long long int
using namespace std;

// Function for merging 2 sorted arrays
void merge(ll x[], ll low, ll mid, ll high){
    ll i=0, j=0, k=0;
    
    // finding the size of 2 divided arrays using the indices
    ll size1 = mid-low+1, size2 = high-mid;
    
    // Creating 2 temporary arrays for accessing the elements from actual array and
    // later modify the array
    ll temp1[size1], temp2[size2];
    
    for(ll i=0; i<size1; i++){
        temp1[i] = x[low + i];
    }
    
    for(ll j=0; j<size2; j++){
        temp2[j] = x[mid + 1 + j];
    }
    
    // Reinitializing i, j and k
    i = 0; j = 0; k = low;
    
    while(i < size1 and j < size2){
        if(temp1[i] <= temp2[j]){
            x[k] = temp1[i];
            i += 1;
            k += 1;
        }
        
        if(temp1[i] > temp2[j]){
            x[k] = temp2[j];
            j += 1;
            k += 1;
        }
    }
    
    // One of the array will be completly accessed before another
    // Checking temp1 is remaining to be accessed
    while(i < size1){
        x[k] = temp1[i];
        i += 1;
        k += 1;
    }
    
    // Checking temp1 is remaining to be accessed
    while(j < size2){
        x[k] = temp2[j];
        j += 1;
        k += 1;
    }
}

// Merge Sort using divide and conquer
// Approach - 1
void merge_sort(ll x[], ll low, ll high){
    if(low < high){
        // ll mid = (low + high)/2;
        // To avoid integer overflow for large values of low and high
        
        ll mid = low + (high - low)/2; 
        merge_sort(x, low, mid);
        merge_sort(x, mid+1, high);
        
        merge(x, low, mid, high);
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
    
    // Sorting the array using merge sort
    merge_sort(x, 0, n-1);
    
    // Printing the array
    for(ll i=0; i<n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    return 0;
}