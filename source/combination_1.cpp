/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

   All numbers (including target) will be positive integers.
   The solution set must not contain duplicate combinations.

For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:

[
 [7],
 [2, 2, 3]
]

*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int array_size = candidates.size();

        vector<vector<int>> result;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());
        backtracker(result, candidates, temp,target,0, array_size);

        return result;

    }

    void backtracker( vector<vector<int>> &result, vector<int> &candi, vector<int> &temp, int sum,int indx, int size)
    {
        if (sum == 0)
        {
            result.push_back(temp);
            return;
        }

        for(int i = indx;( (i < size) && (candi[i] <= sum)) ; i++)
        {
            int diff = sum - candi[i];
            //no need to go through this, if the difference is negative, as we don't have any
            //negative numbers
            if(diff >= 0)
            {
                temp.push_back(candi[i]);
                //cout<<candi[i];
                backtracker(result, candi, temp, diff, i, size);
                temp.pop_back();
            }

        }


    }
};
