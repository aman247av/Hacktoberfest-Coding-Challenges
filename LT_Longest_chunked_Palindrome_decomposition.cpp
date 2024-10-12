// https://leetcode.com/problems/longest-chunked-palindrome-decomposition/description/?envType=problem-list-v2&envId=greedy

#include <string>
using namespace std;

class Solution {
public:
    int longestDecomposition(string s) {
        int left = 0, right = s.length() - 1;
        int chunk_count = 0;

        while (left < right) {
            // Find the matching start and end substrings
            if (s.substr(0, left + 1) == s.substr(right, left + 1)) {
                chunk_count += 2;  // Two matching chunks found
                s = s.substr(left + 1, right - left - 1);  // Update s to remaining substring
                left = 0;
                right = s.length() - 1;  // Reset pointers
            } else {
                left++;
                right--;
            }
        }

        // Add one if there's any substring left (middle character)
        if (!s.empty()) {
            chunk_count++;
        }

        return chunk_count;
    }
};
