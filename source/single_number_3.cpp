/*
Given an array of numbers nums, in which exactly two elements appear only once
and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:

   The order of the result is not important. So in the above example, [5, 3] is also correct.
   Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int result=0;
        int a=0,b=0;
        //vector<int> final;

        for(int i = 0; i < nums.size(); i++)
        {
            //result will only be the xor of two different numbers
            result = result^nums[i];
        }

        //the bit where the two numbers have there first different bit (opposite: 1 and 0)
        int diff_bit = result&(-result);

        for(int i = 0; i <nums.size() ; i++)
        {
            //if that bit is set to 1: ANDing masks the other bits
            if( (nums[i]&diff_bit) == diff_bit)
            {
                a = a^nums[i];
            }
            /*
            else
                b = b^nums[i];
            */
        }
        //reducing the calculations and number of lines by eliminating these lines
        /*
        final.push_back(a);
        final.push_back(b);

        return final;
        */
        return {a,result^a};
    }
};

/*
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2);
        int x, y;
        int n = nums.size(), i;
        int xXORy = 0;
        for(i=0; i<n; i++)
            xXORy = xXORy^nums[i];

        int lowBit = 1;
        while((lowBit&xXORy) != lowBit)
        {
            lowBit = lowBit << 1;
        }

        x = 0;
        for(i=0; i<n; i++)
        {
            if(lowBit&nums[i])
                x = x^nums[i];
        }

        y = xXORy ^ x;

        result[0] = x;
        result[1] = y;
        return result;
    }
};

*/
