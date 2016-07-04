/*

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int nums_size = nums.size();
        k = k%nums_size;

        //solution using reverse
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

        //pushing the desired digits to the back i.e. index 0 to nums-k-1
        //as for rotating the array by k, k digits will be pushed out from the back to front
        // or in other words nums-k digits will be moved from front and
        //pushed in from the back (last index nums-k-1)
        /*
        if (nums_size == 0)
        {
            return;
        }
        int counter= 0;

        k = k%nums_size;

        if (k == 0 )
        {
            return;
        }

        for(int i= 0; i < (nums_size - k); i++)
        {
            int temp = nums[0];
            nums.erase(nums.begin());
            nums.push_back(temp);
        }

        */
    }
};
