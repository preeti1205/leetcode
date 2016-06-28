/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> hash;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (hash.find(diff) == hash.end())
            {
                hash.insert(make_pair(nums[i],i));
            }
            else
            {
                result.push_back(hash[diff]);
                result.push_back(i);
                return result;
            }
        }

        return result;

    }
};
