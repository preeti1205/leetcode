/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:

[
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
]
*/
class Solution {
public:
    void perm(vector<vector<int> > &result, int start, vector<int> &nums) {
        int n = nums.size();
       if (start == n) {
           result.push_back(nums);
           return;
       }

       for(int i = start; i < n; i++) {
           swap(nums[start], nums[i]);
           perm(result, start + 1, nums);
           swap(nums[start], nums[i]);   // not needed if we pass nums by value as original array will stay the same in pass by value
       }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        perm(result, 0, nums);
        return result;
    }
};
