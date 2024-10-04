// Problem Link: https://leetcode.com/problems/jump-game-ii/

class Solution {
    public int jump(int[] nums) {
        if (nums.length <= 1) {
            return 0; // If there's only one element, no jumps are needed
        }
        
        int jumps = 0; // Counter for number of jumps
        int currentEnd = 0; // The farthest index that can be reached with the current number of jumps
        int farthest = 0; // The farthest index that can be reached from the current index
        
        for (int i = 0; i < nums.length - 1; i++) {
            // Update the farthest point reachable from index i
            farthest = Math.max(farthest, i + nums[i]);
            
            // If we have reached the end of the range for the current jump
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                
                // If we can reach the last element, break the loop
                if (currentEnd >= nums.length - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }

    // Main method for testing the solution
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        int[] nums1 = {2, 3, 1, 1, 4};
        System.out.println("Minimum jumps for nums1: " + solution.jump(nums1)); // Output: 2

        int[] nums2 = {2, 3, 0, 1, 4};
        System.out.println("Minimum jumps for nums2: " + solution.jump(nums2)); // Output: 2

        int[] nums3 = {1, 2, 1, 1, 1};
        System.out.println("Minimum jumps for nums3: " + solution.jump(nums3)); // Output: 3
    }
}
