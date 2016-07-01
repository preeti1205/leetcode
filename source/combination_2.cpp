/*

Given a collection of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

   All numbers (including target) will be positive integers.
   The solution set must not contain duplicate combinations.

For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:

[
 [1, 7],
 [1, 2, 5],
 [2, 6],
 [1, 1, 6]
]

*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());

        backtracker (result, candidates, temp , target, 0);

        return result;
    }

    void backtracker( vector<vector<int>> &res, vector<int> &candi, vector<int> &temp, int sum, int indx)
    {
        if (sum == 0)
        {
            res.push_back(temp);
            return;
        }

        for(int i = indx; (i < candi.size()) && (sum >= candi[i]); i++)
        {
            if ((i > indx) && (candi[i]== candi[i-1]))
            {
                continue;
            }
            int diff = sum - candi[i];
            temp.push_back(candi[i]);
            backtracker(res, candi, temp, diff, i+1);
            temp.pop_back();
        }

        return;

    }
};
