/*

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/
class Solution {
public:
    bool isPowerOfFour(int num) {

        return ( !(num&(num-1)) && (num >0) && (num & 0x55555555)) ;

        /*
        double n = num;
        return ( (*(long*)&n & 0x801FFFFFFFFFFFFF) == 0x0010000000000000 );
        */

        /*
        if ( ( (num&(num-1)) == 0) && (num >0) )
        {
            int k = num- 1;
            int count = 0;

            while(k != 0)
            {
                k = k&(k-1);
                count++;
            }

            if ((count%2) == 0)
            {
                return true;
            }

        }

        return false;
        */
    }
};
