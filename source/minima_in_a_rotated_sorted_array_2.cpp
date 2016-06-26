/*

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.



    Follow up for "Find Minimum in Rotated Sorted Array":
    What if duplicates are allowed?

    Would this affect the run-time complexity? How and why?
*/

class Solution {
public:
    int findMin(vector<int>& nums) {


        int left = 0;
        int right = nums.size() -1;
        int mid=0 ;

        if (right == 0)
        {
            return nums[0];
        }

        //worst case - O(n) coz of duplicates
        //otherwise its nlogn
        while(left <= right)
        {
            mid = (left + right)/2;
            if (nums[mid] == nums[right])
            {
                right = right -1;
            }
            else
            (nums[right]>nums[mid] ?(nums[left] < nums[mid] ?(right = mid-1 ):right=mid) :(left = mid+1 ));
        }

        return nums[mid];


        //O(n) solution
        /*

        int minima = nums[0];

        for(int i =1; i < nums.size() ; i++)
        {
            if (nums[i] < nums[i-1])
            {
                minima = nums[i];
                break;
            }
        }

        return minima;
        */

    }
};
