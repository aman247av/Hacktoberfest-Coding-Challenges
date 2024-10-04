// Problem Link: https://codeforces.com/problemset/problem/2020/B

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t; // Read number of test cases

    while (t--) {
        int n;
        cin >> n; // Read number of names
        
        vector<string> names(n); // Vector to store names
        unordered_set<string> uniqueNames; // Set to store unique names
        
        // Reading names
        for (int i = 0; i < n; ++i) {
            cin >> names[i];
            uniqueNames.insert(names[i]);
        }

        // Process to calculate result (example logic, based on problem requirements)
        int result = 0;
        for (char first = 'a'; first <= 'z'; ++first) {
            for (char second = 'a'; second <= 'z'; ++second) {
                string newName = string(1, first) + string(1, second);
                if (uniqueNames.find(newName) == uniqueNames.end()) {
                    // Check for unique new names logic
                    result++;
                }
            }
        }

        cout << result << endl; // Output the result for each test case
    }

    return 0;
}
