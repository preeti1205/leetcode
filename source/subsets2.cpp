/*

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
]

*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> set;
        set.push_back(temp);
        backtracker(nums, temp, set,0);
        return set;
    }

    void backtracker( vector<int> &nums, vector<int> &temp, vector<vector<int>> &set, int indx)
    {
        //this is not needed as the next look will take care if indx exceeds the bounds
         /*if (indx == nums.size() )
         {
             return;
         }*/

        for(int i = indx; i < nums.size(); i++)
        {
            if( ((i > indx) && (nums[i] != nums[i-1])) || (i == indx) )
            {
            temp.push_back(nums[i]);
            set.push_back(temp);
            backtracker(nums, temp, set, i+1);
            temp.pop_back();
            }
        }
    }
};
