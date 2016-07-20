/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {

        int result=0;

        for(int i = 0; i < 31 ; i++)
        {
            int curr = (m>>i);

            for(int j = m+1; (j <= n) && (j > 0) && ((j>>i) >0);j++)
            {
                curr = curr & ((j>>i)&1);
                if (curr == 0)
                {
                    //cout<<i<<":"<<j<<endl;
                    break;
                }
            }
            result |= (curr<<i);
        }
        return result;

    }
};
