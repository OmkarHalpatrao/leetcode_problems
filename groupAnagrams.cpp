// Given an array of strings strs, group the  anagrams together. You can return the answer in any order.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        for(auto it : strs){
            string temp = it;
            sort(it.begin(),it.end()); //sorting the string to get key to make grp
            mp[it].push_back(temp);    // sorts string according to grp key and new key then create new grp
        }

        vector<vector<string>>ans;

        for (auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
        
    }
};