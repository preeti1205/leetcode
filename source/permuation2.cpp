/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:

[
 [1,1,2],
 [1,2,1],
 [2,1,1]
]
*/

class Solution {
public:
    void perm(vector<int> nums, int start, vector<vector<int>> &result) {
        int n = nums.size();
        if (start == n) {
            result.push_back(nums);
            return;
        }

        for(int i = start; i < n; i++) {
            if( i != start && nums[start] == nums[i]) continue;
            swap(nums[start], nums[i]);
            perm(nums, start + 1, result);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        perm(nums, 0, result);
        return result;
    }
};
