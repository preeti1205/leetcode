/*
Given a board with m by n cells, each cell has an initial state live (1) or dead (0).
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

   Any live cell with fewer than two live neighbors dies, as if caused by under-population.
   Any live cell with two or three live neighbors lives on to the next generation.
   Any live cell with more than three live neighbors dies, as if by over-population..
   Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state.

Follow up:

   Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update
   some cells first and then use their updated values to update other cells.
   In this question, we represent the board using a 2D array.
    In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array.
    How would you address these problems?

*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> next;
        int row = board.size();
        int col = board[0].size();

        for(int i =0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
               int sum = findSum(i,j,board, row, col);
               // if sum of all 9 neighbours is 3, then the element is always 1.
               //if sum is 4, the current state is retained. In any other case, the state becomes 0
               if(sum==3)
               {
                   board[i][j] = (board[i][j] == 0 ? 2 :3);
               }
               else if(sum ==4)
               {
                   board[i][j] = (board[i][j]==0 ?0 :3);
               }
               else board[i][j] = (board[i][j] ==0 ? 0 : 1);
            }
        }

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                board[i][j] = board[i][j]>>1;
            }
        }
    }

    int findSum(int a, int b, vector<vector<int>> matrix, int m, int n)
    {
        int count= 0;
        for(int i = a-1; i <=a+1; i++)
        {
            for(int j = b-1; j <= b+1; j++ )
            {
                if(i>=0 && i<m && j>=0 && j<n)
                {
                    count = count + (matrix[i][j] & 1);
                }
            }
        }

        return count;
    }
};
