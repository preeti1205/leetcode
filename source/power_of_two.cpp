/*

Given an integer, write a function to determine if it is a power of two.

*/

class Solution {
public:
    bool isPowerOfTwo(int n) {

        return ((n>0) && ((n&(n-1))==0));

        /*
        int count = 0;

        if (n < 0)
        {
            return false;
        }

        while(n!= 0 && count < 2)
        {
            int temp = n&(~(n-1));
            if (temp) count++;
            n = n^temp;
        }

        if (count == 1 )
            return true;
        else
            return false;
        */

    }
};
