/*Given a sorted array, remove the duplicates in place
such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int nums_size = nums.size();
        int count= 0;

        if (nums_size == 0)
        {
            return 0;
        }

        //two pointer solution - must faster and elegant
        for(int i =1; i < nums_size; i++)
        {
            if (nums[i] != nums[count])
            {
                nums[++count] = nums[i];
            }
        }

        /* My original solution
        while(i< nums_size )
        {
            if (nums[i] == nums[i-1])
            {
                //int temp = nums[i-1];
                nums.erase(nums.begin() + i -1);
                nums.push_back(0);
                nums_size = nums_size -1 ;
            }
            else
            {
                i++;
            }
            cout<<nums_size<<endl;
        }

        return nums_size;
        */

        return (count +1);

    }
};
