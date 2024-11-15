// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
// Example 1:

// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
// Example 2:

// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
#include <bits/stdc++.h>

using namespace std;

    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxLen = 0;
        int endIdx = -1;

        for(int i =0;i<n;i++){
            nums[i] = (nums[i] == 0) ? -1 : 1 ;
        }

        unordered_map<int,int>mpp;

        for(int i =0;i<n;i++){
            sum += nums[i];

            if(sum == 0){
                maxLen = i+1;
                // endIdx = i;
            }

            if(mpp.find(sum) != mpp.end()){
                if(maxLen < i - mpp[sum]){
                    maxLen = i- mpp[sum];
                    // endIdx = i;
                }
            }else{
                mpp[sum] = i;
            }
            
        }
        
        return maxLen;
    }

    int main(){
        vector<int>v;

        v.push_back(0);
        v.push_back(1);
        v.push_back(0);
        v.push_back(0);
        v.push_back(1);
        v.push_back(0);

        int ans = findMaxLength(v);

        cout<<ans;

        return 0;
    }
