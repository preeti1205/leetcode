/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

*/

//Note : beter way to use is binary search
//using this here to later track how much my programming logic has improved

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int nums_size = nums.size();

        //nums[-1] = nums[nums_size]= INT_MIN;
        int left = 0;
        int right = nums_size -1;
        int mid = (left + right)/2;


        while((mid >=0) && (mid < nums_size))
        {
            if((nums[mid] > nums[mid-1]) && (nums[mid] > nums[mid +1]))
            { return mid;
            }

            ((nums[mid+1] > nums[mid] )? mid++: mid--);

        }

        //in case it reaches the extreme and we are exiting after adding one(in case of extreme)
        //we reached here coz the peak wasn't in between extremes
        if (mid >=nums_size) return mid-1;
        else
            return mid+1;

    }
};
