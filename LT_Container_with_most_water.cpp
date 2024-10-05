// Problem Link : https://leetcode.com/problems/container-with-most-water/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int> &height)
{
    int left = 0;                  // Left pointer
    int right = height.size() - 1; // Right pointer
    int maxArea = 0;               // Variable to store the maximum area

    while (left < right)
    {
        // Calculating the width and height of the container
        int width = right - left;
        int h = min(height[left], height[right]); // The height is determined by the shorter line
        maxArea = max(maxArea, width * h);        // Updating maxArea if the current area is larger

        // Move the pointer pointing to the shorter line
        if (height[left] < height[right])
        {
            left++; // Move left pointer to the right
        }
        else
        {
            right--; // Move right pointer to the left
        }
    }

    return maxArea; // Return the maximum area found
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = maxArea(height);
    cout << "Input: [";
    for (int h : height)
    {
        cout << h << " ";
    }
    cout << "], Output: " << result << endl;
    return 0;
}