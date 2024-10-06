#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findMinSubarraySize(vector<int>& nums, int rem, int p) {
        map<int, int> prefixMod;
        prefixMod[0] = -1;
        long long currentSum = 0;
        int minLength = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            int currentRem = currentSum % p;
            int target = (currentRem - rem + p) % p;
            if (prefixMod.find(target) != prefixMod.end()) {
                minLength = min(minLength, i - prefixMod[target]);
            }
            prefixMod[currentRem] = i;
        }
        return (minLength == nums.size()) ? -1 : minLength;
    }

    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for (int num : nums) sum += num;

        int rem = sum % p;
        if (rem == 0) return 0;
        return findMinSubarraySize(nums, rem, p);
    }
};

int main() {
    Solution solution;

    vector<int> nums = {3, 1, 4, 2};
    int p = 6;

    int result = solution.minSubarray(nums, p);

    if (result == -1)
        cout << "No valid subarray found." << endl;
    else
        cout << "The minimum subarray size to remove is: " << result << endl;

    return 0;
}
