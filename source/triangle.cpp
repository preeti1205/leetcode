/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        if(triangle.size()==0)
        {
            return 0;
        }

        int row= triangle.size();
        int col = triangle[row-1].size();
        int minima = INT_MAX;

        vector<int> final(col, INT_MAX);
        final[0]= triangle[0][0];

        for(int i = 1; i < row; i++)
        {
            for(int j = i; j >= 0; j-- ) //going from back to front is a lot easier as it
            //doesn't mess up with the values we need for calculation
            {
                if (j==0)
                {
                    final[j] = triangle[i][j] + final[j];
                }
                else if (j==i)
                {
                    final[j] = triangle[i][j] + final[j-1];
                }
                else
                {
                    final[j] = triangle[i][j] + min(final[j], final[j-1] );
                }
            }
        }

        for(int i = 0; i < col; i++)
        {
             minima = min(minima, final[i]);
        }
        return minima;
    }
};
