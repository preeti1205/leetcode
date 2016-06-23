/*

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> row(rowIndex+1 , 1);

        //O(n) solution using binomial coeffient nC0 , nC1, nC2...nCn
        // the difference between two consecutive coefficients( eg 5c1 and 5c2 ):
        //ca = (5)/(1) and cb = (5*4)/(1*2) i.e cb = ca*(4/2)

        double coeff=1;

        for(int i =1; i <= (rowIndex/2) ; i++)
        {
            coeff = coeff*(rowIndex+1 - i)/i;
            row[i]= int(coeff);
            row[rowIndex - i]= row[i];

        }

        //O(n*n) solution - takes longer time
        /*
        for(int i = 0; i <= rowIndex ; i++)
        { //its a better idea to start from the end-
        //doesn't interfere with original values we still need
            for(int j =i-1 ; j > 0; j--)
            {
                row[j] = row[j] + row[j-1];
            }

        }
        */
        return row;

    }
};
