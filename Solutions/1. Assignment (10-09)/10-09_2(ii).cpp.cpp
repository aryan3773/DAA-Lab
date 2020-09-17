#include<iostream>
#include<math.h>
#include<climits>
#define ll long long int
using namespace std;

// Function to find the largest possible sub array sum
ll findLargestSum(ll x[], ll n){
    ll maximum_Sum = INT_MIN, negatives = 0;
    ll temp_Sum = 0;
    
    for(ll i=0; i<n; i++){
        if(x[i] < 0){
            negatives += 1;
        }
    }
    
    // For handling the case when all the numbers are negative other ans according to the below method will be always zero.
    // If all the numbers are negative then the maximum element of the array will be the answer
    if(negatives == n){
        // Finding maximum element of array
        for(ll i=0; i<n; i++){
            if(maximum_Sum < x[i]){
                maximum_Sum = x[i];
            }
        }
    }

    else{
        for(ll i=0; i<n; i++){
            temp_Sum += x[i];
            if(temp_Sum > maximum_Sum){
                maximum_Sum = temp_Sum;
            }
            if(temp_Sum < 0){
                temp_Sum = 0;
            }
        }
    }
    return maximum_Sum;
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
    
    // Printing the final answer
    cout << findLargestSum(x, n);
    return 0;
}