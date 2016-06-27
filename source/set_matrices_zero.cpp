/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();
        int k ;

        for( k = 0 ; k < col; k++)
        {
            if (matrix[0][k] ==0)
                {break;}
        }

        for(int i =1; i < row; i++)
        {
            for(int j = 0; j <col; j++ )
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0]=matrix[0][j] = 0;
                }
            }
            cout<<endl;
        }

        for(int i =1; i < row; i++)
        {
            //if we start from j = 0, we will overwrite all values of 0 saved in it
            //and hence, if there is even a single zero, all the column zero elements
            //become 0. Thus the whole matrix becomes 0
            for(int j = col-1; j >= 0; j-- )
            {
                if ((matrix[i][0] == 0) || (matrix[0][j] ==0))
                {
                    matrix[i][j]= 0;
                }
            }
        }

        if(k < col)
        {
            for(int p = 0; p < col ; p++)
            {
                matrix[0][p] = 0;
            }
        }


    }
};
