/*
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
 It doesn't matter what you leave beyond the new length.

 */

 class Solution {
public:
    int removeDuplicates(vector<int>& nums) {


        int nums_size = nums.size();
        //if (nums_size == 0) return 0;
        int k =0;

        for(int i =0; i < nums_size ; i++)
        {
            // not nums[i] > nums[i-2] but nums[i] > nums[k-2] as nums[i] will be overwritten as we encounter more than 2 same elements, but k-2 will still be the same (as k is not growing until 2 dup check is true)

            //cout<<" i and k respectively :"<< i <<" "<<k<<endl;
            if ((k < 2) || (nums[i] > nums[k-2])) nums[k++] = nums[i];
        }

        return k;





        /*

        //int last = 2;
        if (nums_size == 0) return 0;

        if(nums_size == 1 || nums_size ==2)
        {
            return nums_size;
        }

        //int count= 1;
        for(int i = 2; i < nums_size; i++)
        {
            if (nums[i] != nums[last -2]) nums[last++] = nums[i];
            //if (nums[i] != nums[count-1]) nums[++count] = nums[i];
        }

        return count+1;

        */

        //counter method - slower and more lines of code
        /*
        if (nums_size == 0) return 0;
        int count = 0;
        int check_two = 1;

        for(int i = 1; i < nums_size; i++)
        {
            if (nums[i] != nums[count])
            {
                nums[++count]= nums[i];
                check_two = 1;
            }
            else if (check_two)
            {
                nums[++count]= nums[i];
                check_two=0;
            }
        }
        return count+1;
        */


    }
};
