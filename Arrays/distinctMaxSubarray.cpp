/*
2461. Maximum Sum of Distinct Subarrays With Length K
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxi = 0;
        unordered_map<int ,int> mpp;  
        long long sum = 0;

        // We use a sliding window technique
        for (int i = 0; i < nums.size(); i++) {
            // Add the current element to the sum and set
            sum += nums[i];
            mpp[nums[i]]++;
            
            // If the window exceeds size k, remove the leftmost element from the window
            if (i >= k) {
                sum -= nums[i - k];
                mpp[nums[i-k]]--;

                if(mpp[nums[i-k]]==0)
                    mpp.erase(nums[i - k]);
            }
            
            // If the window has exactly k elements and all are unique
            if (mpp.size() == k && i >= k - 1) {
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};

