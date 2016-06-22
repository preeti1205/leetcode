/*Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> temp;

        if( numRows == 0)
        {
            return temp;
        }

        for(int i = 0; i < numRows ; i++)
        {
            //this is much cooler - we already know there will be 1 at the beginning and end
            vector<int> row(i+1, 1);
            for (int j = 1; j < i; j++)
            {
                //this if statement is making it slower - try adding it before beginning the vector
                /*if(j==0 || j ==i)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back(temp[i-1][j-1] + temp[i-1][j]);
                }
                */
                row[j] = temp[i-1][j-1] + temp[i-1][j];
            }

            temp.push_back(row);
        }

        return temp;

    }
};
