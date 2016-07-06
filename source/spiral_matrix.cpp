/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5].

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> result;
        int row = matrix.size();

        if (row == 0)
        {
            return result;
        }


        int col = matrix[0].size();
        int total = row*col;
        int count = 0;

        int i, j;

        for (int start = 0, i=0, j=0; i <= (row/2); start++, i++, j++ )
        {
            if ((row == col) && (row%2 !=0) && (start==(row/2)) )
            {
            result.push_back(matrix[i][j]);
            }

            for( ; j < (col-1-start) && count< total; j++)
            {
                result.push_back(matrix[i][j]);
                count++;
            }

            for(; i< (row-1-start) && count < total; i++)
            {
                result.push_back(matrix[i][j]);
                count++;
            }

            for( ; j>start && count < total; j--)
            {
                result.push_back(matrix[i][j]);
                count++;
            }

            cout<<endl;

            for(;i>start && count < total;i--)
            {
                result.push_back(matrix[i][j]);
                count++ ;
            }
        }

        return result;

    }
};
