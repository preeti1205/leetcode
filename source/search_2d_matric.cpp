/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

Return true if element exists
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        if ((target < matrix[0][0]) || (target > matrix[row-1][col-1])) return false;

        int left = 0;
        int right = row*col -1;
        int mid;

        while(left <= right)
        {
            mid = (left + right)/2;
            int i= mid/col;
            int j= mid%col;

            if(matrix[i][j] == target) return true;

            ((matrix[i][j] > target ) ? (right = mid -1) : (left = mid+1) );

        }

        return false;


        /*

        //The worst case complexity for both of these algos is the same
        //but the first one is a smarter way

        int left= 0;
        int col_left = 0;
        int right = row -1;
        int col_right = col-1;
        int mid;
        int col_mid;

    if ((target < matrix[0][0]) || (target > matrix[row-1][col-1])) return false;

    while(left <= right )
    {
        mid = (left + right)/2;
        if (matrix[mid][0] == target) return true;

        ((matrix[mid][0] > target ) ? (right = mid -1) : (left = mid+1) );

    }

    //since the algo can loop one step ahead while looking for the element
    if (matrix[mid][0] > target)  mid = mid -1;

    while(col_left <= col_right)
    {
        col_mid = (col_left + col_right)/2;

        if (matrix[mid][col_mid] == target)
        {
            return true;
        }
        else
            ((matrix[mid][col_mid] > target ) ? (col_right = col_mid -1) : (col_left = col_mid+1) );
    }


    return false;*/

    }
};
