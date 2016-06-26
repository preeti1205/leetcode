/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {


        int size = nums.size();
        int set_size = 1 << size;
        vector<vector<int>> sets(set_size);

        //bit manipulation
        //there will be a total of 2 to the power n subsets.if you write all the numbers from 0 to n-1
        //you can see the pattern of each number in the set
        //eg for 2 element set (11,12) there are 4 sets as follows
        // 11 12
        // 0  0
        // 0  1
        // 1  0
        // 1  1
        for(int i = 0; i <size; i++)
        {
            for(int j = 0; j < set_size ; j++)
            {
                if((j>>i)&1) sets[j].push_back(nums[i]);
            }
        }

        return sets;



    }
};
