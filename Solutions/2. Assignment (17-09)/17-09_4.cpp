#include<iostream>
#include<math.h>
#include<climits>
#define ll long long int
using namespace std;

// Function for merging 2 sorted arrays in constant space
// Using two pointers Approach

void merge(ll x[], ll low, ll mid, ll high){
    ll i = mid + 1;
    
    // If the last element of first array is less than or equal to the first element of the second array
    // then we will simply merge the arrays as the resultant array will also be sorted.
    // eg - [1, 3, 6] and [7, 8, 9]. Here, we can directly merge the 2 arrays
    if(x[mid] <= x[i]){
        return ;
    }
    
    while(low <= mid and i <= high){
        if(x[low] <= x[i]){
            low += 1;
        }
        
        else{
            ll temp = x[i], j = i;
            
            // We will shift the elements between low and index j
            while(j != low){
                x[j] = x[j-1];
                j -= 1;
            }
            // Put the value of temp at low
            x[low] = temp;
            i += 1;
            low += 1;
            mid += 1;
        }
    }
}

// Function for inplace Merge Sort
// Approach - 2
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