/*

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t reverse= 0;
        uint32_t shifter = 1<<31;

        //stops when only zeros are left
        for(int i = 0; n!= 0; i++)
        {
            if(n & 1) { reverse |=(shifter>>i); }
            n >>=1;
        }

        return reverse;

        /*
        uint32_t shifter = 1<<31;  // make sure that shifter is unsigned.Otherwise shifting right will add ones to left
        int mask = 1;

        for(int i = 0; i < 32; i++)
        {
            if(n & mask)
            {
                reverse |= (shifter>>i);
            }
            mask <<= 1;
        }
        return reverse;
        */

    }
};
