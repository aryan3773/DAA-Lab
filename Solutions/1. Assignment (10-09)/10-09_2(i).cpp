#include<iostream>
#include<math.h>
#include<climits>
#define ll long long int
using namespace std;

// Function for finding gcd of 2 numbers
ll gcd(ll x, ll y){
    if(y == 0){
        return x;
    }
    return gcd(y, x%y);
}

// 2 numbers are co-prime when their gcd is 1
void findPair(ll x[], ll n){
    for(ll i=0; i<n-1; i++){
        for(ll j=i+1; j<n; j++){
            if(gcd(x[i], x[j]) == 1){
                cout << "(" << x[i] << ", " << x[j] << ")" << " ";
            }
        }
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
    
    // Printing the final answer
    findPair(x, n);
    return 0;
}