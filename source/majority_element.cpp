/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int nums_size = sizeof(int)*8 , size = nums.size();
        int mask = 1;
        int result = 0;

        //O(32*n) complexity
        for(int i = 0; i < nums_size; i++)
        {
            int count = 0;

            for(int j = 0; j < size; j++)
            {
                if(mask & nums[j]) count++;
            }

            if(count > size/2)
            {
                result |= mask;
            }

            mask <<=1;
        }

        return result;

        //Voting algo solution - O(n) complexity-faster
        /*
        int result =0;
        int count = 0;

        for(int i = 0;i < nums.size(); i++)
        {
            if(count == 0)
            {
                result = nums[i];
                count++;
            }
            else if(nums[i]==result)
            {
                count++ ;
            }
            else
                count--;
        }

        return result;
        */

    }
};
