/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        int rowcheck[9]={0}, colcheck[9]={0},gridcheck[9]={0} ;

        for(int i = 0; i < row; i++)
        {
            for(int j=0; j < col; j++)
            {
               if(board[i][j] =='.') continue;
               int a = int(board[i][j]);
               int e = 1<<a;
               if (rowcheck[i] & e || colcheck[j] & e || gridcheck[(j/3) + 3*(i/3)] & e) return false;
               rowcheck[i] |= e;
               colcheck[j] |= e;
               gridcheck[(j/3) + 3*(i/3)] |= e;
            }
        }

        return true;

    }
};
