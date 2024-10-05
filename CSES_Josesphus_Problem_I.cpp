// Problem Link : https://cses.fi/problemset/task/2162
#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n; // Read number of children present in the circle
    set<ll> arr; // Set to store all children

    // Inserting children 1 to n in the set
    for(int i=1; i<=n; i++){
        arr.insert(i);
    }

    auto it = arr.begin(); // Iterator pointing towards the child that will be removed

    // Repeat the process until no child is left in the circle
    while(arr.size()){
        it++; // As the part of the game, we skip over 1 child

        // If we have reached the end of the circle then we go back to the beginning of the circle
        if(it==arr.end()){
            it=arr.begin();
        }
        cout << *it << " "; // Print the child about to be removed
        it = arr.erase(it); // Erase the current child from the set. Returns the iterator pointing towards the next child in the circle

        // If we have reached the end of the circle then we go back to the beginning of the circle
        if(it==arr.end()){
            it=arr.begin();
        }
    }
}