/*


Find all possible combinations of k numbers that add up to a number n,
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        //vector<int> nums;
        vector<int> temp;
        vector<vector<int>> result;

        //remove the use of extra space
        //we use this knowledge that index 0 has element 1 , indx 1 has 2 and so on
        /*for(int i = 1; i <10; i++)
        {
            nums.push_back(i);
        }

        backtracker(result, nums,temp, k, n,0);
        */

        backtracker(result, temp, k, n,0);

        return result;

    }

    //void backtracker(vector<vector<int>> &res, vector<int> &num, vector<int> &temp, int total, int sum, int indx)
    void backtracker(vector<vector<int>> &res, vector<int> &temp, int total, int sum, int indx)
    {
        if (sum == 0 && total ==0)
        {
            //if(temp.size() == total)
            //
            //{
            res.push_back(temp);
            //}
            return;
        }

        //for(int i = indx; i < 9 && sum>= num[i]; i++)
        //for(int i = indx; i < 9 && sum>= i+1 ; i++)
        //we use this knowledge that index 0 has element 1 , indx 1 has 2 and so on
        for(int i = indx; i < 9 && sum>= i+1 && total > 0; i++)
        {
            //int diff = sum - num[i];
            int diff = sum - (i+1);
            if (diff >= 0)
            {
            temp.push_back(i+1);
            //backtracker(res, num, temp, total, diff, i+1); -> no need for num anymore
            //backtracker(res,temp, total, diff, i+1); ->instead of calculating all solutions and discarding at the end
            //we discard it right here, by reducing total each time we push a new element
            backtracker(res,temp, total-1, diff, i+1);
            temp.pop_back();
            }
        }
    }
};
